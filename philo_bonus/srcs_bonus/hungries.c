/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hungries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:16:20 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 17:17:51 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	stop_child(t_data *datas)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < datas->number_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < datas->number_philo)
				kill(datas->philos[i].pid, SIGKILL);
			break ;
		}
		i++;
	}
	safe_sema(CLOSE, datas->stop);
	safe_sema(CLOSE, datas->forks);
	safe_sema(CLOSE, datas->write);
	safe_sema(UNLINK, "stop");
	safe_sema(UNLINK, "forks");
	safe_sema(UNLINK, "write");
}

static void	start_process(t_data *datas)
{
	int	i;

	i = 0;
	while (i < datas->number_philo)
	{
		datas->philos[i].pid = fork();
		if (datas->philos[i].pid == 0)
		{
			dinner_routine(&datas->philos[i]);
			exit(0);
		}
		i++;
	}
}

int	hungries(t_data *datas)
{
	datas->simulation_start = gettime(MILLISECONDS);
	start_process(datas);
	stop_child(datas);
	return (1);
}
