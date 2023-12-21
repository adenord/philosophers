/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:07 by adenord           #+#    #+#             */
/*   Updated: 2023/12/21 12:40:17 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	*checker_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		usleep(100);
		if (gettime(MILLISECONDS) - philo->last_meal > \
			(philo->datas->time_to_die / 1e3))
		{
			safe_sema(WAIT, philo->datas->stop, philo->datas);
			write_state(DIED, philo);
			exit(1);
		}
	}
	return (NULL);
}

static void	eat_routine(t_philo *philo)
{
	safe_sema(WAIT, philo->datas->forks, philo->datas);
	write_state(TAKE_FIRST_FORK, philo);
	safe_sema(WAIT, philo->datas->forks, philo->datas);
	write_state(TAKE_SECOND_FORK, philo);
	write_state(EATING, philo);
	philo->last_meal = gettime(MILLISECONDS);
	philo->number_meals++;
	custom_sleep(philo->datas->time_to_eat);
	safe_sema(POST, philo->datas->forks, philo->datas);
	safe_sema(POST, philo->datas->forks, philo->datas);
	if (philo->number_meals == philo->datas->number_cycles)
		philo->is_full = true;
}


static void	thinking_routine(t_philo *philo)
{
	long	t_think;

	if (philo->datas->number_philo % 2 != 0)
	{
		t_think = (philo->datas->time_to_eat * 2) - philo->datas->time_to_sleep;
		if (t_think < 0)
			t_think = 0;
		custom_sleep(t_think >> 1);
	}
}

void	dinner_routine(t_philo *philo)
{
	philo->last_meal = philo->datas->simulation_start;
	safe_thread(CREATE, philo->datas, (*checker_routine), philo);
	if (philo->id % 2 == 0)
		custom_sleep(philo->datas->time_to_eat - 50);
	while (true)
	{
		safe_sema(WAIT, philo->datas->stop, philo->datas);
		safe_sema(POST, philo->datas->stop, philo->datas);
		eat_routine(philo);
		write_state(SLEEPING, philo);
		custom_sleep(philo->datas->time_to_sleep);
		if ((philo->datas->number_philo % 2 && philo->datas->time_to_sleep \
		== philo->datas->time_to_eat) || (philo->datas->time_to_eat > \
		philo->datas->time_to_sleep))
			thinking_routine(philo);
		if (philo->is_full)
			break ;
	}
	safe_thread(JOIN, philo->datas, NULL, NULL);
	exit(1);
}
