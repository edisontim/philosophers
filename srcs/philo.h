#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <errno.h>
# include <semaphore.h>
# define EAT 0
# define SLEEP 1
# define THINK 2
# define EATING 3

typedef struct s_philo_d{
	int			state;
	long long	limit;
	long long	t_o_m;
	int			ate;
}				t_philo_d;

typedef struct s_data{
	long long	index;
	int			forks;
	int			ate;
	long long	n_times_to_eat;
	long long	sleep_at;
	long long	t_o_m;
	long long	t_t_s;
	long long	t_t_e;
	long long	philo_n;
}				t_data;

typedef struct s_params{
	int				philo_n;
	long long		time_to_die;
	long long		t_t_e;
	long long		t_t_s;
	long long		n_times_to_eat;
	struct timeval	tv;
	pthread_mutex_t	*mtex_fo;
	pthread_t		*philos;
	pthread_mutex_t	write_lock;
	long long		start_time;
	int				ate_enough;
	pthread_mutex_t	check_state;
	t_philo_d		*philo_d_a;
	pthread_mutex_t	check_death;
	pthread_t		monitor;
	int				dead;
}				t_params;
int						nbr_size(long long nbr);
char					*ft_strjoin(char *s1, char *s2);
int						get_args(int argc, char *argv[], t_params *pa);
long long				ts(t_params *pa);
unsigned long long		ft_atoi(const char *str);
int						ft_putaction(t_params *pa, char *str, \
long long index, int size);
int						check_dead(t_params *pa, long long index);
int						take_forks(t_params *pa, t_data *data, int index);
int						drop_forks(t_params *pa, long long index, t_data *data);
int						do_philo_stuff(t_params *pa, t_data *data);
void					*ft_philosopher(void *p_data);
void					ft_putnbr_base(long long nb, char *base);
void					*time_monitor(void *p_data);

#endif
