/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:24:54 by adenord           #+#    #+#             */
/*   Updated: 2023/12/12 15:52:39 by adenord          ###   ########.fr       */
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
			printf(RED"Error : Invalid arguments\n"RST);
			return (0);
		}
		if (i > 17)
		{
			printf(RED"Error : wtf ?! too much is too much\n"RST);
			return (0);
		}
	}
	return (1);
}

static int	check_args(char **argv)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = 0;
	while (argv[++i])
	{
		if (!check_str(argv[i]))
			return (0);
		tmp = ft_atol(argv[i]);
		if ((i == 1 && (tmp > 200 || tmp == 0)) || \
		(i > 1 && i < 5 && (tmp < 60 || tmp > INT_MAX)) || \
		(i == 5 && (tmp > INT_MAX || tmp <= 0)))
		{
			printf(RED"Error : value too high or too low\n"RST
				B"Hint : number_of_philosophers\t\t[1  - 200]\n"RST
				B"Hint : time_to_die\t\t\t[60 - INT_MAX]\n"RST
				B"Hint : time_to_eat\t\t\t[60 - INT_MAX]\n"RST
				B"Hint : time_to_sleep\t\t\t[60 - INT_MAX]\n"RST
				B"Hint : number_of_times_philo_must_eat\t[1  - INT_MAX]\n"RST);
			return (0);
		}
	}
	return (1);
}

int	check_format(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf(RED"Error : Invalid number of arguments\n"RST);
		return (0);
	}
	if (!check_args(argv))
		return (0);
	return (1);
}
