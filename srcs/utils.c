#include "philo.h"
#include "philo_bonus.h"

int	nbr_size(long long int nbr)
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

int	get_args(int argc, char *argv[], t_params *pa)
{
	if (!only_num(argv))
		return (0);
	pa->philo_n = ft_atoi(argv[0]);
	pa->time_to_die = ft_atoi(argv[1]);
	pa->t_t_e = ft_atoi(argv[2]);
	pa->t_t_s = ft_atoi(argv[3]);
	if (pa->t_t_s <= 0 || pa->t_t_e <= 0 \
			|| pa->time_to_die <= 0 || pa->philo_n > 825 || pa->philo_n < 1)
		return (0);
	if (argc == 6)
		pa->n_times_to_eat = ft_atoi(argv[4]);
	else
		pa->n_times_to_eat = 9223372036854775807;
	return (1);
}
