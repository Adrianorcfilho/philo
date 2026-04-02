/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:55:28 by adrocha-          #+#    #+#             */
/*   Updated: 2026/04/02 20:14:30 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	t_table			*table;
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	table = philo->table;
	if (check_simulation_end(table))
		return ;
	take_forks_order(philo, &first, &second);
	philo->has_forks = 0;
	pthread_mutex_lock(first);
	safe_printf(philo, "has taken a fork");
	if (check_simulation_end(table))
	{
		pthread_mutex_unlock(first);
		return ;
	}
	pthread_mutex_lock(second);
	safe_printf(philo, "has taken a fork");
	philo->has_forks = 1;
}

void	philo_eating(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->mutex_meal);
	philo->last_meal = timestamp(table->start_time);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&table->mutex_meal);
	if (check_simulation_end(table))
		return ;
	safe_printf(philo, "is eating");
	sleep_or_wait(philo, table->time_to_eat);
}

void	philo_unlock_forks(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->has_forks)
	{
		take_forks_order(philo, &first, &second);
		pthread_mutex_unlock(second);
		pthread_mutex_unlock(first);
		philo->has_forks = 0;
	}
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
