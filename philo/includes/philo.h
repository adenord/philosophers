/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:48:32 by adenord           #+#    #+#             */
/*   Updated: 2023/12/05 17:37:43 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdbool.h>

typedef struct timeval	t_time;

typedef struct s_fork
{
	pthread_mutex_t	mtx;
	int				id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			number_meals;
	long		last_meal;
	bool		is_full;
	t_fork		right;
	t_fork		left;
	pthread_t	thread_id;
}	t_philo;

typedef struct s_data
{
	int		number_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		number_cycles;
	long	simulation_start;
	bool	end_of_simulation;
	t_fork	*forks;
	t_philo	*philos;
}	t_data;

void	custom_sleep(long wait_time);
int		parser(int argc, char **argv);
long	ft_atol(const char *str);
int		data_init(t_data *datas, int argc, char **argv);
void	clean_mess(t_data *datas, int last);

#endif
