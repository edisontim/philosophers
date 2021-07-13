#include "philo_bonus.h"

int	check_dead_b(sem_t *sem, long long int index, \
long long int t_o_m, int forks)
{
	long long int	limit;

	limit = params_b.time_to_die - (timestamp() - t_o_m);
	if (limit <= 0)
	{
		ft_putaction("is dead.", index, 8);
		while (forks != 0)
		{
			sem_post(sem);
			forks--;
		}
		return (1);
	}
	return (0);
}

int	philosopher(sem_t *sem)
{
	t_data_b	data_b;

	memset((void *) &data_b, 0, sizeof(t_data_b));
	data_b.index = get_pid();
	if (data_b.index == MALLOC_ERROR)
		return (MALLOC_ERROR);
	data_b.t_o_m = timestamp();
	while (data_b.ate < params_b.n_times_to_eat)
	{
		signal(SIGINT, signal_handler);
		if (check_dead_b(sem, data_b.index, data_b.t_o_m, data_b.forks))
			return (0);
		if (!eat_b(&data_b, sem))
			return (0);
		if (check_dead_b(sem, data_b.index, data_b.t_o_m, data_b.forks))
			return (0);
		if (!sleep_think_b(&data_b, sem))
			return (0);
		usleep(50);
	}	
	while (data_b.forks-- != 0)
		sem_post(sem);
	return (1);
}

int	init_processes(int i, unsigned int *pid)
{
	while (i < params_b.philo_n)
	{
		if (*pid != 0)
		{
			if (i == 0)
				params_b.start_time = timestamp();
			*pid = fork();
			signal(SIGINT, kill_processes);
			if (*pid != 0)
			{
				usleep(500);
				send_pid(i, *pid);
				params_b.pids[i] = *pid;
			}
		}
		i++;
	}
	return (1);
}

int	exec_processes(unsigned int *pid, int status, sem_t *sem, int i)
{
	if (*pid != 0)
	{
		i = -1;
		pthread_create();
		if (params_b.n_times_to_eat == 9223372036854775807)
			waitpid(-1, &status, 0);
		else
		{
			while (++i < params_b.philo_n)
			{
				waitpid(params_b.pids[i], NULL, 0);
			}
		}
		kill_processes(SIGINT);
		free(params_b.pids);
		return (0);
	}
	else if (*pid == 0)
	{
		philosopher(sem);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	sem_t			*sem;
	sem_t			*write_sem;
	unsigned int	pid;
	int				i;
	int				status;

	status = 0;
	if (!get_args(argc, &argv[1]))
		return (1);
	sem = sem_open(SEM_NAME, O_CREAT, 0660, params_b.philo_n);
	write_sem = sem_open("write_sem", O_CREAT, 0660, 1);
	if (write_sem == SEM_FAILED)
		return (1);
	params_b.pids = malloc(sizeof(*params_b.pids) * params_b.philo_n);
	if (!params_b.pids)
		return (1);
	gettimeofday(&params_b.tv, NULL);
	i = 0;
	pid = 1;
	init_processes(i, &pid);
	if (!exec_processes(&pid, status, sem, i))
		return (1);
	return (0);
}
