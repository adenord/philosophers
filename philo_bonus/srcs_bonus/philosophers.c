/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:52:44 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 18:04:17 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_data	datas;

	if (!check_format(argc, argv))
		return (1);
	if (!data_init(&datas, argc, argv))
		return (1);
	if (!hungries(&datas))
		return (1);
	free(datas.philos);
	return (0);
}
