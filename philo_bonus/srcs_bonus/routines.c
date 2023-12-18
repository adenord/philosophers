/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:07 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 17:20:24 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*checker_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	custom_sleep(1000);
	while (!philo->is_dead)
	{
		if (gettime(MILLISECONDS) - philo->last_meal > (philo->datas->time_to_die / 1000))
		{
			write_state(DIED, philo);
			exit(1);
		}
	} return (NULL);
}

static void	eat_routine(t_philo *philo)
{
	safe_sema(WAIT, philo->datas->forks);
	write_state(TAKE_FIRST_FORK, philo);
	safe_sema(WAIT, philo->datas->forks);
	write_state(TAKE_SECOND_FORK, philo);
	philo->last_meal = gettime(MILLISECONDS);
	philo->number_meals++;
	write_state(EATING, philo);
	custom_sleep(philo->datas->time_to_eat);
	if (philo->number_meals == philo->datas->number_cycles)
		philo->is_full = true;
	safe_sema(POST, philo->datas->forks);
	safe_sema(POST, philo->datas->forks);
}

void	dinner_routine(t_philo *philo)
{
	philo->last_meal = philo->datas->simulation_start;
	safe_thread(CREATE, &philo->thread_id, (*checker_routine), philo);
	while (true)
	{
		eat_routine(philo);
		write_state(SLEEPING, philo);
		custom_sleep(philo->datas->time_to_sleep);
		thinking_routine(philo, true);
		if (philo->is_full)
		{
			philo->is_dead = true;
			break ;
		}
	}
	safe_thread(JOIN, &philo->thread_id, NULL, NULL);
	exit(1);
}

void	thinking_routine(t_philo *philo, bool simulation_started)
{
	long	t_think;

	if (simulation_started)
		write_state(THINKING, philo);
	if (philo->datas->number_philo % 2 != 0)
	{
		t_think = (philo->datas->time_to_eat * 2) - philo->datas->time_to_sleep;
		if (t_think < 0)
			t_think = 0;
		custom_sleep(t_think >> 1);
	}
}
