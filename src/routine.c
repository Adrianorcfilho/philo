/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:55:28 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/23 22:08:59 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_simulation_end(t_table *table)
{
	pthread_mutex_lock(&table->mutex_end);
	if (table->simulation_end)
	{
		pthread_mutex_unlock(&table->mutex_end);
		return (1);
	}
	pthread_mutex_unlock(&table->mutex_end);
	return (0);
}

void	safe_printf(t_philo *philo, char *msg)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->write_mutex);
	if (check_simulation_end(table))
	{
		pthread_mutex_unlock(&table->write_mutex);
		return ;
	}
	printf("%ld %d %s\n", timestamp(table->start_time), philo->id, msg);
	pthread_mutex_unlock(&table->write_mutex);
	return ;
}

void	philo_thinking(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (check_simulation_end(table))
		return ;
	safe_printf(philo, "is thinking");
}

void	philo_lock_forks(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (check_simulation_end(table))
		return ;
	pthread_mutex_lock(&table->forks[philo->left_fork]);
	safe_printf(philo, "has taken a fork");
	if (philo->left_fork != philo->right_fork)
	{
		if (check_simulation_end(table))
		{
			pthread_mutex_unlock(&table->forks[philo->left_fork]);
			return ;
		}
		pthread_mutex_lock(&table->forks[philo->right_fork]);
		safe_printf(philo, "has taken a fork");
	}
}

void	philo_eating(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->mutex_meal);
	philo->last_meal = timestamp(table->start_time);
	pthread_mutex_unlock(&table->mutex_meal);
	philo->meals_eaten += 1;
	if (check_simulation_end(table))
		return ;
	safe_printf(philo, "is eating");
	sleep_or_wait(philo, table->time_to_eat);
}

void	philo_unlock_forks(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_unlock(&table->forks[philo->left_fork]);
	pthread_mutex_unlock(&table->forks[philo->right_fork]);
}

void	philo_sleeps(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if (check_simulation_end(table))
		return ;
	safe_printf(philo, "is sleeping");
	sleep_or_wait(philo, table->time_to_sleep);
}
