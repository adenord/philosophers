/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:48:04 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 11:00:52 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// void	clean_mess(t_data *datas, int last)
// {
// 	int	i;

// 	i = -1;
// 	if (last > 0)
// 	{
// 		while (++i < last)
// 			pthread_mutex_destroy(&datas->forks[i].mtx);
// 	}
// 	else
// 	{
// 		while (++i < datas->number_philo)
// 			pthread_mutex_destroy(&datas->forks[i].mtx);
// 	}
// 	free(datas->forks);
// 	free(datas->philos);
// }

// void	wash_it(t_data *datas, int last)
// {
// 	int	i;

// 	i = -1;
// 	while (i < last)
// 	{
// 		pthread_join(datas->philos[i].thread_id, NULL);
// 	}
// 	clean_mess(datas, -1);
// }

void	error_exit(char *e_str)
{
	printf("ERROR : %s\n", e_str);
	exit(1);
}
