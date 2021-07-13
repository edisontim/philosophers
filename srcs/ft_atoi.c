/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:22:48 by tedison           #+#    #+#             */
/*   Updated: 2021/06/30 10:39:09 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char c, int *i)
{
	*i = 0;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

unsigned long long int	ft_atoi(const char *str)
{
	int					i;
	long long			sign;
	unsigned long long	number;
	int					c;

	c = 0;
	i = 0;
	sign = 1;
	number = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number += str[i++] - '0';
		c++;
		if (str[i] >= '0' && str[i] <= '9')
			number *= 10;
	}
	if ((number > 9223372036854775807ull && sign > 0) || (sign > 0 && c > 19))
		return (-1);
	else if ((number > 9223372036854775808ull && sign < 0) || c > 19)
		return (0);
	return (number * sign);
}
