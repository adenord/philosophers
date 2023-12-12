/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:14:58 by adenord           #+#    #+#             */
/*   Updated: 2023/12/06 10:23:55 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long	gettime(t_time_code code)
{
	t_time	now;

	gettimeofday(&now, NULL);
	if (code == SECONDS)
		return (now.tv_sec + (now.tv_usec / 1e6));
	else if (code == MILLISECONDS)
		return ((now.tv_sec * 1e3) + (now.tv_usec / 1e3));
	else if (code == MICROSECONDS)
		return ((now.tv_sec * 1e6) + now.tv_usec);
	else
		return (-1);
}
