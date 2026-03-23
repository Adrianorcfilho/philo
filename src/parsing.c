/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:16:30 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/23 23:07:43 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	allisnum(int c)
{
	return (c >= '0' && c <= '9');
}

int	parsing(int ac, char *av[])
{
	int	i;
	int	c;
	int	j;

	if (ac < 5 || ac > 6)
		return (0);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' && j == 0)
				j++;
			if(!allisnum(av[i][j]))
				return (0);
			j++;
		}
		c = ft_atoi(av[i]);
		if (c <= 0)
			return (0);
		i++;
	}
	return (1);
}
