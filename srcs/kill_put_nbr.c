#include "philo_bonus.h"

void	kill_processes(int signal)
{
	int	i;

	i = 0;
	while (i < params_b.philo_n)
	{
		kill(params_b.pids[i], signal);
		i++;
	}
	sem_unlink(SEM_NAME);
}

void	ft_myputnbr(unsigned int n, char *arr, int *c)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		arr[0] = '-';
		*c = *c + 1;
		nbr = -nbr;
	}
	if (nbr < 10)
	{
		arr[*c] = nbr + '0';
		*c = *c + 1;
	}
	else
	{
		ft_myputnbr(nbr / 10, arr, c);
		ft_myputnbr(nbr % 10, arr, c);
	}
}
