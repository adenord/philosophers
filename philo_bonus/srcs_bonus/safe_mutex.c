/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:10:53 by adenord           #+#    #+#             */
/*   Updated: 2023/12/13 10:50:50 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	error_mutex_handler(int status, t_mtx_code code)
{
	if (status == 0)
		return ;
	if (status == EINVAL && code == INIT)
		error_exit("The value specified by attr is invalid.");
	if (status == EINVAL)
		error_exit("The value specified by mutex is invalid.");
	if (status == ENOMEM)
		error_exit("The process cannot allocate enough memory to create another mutex.");
	if (status == EBUSY)
		error_exit("Mutex is locked.");
	if (status == EPERM)
		error_exit("The current thread does not hold a lock on mutex.");
	if (status == EDEADLK)
		error_exit("A deadlock would occur if the thread blocked waiting for mutex.");
	else
		error_exit("Wtf ? Mutex errno code unknown");
}

void	safe_mutex(pthread_mutex_t *mtx, t_mtx_code code)
{
	if (!mtx)
		error_exit("Pointer to mutex is NULL");
	else if (code == INIT)
		error_mutex_handler(pthread_mutex_init(mtx, NULL), code);
	else if (code == LOCK)
		error_mutex_handler(pthread_mutex_lock(mtx), code);
	else if (code == UNLOCK)
		error_mutex_handler(pthread_mutex_unlock(mtx), code);
	else if (code == DESTROY)
		error_mutex_handler(pthread_mutex_destroy(mtx), code);
	else
		error_exit("Invalid code for safe_mutex function");
}
