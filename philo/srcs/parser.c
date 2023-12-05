/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:24:54 by adenord           #+#    #+#             */
/*   Updated: 2023/12/05 16:06:27 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	check_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("Error : Invalid arguments\n");
			return (0);
		}
		if (i > 17)
		{
			printf("Error : wtf ?! too much is too much\n");
			return (0);
		}
	}
	return (1);
}

static int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		printf("Error : Invalid number of arguments\n");
		return (0);
	}
	while (argv[++i])
	{
		if (!check_str(argv[i]))
			return (0);
		if (ft_atol(argv[i]) > INT_MAX)
		{
			printf("Error : wtf ?! too much is too much\n");
			return (0);
		}
	}
	return (1);
}

int	parser(int argc, char **argv)
{
	if (!check_args(argc, argv))
		return (0);
	return (1);
}
