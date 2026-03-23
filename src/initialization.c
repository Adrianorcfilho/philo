/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 13:50:07 by adrocha           #+#    #+#             */
/*   Updated: 2026/03/23 21:41:40 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_table(t_table *table, char *av[])
{
	table->simulation_end = 0;
	table->num_of_philo = atoi(av[1]);
	table->time_to_die = atoi(av[2]);
	table->time_to_eat = atoi(av[3]);
	table->time_to_sleep = atoi(av[4]);
	// table->must_eat_count = mec;
	table->philos = malloc((table->num_of_philo) * sizeof(t_philo));
	if (!table->philos)
		return ;
	table->forks = malloc((table->num_of_philo) * sizeof(pthread_mutex_t));
	if (!table->forks)
	{
		free(table->philos);
		return ;
	}
	return ;
}

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].left_fork = i;
		table->philos[i].right_fork = ((i + 1) % table->num_of_philo);
		table->philos[i].table = table;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal = 0;
		i++;
	}
	return ;
}

void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	init_mutex(t_table *table)
{
	pthread_mutex_init(&table->write_mutex, NULL);
	pthread_mutex_init(&table->mutex_meal, NULL);
	pthread_mutex_init(&table->mutex_end, NULL);
}

