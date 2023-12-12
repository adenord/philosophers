/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hungries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:16:20 by adenord           #+#    #+#             */
/*   Updated: 2023/12/12 16:58:10 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	init_threads(t_data *datas)
{
	int	i;

	i = -1;
	while (++i < datas->number_philo)
	{
		if (pthread_create(&datas->philos[i].thread_id, NULL, \
		(*dinner_routine), &datas->philos[i]) != 0)
		{
			wash_it(datas, i);
			return (0);
		}
	}
	return (1);
}

int	hungries(t_data *datas)
{
	int	i;

	i = -1;
	if (datas->number_cycles == 0)
		return (0);
	if (datas->number_philo == 1)
		pthread_create(&datas->philos[0].thread_id, NULL, \
		(*philo_alone), &datas->philos[0]);
	else if (!init_threads(datas))
		return (0);
	pthread_create(&datas->checker, NULL, (*checker_routine), datas);
	datas->simulation_start = gettime(MILLISECONDS);
	set_bool(&datas->table_mtx, &datas->everybody_ready, true);
	while (++i < datas->number_philo)
		pthread_join(datas->philos[i].thread_id, NULL);
	set_bool(&datas->table_mtx, &datas->end_of_simulation, true);
	pthread_join(datas->checker, NULL);
	return (1);
}
