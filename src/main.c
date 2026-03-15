/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:19:24 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/15 13:03:25 by adrocha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_table(t_table *table, char *av[])
{
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

void init_philos(t_table *table)
{
	
	int i = 0;

	while(i < table->num_of_philo)
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

int	main(int ac, char *av[])
{
	static t_table	table;

	if (!parsing(ac, av))
	{
		printf("Error:\n");
		return (1);
	}
	init_table(&table, av);
	init_philos(&table);
	return (0);
}
