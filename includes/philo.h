/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:05:21 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/17 18:59:06 by adrocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define HERE printf("HERE\n")

typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

struct					s_table
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat_count;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	long				start_time;
};

struct					s_philo
{
	int					id;
	pthread_t			thread;
	int					left_fork;
	int					right_fork;
	long				last_meal;
	int					meals_eaten;
	t_table				*table;
};

int						ft_atoi(const char *str);
int						ft_isnum(int c);
int						parsing(int ac, char *av[]);
void					init_table(t_table *table, char *av[]);
void					init_philos(t_table *table);
void					init_forks(t_table *table);
void					philo_routine(t_philo *philo);
long					get_time(void);
long					timestamp(long time);
void					philo_thinking(t_philo *philo);
void					philo_lock_forks(t_philo *philo);
void					philo_eating(t_philo *philo);
void					philo_unlock_forks(t_philo *philo);
void					philo_sleeps(t_philo *philo);
void					philo_routine(t_philo *philo);
void					creat_new_thread(t_table *table);

#endif
