/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:16:30 by adrocha-          #+#    #+#             */
/*   Updated: 2026/04/03 20:39:46 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parsing(int ac, char *av[])
{
	int	i;
	int	c;
	int	j;

	if (ac < 5 || ac > 6)
		return (0);
	if (ac == 6 && (av[5][0] == '0' || (av[5][0] == '+' && av[5][1] == '0')))
		return (1);
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '+' && j == 0)
				j++;
			if (!ft_isnum(av[i][j]))
				return (0);
			j++;
		}
		c = ft_atoi(av[i]);
		if (c <= 0)
			return (0);
	}
	return (1);
}
