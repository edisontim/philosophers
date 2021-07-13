/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:45:25 by tedison           #+#    #+#             */
/*   Updated: 2021/06/30 10:47:56 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	siz(long long int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

long long int	timestamp(void)
{
	gettimeofday(&params_b.tv, NULL);
	return (params_b.tv.tv_sec * 1000 + params_b.tv.tv_usec / 1000);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	only_num(char *argv[])
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!is_num(argv[i][j]) && argv[i][j] != '-')
				return (0);
			if (argv[i][j] == '-' && argv[i][j + 1] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_args(int argc, char *argv[])
{
	if (!only_num(argv))
		return (0);
	params_b.philo_n = ft_atoi(argv[0]);
	params_b.time_to_die = ft_atoi(argv[1]);
	params_b.time_to_eat = ft_atoi(argv[2]);
	params_b.time_to_sleep = ft_atoi(argv[3]);
	if (params_b.time_to_sleep <= 0 || params_b.time_to_eat <= 0 \
	|| params_b.time_to_die <= 0 || params_b.philo_n > 825
		|| params_b.philo_n < 1)
		return (0);
	if (argc == 6)
		params_b.n_times_to_eat = ft_atoi(argv[4]);
	else
		params_b.n_times_to_eat = 9223372036854775807;
	return (1);
}
