/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:05:21 by adrocha-          #+#    #+#             */
/*   Updated: 2026/03/31 23:25:44 by adrocha-         ###   ########.fr       */
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
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		mutex_meal;
	pthread_mutex_t		mutex_end;
	long				start_time;
	int					simulation_end;
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
int						ft_strcmp(const char *s1, const char *s2);
int						parsing(int ac, char *av[]);
void					init_table(t_table *table, char *av[]);
void					init_philos(t_table *table);
void					init_forks(t_table *table);
void					init_mutex(t_table *table);
long					get_time(void);
long					timestamp(long time);
void					philo_thinking(t_philo *philo);
void					philo_lock_forks(t_philo *philo);
void					philo_eating(t_philo *philo);
void					philo_unlock_forks(t_philo *philo);
void					philo_sleeps(t_philo *philo);
void					*watcher_routine(void *arg);
void					*philo_routine(void *arg);
void					creat_new_thread(t_table *table);
void					sleep_or_wait(t_philo *philo, long duration_ms);
void					safe_printf(t_philo *philo, char *msg);
int						check_simulation_end(t_table *table);
long					get_last_meal(t_table *table, int i);
void					last_check(t_table *table);
int						check_all_ate(t_table *table);
void					destroy_forks(t_table *table);
void					destroy_global_mutexes(t_table *table);
void					free_memory(t_table *table);
void					cleanup(t_table *table);
void					take_forks_order(t_philo *philo,
							pthread_mutex_t **fork1, pthread_mutex_t **fork2);

#endif
