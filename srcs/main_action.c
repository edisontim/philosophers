#include "philo.h"

static int	eat(t_params *pa, t_data *data, int state)
{
	if (state == EAT)
	{
		if (!take_forks(pa, data, data->index))
			return (-1);
		return (EATING);
	}
	if ((ts(pa) >= data->t_o_m + data->t_t_e) && state == EATING)
	{
		if (!drop_forks(pa, data->index, data))
			return (-1);
		data->sleep_at = ts(pa);
		return (SLEEP);
	}
	return (state);
}

static int	sleep_think(t_params *pa, t_data *data, int state)
{
	if (state == SLEEP)
	{
		if (ts(pa) >= data->sleep_at + data->t_t_s)
			return (THINK);
		else
			usleep(50);
		return (SLEEP);
	}
	if (state == THINK)
	{
		ft_putaction(pa, "is thinking.\n", data->index, 13);
		return (EAT);
	}
	return (state);
}

int	do_philo_stuff(t_params *pa, t_data *data)
{
	int	state;

	state = EAT;
	while (1)
	{
		state = eat(pa, data, state);
		if (state == -1)
			return (0);
		usleep(400);
		state = sleep_think(pa, data, state);
		if (state == -1)
			return (0);
		usleep(400);
	}
	return (0);
}

void	*ft_philosopher(void *p_data)
{
	t_data			data;
	static int		index = 0;
	t_params		*pa;

	pa = p_data;
	memset((void *) &data, 0, sizeof(t_data));
	data.index = index;
	index++;
	if (data.index == 0)
		pa->start_time = ts(pa);
	pa->philo_d_a[data.index].t_o_m = pa->start_time;
	data.t_o_m = pa->start_time;
	data.n_times_to_eat = pa->n_times_to_eat;
	data.t_t_s = pa->t_t_s;
	data.t_t_e = pa->t_t_e;
	data.philo_n = pa->philo_n;
	if (data.index % 2 == 0)
		usleep(pa->t_t_e * 1000 / 2);
	do_philo_stuff(pa, &data);
	return (NULL);
}
