/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:07 by adenord           #+#    #+#             */
/*   Updated: 2023/12/12 14:45:49 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->first->mtx);
	write_state(TAKE_FIRST_FORK, philo);
	pthread_mutex_lock(&philo->second->mtx);
	write_state(TAKE_SECOND_FORK, philo);
	set_long(&philo->philo_mtx, &philo->last_meal, gettime(MILLISECONDS));
	philo->number_meals++;
	write_state(EATING, philo);
	custom_sleep(philo->datas->time_to_eat, philo->datas);
	if (philo->datas->number_cycles > 0 && \
	philo->number_meals == philo->datas->number_cycles)
		set_bool(&philo->philo_mtx, &philo->is_full, true);
	pthread_mutex_unlock(&philo->first->mtx);
	pthread_mutex_unlock(&philo->second->mtx);
}

void	*checker_routine(void *data)
{
	int		i;
	t_data	*datas;

	datas = (t_data *)data;
	wait_every_philos(datas);
	custom_sleep(1000, data);
	while (!simulation_finished(datas))
	{
		i = -1;
		while (++i < datas->number_philo && !simulation_finished(datas))
		{
			if (death(&datas->philos[i]))
			{
				write_state(DIED, &datas->philos[i]);
				set_bool(&datas->table_mtx, &datas->end_of_simulation, true);
			}
		}
	}
	return (NULL);
}

void	*dinner_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_every_philos(philo->datas);
	set_long(&philo->philo_mtx, &philo->last_meal, gettime(MILLISECONDS));
	force_odd_to_think(philo);
	while (!simulation_finished(philo->datas))
	{
		if (get_bool(&philo->philo_mtx, &philo->is_full))
			break ;
		eat_routine(philo);
		write_state(SLEEPING, philo);
		custom_sleep(philo->datas->time_to_sleep, philo->datas);
		thinking_routine(philo, true);
	}
	return (NULL);
}

void	*philo_alone(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_every_philos(philo->datas);
	set_long(&philo->philo_mtx, &philo->last_meal, gettime(MILLISECONDS));
	write_state(TAKE_FIRST_FORK, philo);
	while (!simulation_finished(philo->datas))
		custom_sleep(50, data);
	return (NULL);
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
		custom_sleep(t_think >> 1, philo->datas);
	}
}
