/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:48:32 by adenord           #+#    #+#             */
/*   Updated: 2023/12/19 15:25:23 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>
# include <string.h>
# include <semaphore.h>
# include <errno.h>
# include <signal.h>

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

struct s_philo
{
	int				id;
	pid_t			pid;
	int				number_meals;
	long			last_meal;
	bool			is_full;
	t_data			*datas;
	pthread_t		thread_id;
};

struct s_data
{
	int				number_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				number_cycles;
	long			simulation_start;
	t_philo			*philos;
	sem_t			*forks;
	sem_t			*write;
	sem_t			*stop;
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

typedef enum e_mtx_code
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY
}	t_mtx_code;

typedef enum e_thread_code
{
	CREATE,
	JOIN,
	DETACH
}	t_thread_code;

typedef enum e_sema_code
{
	CLOSE,
	POST,
	WAIT,
	UNLINK
}	t_sema_code;

//check_format
int		check_format(int argc, char **argv);

//data_init
int		data_init(t_data *datas, int argc, char **argv);

//hungries
int		hungries(t_data *datas);

//routines
void	dinner_routine(t_philo *philo);

//write
void	write_state(t_philo_state state, t_philo *philo);

//custom_sleep
void	custom_sleep(long wait_time);

//ft_atol
long	ft_atol(const char *str);

//gettime
long	gettime(t_time_code code);

//cleaners
void	error_exit(char *e_str);

//safe_thread
void	safe_thread(t_thread_code code, t_data *datas, \
	void *(*f)(void *), void *arg);

//safe_sema
void	safe_sema(t_sema_code code, void *sem, t_data *data);
sem_t	*safe_sema_open(char *name, t_data *datas, mode_t perm, \
		unsigned int value);

#endif
