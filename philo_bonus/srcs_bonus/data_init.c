/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:36:44 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 17:09:49 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	philos_malloc(t_data *datas)
{
	datas->philos = malloc(sizeof(t_philo) * datas->number_philo);
	if (!datas->philos)
	{
		printf("Error : malloc failed !\n");
		return (0);
	}
	memset(datas->philos, 0, sizeof(t_philo) * datas->number_philo);
	return (1);
}

static void	philo_init(t_data *datas)
{
	int	i;

	i = -1;
	while (++i < datas->number_philo)
	{
		datas->philos[i].id = i + 1;
		datas->philos[i].is_full = false;
		datas->philos[i].is_dead = false;
		datas->philos[i].number_meals = 0;
		datas->philos[i].last_meal = 0;
		datas->philos[i].datas = datas;
	}
}

static void	init_semaphores(t_data *datas)
{
	safe_sema(UNLINK, "stop");
	safe_sema(UNLINK, "forks");
	safe_sema(UNLINK, "write");
	datas->stop = safe_sema_open("stop", O_CREAT, 0600, 0);
	datas->write = safe_sema_open("write", O_CREAT, 0600, 1);
	datas->forks = safe_sema_open("forks", O_CREAT, 0600, datas->number_philo);
}

int	data_init(t_data *datas, int argc, char **argv)
{
	datas->number_philo = ft_atol(argv[1]);
	datas->time_to_die = ft_atol(argv[2]) * 1000;
	datas->time_to_eat = ft_atol(argv[3]) * 1000;
	datas->time_to_sleep = ft_atol(argv[4]) * 1000;
	init_semaphores(datas);
	if (argc == 6)
		datas->number_cycles = ft_atol(argv[5]);
	else
		datas->number_cycles = -1;
	if (!philos_malloc(datas))
		return (0);
	philo_init(datas);
	return (1);
}
