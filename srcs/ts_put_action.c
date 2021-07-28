#include "philo.h"

// static int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while(str[i])
// 		i++;
// 	return (i);
// }

int	ft_putaction(t_params *pa, char *str, long long int index, int size)
{
	long long int	time;

	if (size == 6)
		pa->dead = 1;
	pthread_mutex_lock(&pa->write_lock);
	time = ts(pa) - pa->start_time;
	index++;
	ft_putnbr_base(time, "0123456789");
	write(1, " ", 1);
	ft_putnbr_base(index, "0123456789");
	write(1, " ", 1);
	write(1, str, size);
	pthread_mutex_unlock(&pa->write_lock);
	return (1);
}

long long int	ts(t_params *pa)
{
	gettimeofday(&pa->tv, NULL);
	return (pa->tv.tv_sec * 1000 + pa->tv.tv_usec / 1000);
}
