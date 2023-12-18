/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:11:42 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 17:10:13 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	safe_sema_handler(int status)
{
	if (status == 0)
		return ;
	else if (errno == EINVAL)
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

void	safe_sema(t_sema_code code, void *sem)
{
	if (code == CLOSE)
		safe_sema_handler(sem_close(sem));
	else if (code == POST)
		safe_sema_handler(sem_post(sem));
	else if (code == WAIT)
		safe_sema_handler(sem_wait(sem));
	else if (code == UNLINK)
		sem_unlink((const char *)sem);
	else
		error_exit("Invalid opcode for sema operation");
}

static void	safe_sema_open_handler(void)
{
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
		error_exit("Too many semaphores or file descriptors are open on the system.");
	else if (errno == ENOENT)
		error_exit("O_CREAT is not set and the named semaphore does not exist");
	else if (errno == ENOSPC)
		error_exit("O_CREAT is specified, the file does not exist, and there\
 is insufficient space available to create the semaphore.");
	else
		error_exit("Unknown ERRNO (safe_sema_open)");
}

sem_t	*safe_sema_open(char *name, int oflag, mode_t perm, unsigned int value)
{
	sem_t	*ret;

	ret = NULL;
	if (oflag == O_CREAT)
		ret = sem_open(name, oflag, perm, value);
	else if (oflag == O_EXCL)
		ret = sem_open(name, oflag);
	else
		error_exit("Wrong oflag for sem_open !");
	if (ret == SEM_FAILED)
		safe_sema_open_handler();
	return (ret);
}
