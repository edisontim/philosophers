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
	long long		i;
	t_params		*pa;

	pa = p_data;
	pthread_mutex_lock(&pa->check_death);
	while (19)
	{
		i = -1;
		while (++i < pa->philo_n)
		{
			if (check_dead(pa, i) == 1 || check_eat(pa))
			{
				pa->dead = 1;
				return (NULL);
			}
			usleep(50);
		}
	}
	return (NULL);
}
