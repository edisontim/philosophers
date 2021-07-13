/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 10:58:09 by tedison           #+#    #+#             */
/*   Updated: 2021/06/30 11:33:42 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_all(t_params *pa, int forks, int philos, int philo_d_a)
{
	if (forks != 0)
		free(pa->mtex_fo);
	if (philos != 0)
		free(pa->philos);
	if (philo_d_a != 0)
		free(pa->philo_d_a);
	return (0);
}

int	clean_exit(t_params *pa)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&pa->write_lock);
	pthread_mutex_destroy(&pa->check_state);
	while (++i < pa->philo_n)
		pthread_mutex_destroy(&pa->mtex_fo[i]);
	free_all(pa, 1, 1, 1);
	return (0);
}

int	var_init(int argc, char *argv[], t_params *pa)
{
	memset((void *) pa, 0, sizeof(t_params));
	if (!get_args(argc, &argv[1], pa))
		return (0);
	gettimeofday(&pa->tv, NULL);
	pa->mtex_fo = malloc(sizeof(pthread_mutex_t) * pa->philo_n);
	if (!pa->mtex_fo)
		return (0);
	pa->philos = malloc(sizeof(pthread_t) * pa->philo_n);
	if (!pa->philos)
		return (free_all(pa, 1, 0, 0));
	pa->philo_d_a = malloc(sizeof(t_philo_d) * pa->philo_n);
	if (!pa->philo_d_a)
		return (free_all(pa, 1, 1, 0));
	return (1);
}

int	mutex_thread_init(t_params *pa)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&pa->write_lock, NULL))
		return (free_all(pa, 1, 1, 1));
	if (pthread_mutex_init(&pa->check_state, NULL))
		return (free_all(pa, 1, 1, 1));
	pa->stop = 0;
	while (++i < pa->philo_n)
	{
		pthread_mutex_init(&pa->mtex_fo[i], NULL);
		pa->philo_d_a[i].state = EAT;
		pa->philo_d_a[i].limit = 0;
		pa->philo_d_a[i].s_time = 0;
		pa->philo_d_a[i].ate = 0;
	}
	i = -1;
	while (++i < pa->philo_n)
	{
		pthread_create(&pa->philos[i], NULL, ft_philosopher, (void *)pa);
		usleep(50);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	long long int	i;
	t_params		pa;

	i = -1;
	if (argc != 6 && argc != 5)
		return (1);
	if (argc == 0)
		return (1);
	if (!var_init(argc, argv, &pa))
		return (1);
	if (!mutex_thread_init(&pa))
		return (1);
	pthread_create(&pa.time_thread, NULL, time_monitor, (void *)&pa);
	if (pa.n_times_to_eat != 9223372036854775807L)
	{
		while (++i < pa.philo_n)
			pthread_join(pa.philos[i], NULL);
	}
	pthread_join(pa.time_thread, NULL);
	clean_exit(&pa);
	return (0);
}
