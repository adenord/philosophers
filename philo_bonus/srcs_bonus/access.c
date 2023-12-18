/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:11:52 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 10:57:46 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// bool	get_bool(pthread_mutex_t *mtx, bool *toget)
// {
// 	bool	ret;

// 	ret = false;
// 	pthread_mutex_lock(mtx);
// 	ret = *toget;
// 	pthread_mutex_unlock(mtx);
// 	return (ret);
// }

// void	set_bool(pthread_mutex_t *mtx, bool *toset, bool value)
// {
// 	pthread_mutex_lock(mtx);
// 	*toset = value;
// 	pthread_mutex_unlock(mtx);
// }

// long	get_long(pthread_mutex_t *mtx, long *toget)
// {
// 	long	ret;

// 	ret = 0;
// 	pthread_mutex_lock(mtx);
// 	ret = *toget;
// 	pthread_mutex_unlock(mtx);
// 	return (ret);
// }

// void	set_long(pthread_mutex_t *mtx, long *toset, long value)
// {
// 	pthread_mutex_lock(mtx);
// 	*toset = value;
// 	pthread_mutex_unlock(mtx);
// }

// bool	simulation_finished(t_data *datas)
// {
// 	return (get_bool(&datas->table_mtx, &datas->end_of_simulation));
// }
