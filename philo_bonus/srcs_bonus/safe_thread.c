/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:51:01 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 18:55:37 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	error_thread_handler(int status, t_thread_code code, t_data *datas)
{
	if (status == 0)
		return ;
	free(datas->philos);
	if (status == EAGAIN)
		error_exit("The system lacked the necessary resources to create another\
thread, or the system-imposed limit on the total number of threads in a process\
 [PTHREAD_THREADS_MAX] would be exceeded.");
	if (status == EPERM)
		error_exit("The caller does not have appropriate permission to set the\
 required scheduling parameters or scheduling policy.");
	if (status == EINVAL && code == CREATE)
		error_exit("The value specified by attr is invalid.");
	if (status == EINVAL)
		error_exit("The implementation has detected that the value specified by\
 thread does not refer to a joinable thread.");
	if (status == ESRCH)
		error_exit("No thread could be found corresponding to that specified by\
 the given thread ID, thread.");
	if (status == EDEADLK)
		error_exit("A deadlock was detected or the value of thread specifies\
 the calling thread.");
}

void	safe_thread(t_thread_code code, t_data *datas, \
		void *(*f)(void *), void *arg)
{
	if (code == CREATE)
		error_thread_handler(pthread_create(&datas->philos->thread_id, \
		NULL, (*f), arg), code, datas);
	else if (code == JOIN)
		error_thread_handler(pthread_join(datas->philos->thread_id, NULL), \
		code, datas);
	else if (code == DETACH)
		error_thread_handler(pthread_detach(datas->philos->thread_id), \
		code, datas);
	else
		error_exit("Invalid code for safe_thread function");
}
