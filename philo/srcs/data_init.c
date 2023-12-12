/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:36:44 by adenord           #+#    #+#             */
/*   Updated: 2023/12/12 14:42:38 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	philos_fork_malloc(t_data *datas)
{
	datas->philos = malloc(sizeof(t_philo) * datas->number_philo);
	if (!datas->philos)
	{
		printf("Error : malloc failed !\n");
		return (0);
	}
	memset(datas->philos, 0, sizeof(t_philo) * datas->number_philo);
	datas->forks = malloc(sizeof(t_fork) * datas->number_philo);
	if (!datas->forks)
	{
		free(datas->philos);
		printf("Error : malloc failed !\n");
		return (0);
	}
	memset(datas->forks, 0, sizeof(t_fork) * datas->number_philo);
	return (1);
}

static int	forks_init(t_data *datas)
{
	int	i;

	i = -1;
	while (++i < datas->number_philo)
	{
		if (pthread_mutex_init(&datas->forks[i].mtx, NULL))
		{
			clean_mess(datas, i);
			printf("Error : mutex initialization failed\n");
			return (0);
		}
		datas->forks[i].id = i;
	}
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
		datas->philos[i].number_meals = 0;
		datas->philos[i].last_meal = 0;
		datas->philos[i].datas = datas;
		pthread_mutex_init(&datas->philos->philo_mtx, NULL);
		datas->philos[i].first = &datas->forks[(i + 1) % datas->number_philo];
		datas->philos[i].second = &datas->forks[i];
		if (datas->philos[i].id % 2 == 0)
		{
			datas->philos[i].first = &datas->forks[i];
			datas->philos[i].second = \
			&datas->forks[(i + 1) % datas->number_philo];
		}
	}
}

int	data_init(t_data *datas, int argc, char **argv)
{
	datas->number_philo = ft_atol(argv[1]);
	datas->time_to_die = ft_atol(argv[2]) * 1000;
	datas->time_to_eat = ft_atol(argv[3]) * 1000;
	datas->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (argc == 6)
		datas->number_cycles = ft_atol(argv[5]);
	else
		datas->number_cycles = -1;
	datas->end_of_simulation = false;
	datas->everybody_ready = false;
	pthread_mutex_init(&datas->table_mtx, NULL);
	pthread_mutex_init(&datas->write_mtx, NULL);
	if (!philos_fork_malloc(datas))
		return (0);
	if (!forks_init(datas))
		return (0);
	philo_init(datas);
	return (1);
}
