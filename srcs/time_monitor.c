#include "philo.h"

int	check_eat(t_params *pa)
{
	int	i;
	int	n;
	
	n = 0;
	i = -1;
	while (++i < pa->philo_n)
			if (pa->philo_d_a[i].ate == pa->n_times_to_eat)
				n++;
	if (n == pa->philo_n)
		return (1);
	else
		return (0);
}

void	*time_monitor(void *p_data)
{
	long long int	i;
	t_params *pa;

	pa = (t_params *)p_data;
	while (19)
	{
		i = -1;
		while (++i < pa->philo_n)
			if (check_dead(pa, i) == 1 || check_eat(pa) == 1)
				return (NULL);
	}
	return (NULL);
}
