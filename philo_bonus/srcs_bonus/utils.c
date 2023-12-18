/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:11:15 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 10:56:55 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// bool	death(t_philo *philo)
// {
// 	long	elapsed;
// 	long	last;

// 	last = get_long(&philo->philo_mtx, &philo->last_meal);
// 	if (get_bool(&philo->philo_mtx, &philo->is_full))
// 		return (false);
// 	elapsed = gettime(MILLISECONDS) - last;
// 	if (elapsed > (philo->datas->time_to_die / 1e3))
// 		return (true);
// 	return (false);
// }

// void	wait_every_philos(t_data *datas)
// {
// 	while (!get_bool(&datas->table_mtx, &datas->everybody_ready))
// 		;
// }

// void	force_odd_to_think(t_philo *philo)
// {
// 	if (philo->datas->number_philo % 2 == 0)
// 	{
// 		if (philo->id % 2 == 0)
// 			custom_sleep(3e4, philo->datas);
// 	}
// 	else
// 	{
// 		if (philo->id % 2)
// 			thinking_routine(philo, false);
// 	}
// }
