#include "philo.h"

void	put_string_mutexed(t_params *pa, int size, char *final_str, int len)
{
	if (!pa->stop)
	{
		pthread_mutex_lock(&pa->write_lock);
		if (size == 6)
			pa->stop = 1;
		write(1, final_str, len);
		pthread_mutex_unlock(&pa->write_lock);
	}
}

void	ft_putaction(t_params *pa, char *str, long long int index, int size)
{
	char			*final_str;
	int				i;
	long long int	time;
	int				len;

	time = ts(pa) - pa->start_time;
	index++;
	len = nbr_size(index) + 1 + nbr_size(time) + 1 + size + 1;
	final_str = malloc(sizeof(char) * (nbr_size(index) + nbr_size(time) + 3));
	final_str[nbr_size(time)] = ' ';
	final_str[nbr_size(time) + nbr_size(index) + 2] = 0;
	final_str[nbr_size(time) + nbr_size(index) + 1] = ' ';
	i = 0;
	ft_putnbr_base(final_str, time, "0123456789", &i);
	i = nbr_size(time) + 1;
	ft_putnbr_base(final_str, index, "0123456789", &i);
	final_str = ft_strjoin(final_str, str);
	if (!final_str)
		return ;
	put_string_mutexed(pa, size, final_str, len);
	free(final_str);
}

long long int	ts(t_params *pa)
{
	gettimeofday(&pa->tv, NULL);
	return (pa->tv.tv_sec * 1000 + pa->tv.tv_usec / 1000);
}
