/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:19:24 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/23 22:47:47 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char *av[])
{
	static t_table	table;

	if (ac == 6 && !ft_strcmp(av[5], "0"))
		return (0);
	table.start_time = get_time();
	if (!parsing(ac, av))
	{
		printf("Error:\n");
		return (0);
	}
	init_table(&table, av);
	init_philos(&table);
	init_forks(&table);
	init_mutex(&table);
	creat_new_thread(&table);
	sleep(2);
	return (1);
}
