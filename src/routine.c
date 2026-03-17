/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:55:28 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/17 19:04:32 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_thinking(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	printf("%d\n", philo->id);
	printf("%ld %d is thinking\n", timestamp(table->start_time), philo->id);
}

void	philo_lock_forks(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->forks[philo->left_fork]);
	printf("%ld %d has taken a fork\n", timestamp(table->start_time),
		philo->id);
	pthread_mutex_lock(&table->forks[philo->right_fork]);
	printf("%ld %d has taken a fork\n", timestamp(table->start_time),
		philo->id);
}

void	philo_eating(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	philo->last_meal = timestamp(table->start_time);
	philo->meals_eaten += 1;
	usleep(table->time_to_eat * 1000);
	printf("%ld %d is eating\n", timestamp(table->start_time), philo->id);
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
	t_table *table;

	table = philo->table;
	printf("%ld %d is sleeping\n", timestamp(table->start_time), philo->id);
	usleep(table->time_to_sleep * 1000);
}
