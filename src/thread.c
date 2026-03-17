/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:56:41 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/17 19:04:08 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_routine(t_philo *philo)
{
	int	i;

	// t_table const *table = philo->table;
	i = 0;
	while (1)
	{
		// if (table->must_eat_count)
		// {
		// 	// adicionar condicao para quando tenho eat_count
		// }
		// if (philo->id % 2 == 0)
		// 	usleep(100);
		philo_thinking(philo);
		philo_lock_forks(philo);
		philo_eating(philo);
		philo_unlock_forks(philo);
		philo_sleeps(philo);
	}
}

void	creat_new_thread(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_of_philo)
	{
		pthread_create(&table->philos[i].thread, NULL, (void *)philo_routine,
			&table->philos[i]);
		i++;
	}
	i = 0;
	while (i < table->num_of_philo)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}
