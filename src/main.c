/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:19:24 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/21 21:15:19 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char *av[])
{
	static t_table	table;

	table.start_time = get_time();
	if (!parsing(ac, av))
	{
		printf("Error:\n");
		return (1);
	}
	init_table(&table, av);
	init_philos(&table);
	init_forks(&table);
	init_mutex(&table);
	creat_new_thread(&table);
	sleep(2);
	return (0);
}
