/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:42:04 by adenord           #+#    #+#             */
/*   Updated: 2023/12/05 18:39:33 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_data
{
	int				test;
	pthread_mutex_t	guardian;
}	t_data;

t_data	*init(int i)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->test = i;
	pthread_mutex_init(&data->guardian, NULL);
	return (data);
}

void	*incr(void	*data)
{
	int	i;
	t_data *ta;

	ta = (t_data *)data;
	i = 10000;
	while (i > 0)
	{
		pthread_mutex_lock(&ta->guardian);
		(ta->test)++;
		pthread_mutex_unlock(&ta->guardian);
		i--;
	}
	return (NULL);
}

int main(void)
{
	pthread_t	t1;
	pthread_t	t2;
	t_data		*data;

	data = init(42);
	pthread_create(&t1, NULL, (*incr), data);
	pthread_create(&t2, NULL, (*incr), data);
	// usleep(150);
	// pthread_detach(t1);
	// pthread_detach(t2);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&data->guardian);
	printf("%d\n", data->test);
}
