/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:19:24 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/17 18:38:56 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
	usleep(table->time_to_eat  *1000);
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
	t_table	*table;

	table = philo->table;
	printf("%ld %d is sleeping\n", timestamp(table->start_time), philo->id);
	usleep(table->time_to_sleep * 1000);
}

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

int	main(int ac, char *av[])
{
	static t_table	table;

	table.start_time = get_time();
	printf("%p\n", &table);
	if (!parsing(ac, av))
	{
		printf("Error:\n");
		return (1);
	}
	init_table(&table, av);
	init_philos(&table);
	init_forks(&table);
	creat_new_thread(&table);
	sleep(2);
	// printf("Aqui estao os valores guardados do parsing na Struct table:\n%i\n
	// 	%i\n %i\n %i\n ", table.num_of_philo, table.time_to_die,
	// 	table.time_to_eat, table.time_to_sleep);
	return (0);
}
