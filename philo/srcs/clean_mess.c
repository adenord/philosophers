/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:48:04 by adenord           #+#    #+#             */
/*   Updated: 2023/12/05 16:05:34 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	clean_mess(t_data *datas, int last)
{
	int	i;

	i = -1;
	if (last > 0)
	{
		while (++i < last)
			pthread_mutex_destroy(&datas->forks[i].mtx);
	}
	else
	{
		while (++i < datas->number_philo)
			pthread_mutex_destroy(&datas->forks[i].mtx);
	}
	free(datas->forks);
	free(datas->philos);
}
