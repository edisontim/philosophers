#include "philo_bonus.h"

void	binary(char *str, unsigned int pid)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != 0)
	{
		if (str[i] == '0')
			kill(pid, SIGUSR1);
		if (str[i] == '1')
			kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
}

void	send_message(unsigned int pid, char *str)
{
	char			*binary_char;
	int				i;

	i = 0;
	if (pid < 0)
		return ;
	binary_char = NULL;
	binary_char = ft_convert_base(str);
	if (binary_char == NULL)
		exit(1);
	while (i < 4)
	{
		binary_char[i] = '0';
		i++;
	}
	binary(binary_char, pid);
	if (binary_char)
		free(binary_char);
}

size_t	count_digits(unsigned int n)
{
	size_t			count;
	unsigned int	nbr;	

	count = 0;
	if (n == 0)
		return (1);
	nbr = n;
	if (n < 0)
	{
		count++;
		nbr = -n;
	}
	while (nbr > 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

char	*ft_itoa(unsigned int n)
{
	char	*to_return;
	int		index;

	index = 0;
	to_return = NULL;
	to_return = malloc(sizeof(*to_return) * (count_digits(n) + 1));
	if (!to_return)
		return (NULL);
	ft_myputnbr(n, to_return, &index);
	to_return[index] = '\0';
	return (to_return);
}

int	send_pid(unsigned int index, unsigned int pid)
{
	char	*index_str;

	index_str = ft_itoa(index);
	if (!index_str)
		return (MALLOC_ERROR);
	send_message(pid, index_str);
	free(index_str);
	return (0);
}
