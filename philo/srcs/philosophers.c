/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:52:44 by adenord           #+#    #+#             */
/*   Updated: 2023/12/05 17:57:26 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_data	datas;

	if (!parser(argc, argv))
		return (1);
	if (!data_init(&datas, argc, argv))
		return (1);

	int i = -1;
	while (++i < datas.number_philo)
	{
		printf("philosopher number %d\nleft = %d | right = %d\n\n", datas.philos[i].id, datas.philos[i].left.id, datas.philos[i].right.id);
	}
	// hungries(&datas);  //simulation start
	// 1) create loop to create all threads
	// 2) handle Hcase (1 philosopher or 0 meal to eat)
	// 3) create routine funtion
	// 4) synchronise threads with a new bool in data and a mutex
	// 5) guetters and setters for bool and long
	// 6) get time and put it in data
	//
	// 7) spinlock til the threads are ready
	// 8) am i full ?
	// 9) eat
	// 10) sleep (write status and precise usleep)
	// 11) think
	clean_mess(&datas, -1);
	return (0);
}
