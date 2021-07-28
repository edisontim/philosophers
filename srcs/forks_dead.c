#include "philo.h"

int	check_dead(t_params *pa, long long int index)
{
	if (ts(pa) >= pa->philo_d_a[index].t_o_m + pa->time_to_die)
	{
		ft_putaction(pa, "died.\n", index, 6);
		pthread_mutex_lock(&pa->write_lock);
		return (1);
	}
	return (0);
}

int	take_forks(t_params *pa, t_data *data, int index)
{
	if (data->philo_n == 1)
	{
		ft_putaction(pa, "has taken a fork.\n", index, 18);
		return (EAT);
	}
	if (pa->dead == 1)
		return (0);
	pthread_mutex_lock(&pa->mtex_fo[(index + 1) % data->philo_n]);
	ft_putaction(pa, "has taken a fork.\n", index, 18);
	if (pa->dead == 1)
	{
		pthread_mutex_unlock(&pa->mtex_fo[(index + 1) % data->philo_n]);
		return (0);
	}
	pthread_mutex_lock(&pa->mtex_fo[index]);
	ft_putaction(pa, "has taken a fork.\n", index, 18);
	ft_putaction(pa, "is eating.\n", index, 11);
	if (pa->dead == 1)
		return (0);
	pa->philo_d_a[index].t_o_m = ts(pa);
	data->t_o_m = ts(pa);
	pa->philo_d_a[index].ate++;
	data->ate++;
	return (1);
}

int	drop_forks(t_params *pa, long long int index, t_data *data)
{
	ft_putaction(pa, "is sleeping.\n", index, 13);
	if (pa->dead == 1)
		return (0);
	pthread_mutex_unlock(&pa->mtex_fo[index]);
	if (pa->dead == 1)
		return (0);
	pthread_mutex_unlock(&pa->mtex_fo[(index + 1) % data->philo_n]);
	return (1);
}
