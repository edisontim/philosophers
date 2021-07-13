#include "philo_bonus.h"

char	*ft_putnbr_base(char *tab, long long int nb, char *base, int *index)
{
	long long int	nbr;
	unsigned int	size;

	size = 0;
	while (base[size])
		size++;
	nbr = nb;
	if (nb < 0)
	{
		tab[0] = '-';
		nbr = -nbr;
		*index = *index + 1;
	}
	if (nbr < size)
	{
		tab[*index] = base[nbr];
		*index = *index + 1;
	}
	else
	{
		ft_putnbr_base(tab, nbr / size, base, index);
		ft_putnbr_base(tab, nbr % size, base, index);
	}
	return (tab);
}

void	ft_putaction(char *str, long long int index, int size)
{
	char			*final_str;
	int				i;
	long long int	time;
	int				len;
	static int		done = 0;

	time = timestamp() - params_b.start_time;
	len = siz(index + 1) + 1 + siz(time) + 1 + size + 1;
	final_str = malloc(sizeof(char) * (siz(index + 1) + siz(time) + 3));
	final_str[siz(time)] = ' ';
	final_str[siz(time) + siz(index + 1) + 2] = 0;
	final_str[siz(time) + siz(index + 1) + 1] = ' ';
	i = 0;
	ft_putnbr_base(final_str, time, "0123456789", &i);
	i = siz(time) + 1;
	ft_putnbr_base(final_str, index + 1, "0123456789", &i);
	final_str = ft_strjoin(final_str, str);
	final_str = ft_strjoin(final_str, "\n");
	if (!done)
	{
		if (size == 8)
			done = 1;
		write(1, final_str, len);
	}
	free(final_str);
}
