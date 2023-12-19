/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hungries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:16:20 by adenord           #+#    #+#             */
/*   Updated: 2023/12/19 23:26:44 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	stop_child(t_data *datas)
{
	int	i;
	int	status;

	i = -1;
	status = 1;
	while (++i < datas->number_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < datas->number_philo)
				kill(datas->philos[i].pid, SIGKILL);
			break ;
		}
	}
	safe_sema(CLOSE, datas->stop, datas);
	safe_sema(CLOSE, datas->forks, datas);
	safe_sema(CLOSE, datas->write, datas);
	safe_sema(UNLINK, "stop", datas);
	safe_sema(UNLINK, "forks", datas);
	safe_sema(UNLINK, "write", datas);
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
	datas->simulation_start = gettime(MILLISECONDS) + 1e3;
	start_process(datas);
	stop_child(datas);
	return (1);
}
