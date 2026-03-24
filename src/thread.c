/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:56:41 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/24 23:37:21 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	set_end(t_table *table, int i)
{
	t_philo	*philo;

	philo = &table->philos[i];
	pthread_mutex_lock(&table->mutex_end);
	table->simulation_end = 1;
	pthread_mutex_lock(&table->write_mutex);
	printf("%ld %d died\n", timestamp(table->start_time), philo->id);
	pthread_mutex_unlock(&table->write_mutex);
	pthread_mutex_unlock(&table->mutex_end);
	return ;
}

void	*watcher_routine(void *arg)
{
	t_table	*table;
	int		i;
	long	last_meal_time;

	table = (t_table *)arg;
	while (!check_simulation_end(table))
	{
		i = -1;
		while (++i < table->num_of_philo)
		{
			last_meal_time = get_last_meal(table, i);
			if ((timestamp(table->start_time)
					- last_meal_time) >= table->time_to_die)
			{
				set_end(table, i);
				return (NULL);
			}
		}
		if (table->must_eat_count > 0 && check_all_ate(table))
			return (last_check(table), NULL);
		usleep(100);
	}
	return (NULL);
}

void	sleep_or_wait(t_philo *philo, long duration_ms)
{
	long	start;

	start = get_time();
	while (!philo->table->simulation_end && (get_time() - start < duration_ms))
		usleep(100);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->table->simulation_end)
	{
		if (philo->id % 2 == 0)
			usleep(100);
		philo_thinking(philo);
		philo_lock_forks(philo);
		philo_eating(philo);
		philo_unlock_forks(philo);
		philo_sleeps(philo);
		sleep_or_wait(philo, philo->table->time_to_sleep);
	}
	return (NULL);
}

void	creat_new_thread(t_table *table)
{
	int			i;
	pthread_t	watcher_thread;

	i = 0;
	pthread_create(&watcher_thread, NULL, watcher_routine, table);
	while (i < table->num_of_philo)
	{
		pthread_create(&table->philos[i].thread, NULL, philo_routine,
			&table->philos[i]);
		i++;
	}
	i = 0;
	while (i < table->num_of_philo)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	pthread_join(watcher_thread, NULL);
}
