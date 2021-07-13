#include "philo_bonus.h"

int	take_fork(sem_t *sem, unsigned int index)
{
	sem_wait(sem);
	ft_putaction("has taken a fork.", index, 17);
	return (1);
}

int	drop_forks(sem_t *sem, unsigned int index)
{
	ft_putaction("is sleeping.", index, 12);
	sem_post(sem);
	sem_post(sem);
	return (1);
}

int	take(sem_t *sem, t_data_b *data_b)
{
	take_fork(sem, data_b->index);
	data_b->forks++;
	if (check_dead_b(sem, data_b->index, data_b->t_o_m, data_b->forks))
		return (0);
	take_fork(sem, data_b->index);
	data_b->forks++;
	data_b->ate++;
	data_b->t_o_m = timestamp();
	return (1);
}

int	eat_b(t_data_b *data_b, sem_t *sem)
{
	if (data_b->state == EAT)
	{
		if (params_b.philo_n == 1)
		{
			take_fork(sem, data_b->index);
			data_b->state = 4;
			return (1);
		}
		if (data_b->forks < 2)
			if (!take(sem, data_b))
				return (0);
		if (timestamp() >= data_b->t_o_m + \
		params_b.time_to_eat && data_b->ate)
		{
			drop_forks(sem, data_b->index);
			data_b->forks--;
			data_b->forks--;
			data_b->state = SLEEP;
			data_b->s_time = timestamp();
		}
	}
	return (1);
}

int	sleep_think_b(t_data_b *data_b, sem_t *sem)
{
	if (data_b->state == SLEEP)
	{
		if (timestamp() >= data_b->s_time + params_b.time_to_sleep)
			data_b->state = THINK;
	}
	if (check_dead_b(sem, data_b->index, data_b->t_o_m, data_b->forks))
		return (0);
	if (data_b->state == THINK)
	{
		ft_putaction("is thinking.", data_b->index, 12);
		data_b->state = EAT;
	}
	return (1);
}
