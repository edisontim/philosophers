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

typedef struct s_philo_d{
	int				state;
	long long int	limit;
	long long int	t_o_m;
	long long int	s_time;
	int				ate;
}				t_philo_d;

typedef struct s_data{
	long long int	index;
	long long int	index_mod;
	long long int	upper_ind;
	int				forks;
}				t_data;

typedef struct s_params{
	int				philo_n;
	long long int	time_to_die;
	long long int	t_t_e;
	long long int	t_t_s;
	long long int	n_times_to_eat;
	struct timeval	tv;
	pthread_mutex_t	*mtex_fo;
	pthread_t		*philos;
	pthread_mutex_t	write_lock;
	long long int	start_time;
	int				ate_enough;
	pthread_mutex_t	check_state;
	int				dead;
	t_philo_d		*philo_d_a;
	int				stop;
	pthread_t		time_thread;
}				t_params;
int						nbr_size(long long int nbr);
char					*ft_strjoin(char *s1, char *s2);
int						get_args(int argc, char *argv[], t_params *pa);
long long int			ts(t_params *pa);
unsigned long long int	ft_atoi(const char *str);
void					ft_putaction(t_params *pa, char *str, \
long long int index, int size);
int						check_dead(t_params *pa, long long int index);
int						take_forks_even(t_params *pa, long long int index, \
long long int upper_ind, int *forks);
int						take_forks_odd(t_params *pa, long long int index, \
long long int upper_ind, int *forks);
void					drop_forks_even(t_params *pa, long long int index, \
long long int upper_ind);
void					drop_forks_odd(t_params *pa, long long int index, \
long long int upper_ind);
int						eat(t_params *pa, t_data *data);
int						sleep_think(t_params *pa, t_data *data);
int						do_philo_stuff(t_params *pa, t_data *data);
void					*ft_philosopher(void *p_data);
char					*ft_putnbr_base(char *tab, long long int nb, \
char *base, int *index);
void					*time_monitor(void *p_data);

#endif
