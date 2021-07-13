#include "philo.h"

int	eat(t_params *pa, t_data *data)
{
	if (data->index_mod == 0 && data->forks != 2)
	{
		if (take_forks_even(pa, data->index, data->upper_ind, &data->forks))
			pa->philo_d_a[data->index].ate++;
		else
			return (-1);
	}
	else if (data->forks != 2)
	{
		if (take_forks_odd(pa, data->index, data->upper_ind, &data->forks))
			pa->philo_d_a[data->index].ate++;
	}
	if ((ts(pa) >= pa->philo_d_a[data->index].t_o_m + pa->t_t_e) \
	&& pa->philo_d_a[data->index].ate)
	{
		if (data->index_mod == 0 && data->forks == 2)
			drop_forks_even(pa, data->index, data->upper_ind);
		else if (data->forks == 2)
			drop_forks_odd(pa, data->index, data->upper_ind);
		data->forks -= 2;
		pa->philo_d_a[data->index].state = SLEEP;
		pa->philo_d_a[data->index].s_time = ts(pa);
	}
	return (0);
}

int	sleep_think(t_params *pa, t_data *data)
{
	if (pa->philo_d_a[data->index].state == SLEEP)
	{
		if (ts(pa) >= pa->philo_d_a[data->index].s_time + \
		pa->t_t_s)
			pa->philo_d_a[data->index].state = THINK;
	}
	if (pa->philo_d_a[data->index].state == THINK)
	{
		ft_putaction(pa, "is thinking.\n", data->index, 13);
		pa->philo_d_a[data->index].state = EAT;
	}
	return (0);
}

int	do_philo_stuff(t_params *pa, t_data *data)
{
	while (pa->philo_d_a[data->index].ate < pa->n_times_to_eat)
	{
		if (pa->philo_d_a[data->index].state == EAT)
			if (eat(pa, data) == -1)
				break ;
		if (sleep_think(pa, data) == -1)
			break ;
		usleep(50);
	}
	return (0);
}

void	*ft_philosopher(void *p_data)
{
	t_data		data;
	static int	index = 0;
	t_params	*pa;

	pa = p_data;
	memset((void *) &data, 0, sizeof(t_data));
	pthread_mutex_lock(&pa->check_state);
	data.index = index;
	index++;
	pthread_mutex_unlock(&pa->check_state);
	data.upper_ind = (data.index + 1) % pa->philo_n;
	data.index_mod = data.index % 2;
	if (data.index == 0)
		pa->start_time = ts(pa);
	pa->philo_d_a[data.index].t_o_m = ts(pa);
	do_philo_stuff(pa, &data);
	pthread_mutex_unlock(&pa->mtex_fo[data.index]);
	pthread_mutex_unlock(&pa->mtex_fo[data.upper_ind]);
	return (NULL);
}
