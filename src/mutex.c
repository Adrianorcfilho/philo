/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:11:56 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/24 23:37:38 by adrocha-         ###   ########.fr       */
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

long	get_last_meal(t_table *table, int i)
{
	long	last_meal_time;

	pthread_mutex_lock(&table->mutex_meal);
	last_meal_time = table->philos[i].last_meal;
	pthread_mutex_unlock(&table->mutex_meal);
	return (last_meal_time);
}

int	check_all_ate(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		pthread_mutex_lock(&table->mutex_meal);
		if (table->philos[i].meals_eaten < table->must_eat_count)
		{
			pthread_mutex_unlock(&table->mutex_meal);
			return (0);
		}
		pthread_mutex_unlock(&table->mutex_meal);
		i++;
	}
	return (1);
}

void	last_check(t_table *table)
{
	pthread_mutex_lock(&table->mutex_end);
	table->simulation_end = 1;
	pthread_mutex_unlock(&table->mutex_end);
	return ;
}
