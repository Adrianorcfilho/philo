/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha <adrocha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:19:24 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/15 13:55:18 by adrocha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"



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
	init_forks(&table);
	printf("Aqui estao os valores guardados do parsing na Struct table:\n %i\n %i\n %i\n %i\n ", table.num_of_philo, table.time_to_die, table.time_to_eat, table.time_to_sleep);
	return (0);
}
