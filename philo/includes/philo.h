/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:48:32 by adenord           #+#    #+#             */
/*   Updated: 2023/12/12 14:40:13 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>
# include <string.h>

/*
* RESET
* RED
* GREEN
* YELLOW
* MAGENTA
* CYAN
* BOLD
*/
# define RST    "\033[0m"
# define RED	"\033[1;31m"
# define G      "\033[1;32m"
# define Y      "\033[1;33m"
# define M      "\033[1;35m"
# define C      "\033[1;36m"
# define B		"\033[1m"

typedef struct timeval	t_time;

typedef struct s_data	t_data;

typedef struct s_philo	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	mtx;
	int				id;
}	t_fork;

struct s_philo
{
	int				id;
	int				number_meals;
	long			last_meal;
	bool			is_full;
	t_fork			*first;
	t_fork			*second;
	pthread_t		thread_id;
	t_data			*datas;
	pthread_mutex_t	philo_mtx;
};

struct s_data
{
	int				number_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				number_cycles;
	long			simulation_start;
	bool			end_of_simulation;
	bool			everybody_ready;
	pthread_t		checker;
	pthread_mutex_t	table_mtx;
	pthread_mutex_t	write_mtx;
	t_fork			*forks;
	t_philo			*philos;
};

typedef enum e_time_code
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS
}	t_time_code;

typedef enum e_philo_state
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED
}	t_philo_state;

//check_format
int		check_format(int argc, char **argv);

//data_init
int		data_init(t_data *datas, int argc, char **argv);

//hungries
int		hungries(t_data *datas);

//routines
void	*checker_routine(void *data);
void	*philo_alone(void *data);
void	*dinner_routine(void *data);
void	thinking_routine(t_philo *philo, bool simulation_started);

//write
void	write_state(t_philo_state state, t_philo *philo);

//utils
void	wait_every_philos(t_data *datas);
void	force_odd_to_think(t_philo *philo);
bool	death(t_philo *philo);

//access
bool	get_bool(pthread_mutex_t *mtx, bool *toget);
void	set_bool(pthread_mutex_t *mtx, bool *toset, bool value);
long	get_long(pthread_mutex_t *mtx, long *toget);
void	set_long(pthread_mutex_t *mtx, long *toset, long value);
bool	simulation_finished(t_data *datas);

//custom_sleep
void	custom_sleep(long wait_time, t_data *datas);

//ft_atol
long	ft_atol(const char *str);

//gettime
long	gettime(t_time_code code);

//cleaners
void	clean_mess(t_data *datas, int last);
void	wash_it(t_data *datas, int last);

#endif
