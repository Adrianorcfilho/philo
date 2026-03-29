/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:29:18 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/29 17:30:23 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_forks(t_table *table)
{
	int	i;

	i = 0;
	if (!table->forks)
		return ;
	while (i < table->num_of_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	return ;
}

void	destroy_global_mutexes(t_table *table)
{
	pthread_mutex_destroy(&table->write_mutex);
	pthread_mutex_destroy(&table->mutex_end);
	pthread_mutex_destroy(&table->mutex_meal);
	return ;
}

void	free_memory(t_table *table)
{
	if (table->philos)
	{
		free(table->philos);
		table->philos = NULL;
	}
	if (table->forks)
	{
		free(table->forks);
		table->forks = NULL;
	}
}

void	cleanup(t_table *table)
{
	destroy_forks(table);
	destroy_global_mutexes(table);
	free_memory(table);
	return ;
}

void	take_forks_order(t_philo *philo, pthread_mutex_t **fork1,
		pthread_mutex_t **fork2)
{
	t_table	*table;

	table = philo->table;
	if (&table->forks[philo->left_fork] < &table->forks[philo->right_fork])
	{
		*fork1 = &table->forks[philo->left_fork];
		*fork2 = &table->forks[philo->right_fork];
	}
	else
	{
		*fork1 = &table->forks[philo->right_fork];
		*fork2 = &table->forks[philo->left_fork];
	}
	return ;
}
