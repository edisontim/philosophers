#include "philo_bonus.h"

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		params_b.message += (0 << params_b.g_count);
		params_b.g_count--;
	}
	if (signal == SIGUSR2)
	{
		params_b.message += (1 << params_b.g_count);
		params_b.g_count--;
	}
	if (signal == SIGINT)
	{
		exit(1);
	}
	if (params_b.g_count == -1)
	{
		params_b.to_ret += params_b.message;
		params_b.g_count = 7;
		params_b.message = 0;
		params_b.num_count--;
		return ;
	}
}

int	get_pid(void)
{
	params_b.to_ret = 0;
	params_b.g_count = 7;
	params_b.message = 0;
	params_b.num_count = 1;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		if (params_b.num_count == 0)
			return (params_b.to_ret);
		pause();
	}
}
