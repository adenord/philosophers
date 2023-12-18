/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:48:04 by adenord           #+#    #+#             */
/*   Updated: 2023/12/18 18:05:25 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

static void	str_error_custom(char *str)
{
	if (str)
	{
		write(2, "ERROR : ", 8);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
}

void	error_exit(char *e_str)
{
	str_error_custom(e_str);
	exit(1);
}
