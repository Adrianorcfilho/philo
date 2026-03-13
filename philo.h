/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:05:21 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/13 20:40:48 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_philo t_philo;

typedef struct s_table
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}					t_table;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				left_fork;
	int				right_fork;
	long			last_meal;
	int			meals_eaten;
	t_table			*table;
}					t_philo;

int					ft_atoi(const char *str);
int					ft_isnum(int c);
int					parsing(int ac, char *av[]);

#endif
