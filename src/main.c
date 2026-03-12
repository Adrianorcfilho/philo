/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:19:24 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/12 20:39:58 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// int	ft_atoi(const char *str)
// {
// 	int	i;
// 	int	number;
// 	int	sign;

// 	sign = 1;
// 	number = 0;
// 	i = 0;
// 	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign = -sign;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		number *= 10;
// 		number += str[i] - '0';
// 		i++;
// 	}
// 	return (number * sign);
// }

// int	ft_isnum(int c)
// {
// 	return (c >= '0' && c <= '9');
// }

// int	parsing(int ac, char *av[])
// {
// 	int	i;
// 	int	c;
// 	int	j;

// 	if (ac < 5 || ac > 6)
// 		return (0);
// 	i = 1;
// 	while (i < ac)
// 	{
// 		j = 0;
// 		while (av[i][j])
// 		{
// 			if (!ft_isnum(av[i][j]))
// 				return (0);
// 			j++;
// 		}
// 		c = ft_atoi(av[i]);
// 		if (c <= 0)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

int	main(int ac, char *av[])
{
	static t_table	c;

	if (!parsing(ac, av))
	{
		printf("Error:\n");
		return (1);
	}
	printf("input valido\n");
	c.num_of_philo = atoi(av[1]);
	c.time_to_die = atoi(av[2]);
	c.time_to_eat = atoi(av[3]);
	c.time_to_sleep = atoi(av[4]);
	// c.must_eat_count = mec;
	printf("Esse é o numero de filosofos na mesa:%i\n", c.num_of_philo);
	printf("Hora de morrer:%i\n", c.time_to_die);
	printf("Hora de comer:%i\n", c.time_to_eat);
	printf("Hora de dormir:%i\n", c.time_to_sleep);
	return (0);
}
