/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:11:23 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 18:07:31 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static long	elapsed_time(t_time start, t_time end)
{
	return ((end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec));
}

void	custom_sleep(long wait_time)
{
	t_time	start_sleep;
	t_time	after_sleep;
	long	rtts;
	long	elapsed_t;

	gettimeofday(&start_sleep, NULL);
	elapsed_t = 0;
	while (elapsed_t < wait_time)
	{
		gettimeofday(&after_sleep, NULL);
		elapsed_t = elapsed_time(start_sleep, after_sleep);
		rtts = wait_time - elapsed_t;
		if (rtts > 200)
			usleep(rtts / 2);
	}
}
