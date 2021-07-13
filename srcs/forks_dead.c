#include "philo.h"

int	check_dead(t_params *pa, long long int index)
{
	pa->philo_d_a[index].limit = pa->time_to_die - \
	(ts(pa) - pa->philo_d_a[index].t_o_m);
	if (pa->philo_d_a[index].limit <= 0)
	{
		ft_putaction(pa, "died.\n", index, 6);
		return (1);
	}
	return (0);
}

int	take_forks_even(t_params *pa, long long int index, \
long long int upper_ind, int *forks)
{
	if (pa->philo_n == 1)
	{
		ft_putaction(pa, "has taken a fork.\n", index, 18);
		return (0);
	}
	pthread_mutex_lock(&pa->mtex_fo[upper_ind]);
	ft_putaction(pa, "has taken a fork.\n", index, 18);
	*forks += 1;
	pthread_mutex_lock(&pa->mtex_fo[index]);
	ft_putaction(pa, "has taken a fork.\n", index, 18);
	*forks += 1;
	ft_putaction(pa, "is eating.\n", index, 11);
	pa->philo_d_a[index].t_o_m = ts(pa);
	return (1);
}

int	take_forks_odd(t_params *pa, long long int index, \
long long int upper_ind, int *forks)
{
	pthread_mutex_lock(&pa->mtex_fo[index]);
	ft_putaction(pa, "has taken a fork.\n", index, 18);
	*forks += 1;
	pthread_mutex_lock(&pa->mtex_fo[upper_ind]);
	ft_putaction(pa, "has taken a fork.\n", index, 18);
	*forks += 1;
	ft_putaction(pa, "is eating.\n", index, 11);
	pa->philo_d_a[index].t_o_m = ts(pa);
	return (1);
}

void	drop_forks_even(t_params *pa, long long int index, \
long long int upper_ind)
{
	ft_putaction(pa, "is sleeping.\n", index, 13);
	pthread_mutex_unlock(&pa->mtex_fo[index]);
	pthread_mutex_unlock(&pa->mtex_fo[upper_ind]);
}

void	drop_forks_odd(t_params *pa, long long int index, \
long long int upper_ind)
{
	ft_putaction(pa, "is sleeping.\n", index, 13);
	pthread_mutex_unlock(&pa->mtex_fo[upper_ind]);
	pthread_mutex_unlock(&pa->mtex_fo[index]);
}
