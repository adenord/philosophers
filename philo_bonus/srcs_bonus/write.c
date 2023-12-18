/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:59:39 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 22:28:25 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	write_state(t_philo_state state, t_philo *philo)
{
	long	elapsed;

	elapsed = gettime(MILLISECONDS) - philo->datas->simulation_start;
	if (philo->is_full)
		return ;
	safe_sema(WAIT, philo->datas->write, philo->datas);
	if ((TAKE_FIRST_FORK == state || TAKE_SECOND_FORK == state))
		printf(RST B"%-10ld %d"RST Y" has taken a fork\n"RST, \
		elapsed, philo->id);
	if (EATING == state)
		printf(B"%-10ld %d"RST G" is eating\n"RST, elapsed, philo->id);
	if (SLEEPING == state)
		printf(RST B"%-10ld %d"RST M" is sleeping\n"RST, elapsed, philo->id);
	if (THINKING == state)
		printf(RST B"%-10ld %d"RST C" is thinking\n"RST, elapsed, philo->id);
	if (DIED == state)
	{
		printf(RST B"%-10ld %d"RST RED" died\n"RST, elapsed, philo->id);
		return ;
	}
	safe_sema(POST, philo->datas->write, philo->datas);
}
