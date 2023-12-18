/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:11:42 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 18:37:59 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	safe_sema_handler(int status, t_data *data)
{
	if (status == 0)
		return ;
	free(data->philos);
	if (errno == EINVAL)
		error_exit("sem is not a valid semaphore descriptor.");
	else if (errno == EAGAIN)
		error_exit("The semaphore is already locked.");
	else if (errno == EDEADLK)
		error_exit("A deadlock was detected.");
	else if (errno == EINTR)
		error_exit("The call was interrupted by a signal.");
	else if (errno == EACCES)
		error_exit("Permission is denied to be remove the semaphore.");
	else if (errno == ENAMETOOLONG)
		error_exit("name exceeded PSEMNAMLEN characters.");
	else if (errno == ENOENT)
		error_exit("The named semaphore does not exist.");
	else
		error_exit("Unknown ERRNO (safe_sema)");
}

void	safe_sema(t_sema_code code, void *sem, t_data *data)
{
	if (code == CLOSE)
		safe_sema_handler(sem_close(sem), data);
	else if (code == POST)
		safe_sema_handler(sem_post(sem), data);
	else if (code == WAIT)
		safe_sema_handler(sem_wait(sem), data);
	else if (code == UNLINK)
		sem_unlink((const char *)sem);
	else
		error_exit("Invalid opcode for sema operation");
}

static void	safe_sema_open_handler(t_data *datas)
{
	free(datas->philos);
	if (errno == EACCES)
		error_exit("The required permissions are denied for the given flags");
	else if (errno == EEXIST)
		error_exit("O_CREAT and O_EXCL were specified and semaphore exists");
	else if (errno == EINTR)
		error_exit("The sem_open() operation was interrupted by a signal.");
	else if (errno == EINVAL)
		error_exit("The shm_open() operation is not supported; or O_CREAT is\
 specified and value exceeds SEM_VALUE_MAX.");
	else if (errno == EMFILE)
		error_exit("The process has already reached its limit for semaphores\
 or file descriptors in use.");
	else if (errno == ENAMETOOLONG)
		error_exit("name exceeded PSEMNAMLEN characters.");
	else if (errno == ENFILE)
		error_exit("Too many semaphores or fd are open on the system.");
	else if (errno == ENOENT)
		error_exit("O_CREAT is not set and the named semaphore does not exist");
	else if (errno == ENOSPC)
		error_exit("O_CREAT is specified, the file does not exist, and there\
 is insufficient space available to create the semaphore.");
	else
		error_exit("Unknown ERRNO (safe_sema_open)");
}

sem_t	*safe_sema_open(char *name, t_data *datas, mode_t perm, \
		unsigned int value)
{
	sem_t	*ret;

	ret = sem_open(name, O_CREAT, perm, value);
	if (ret == SEM_FAILED)
		safe_sema_open_handler(datas);
	return (ret);
}
