#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <errno.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <signal.h>
# define EAT 0
# define SLEEP 1
# define THINK 2
# define SEM_NAME "forks"
# define MALLOC_ERROR -100
typedef struct s_params_b{
	int				*pids;
	int				philo_n;
	long long int	time_to_die;
	long long int	time_to_eat;
	long long int	time_to_sleep;
	long long int	n_times_to_eat;
	struct timeval	tv;
	long long int	start_time;
	int				dead;
	int				index;
	int				message;
	int				g_count;
	int				num_count;
	int				to_ret;
}				t_params_b;
typedef struct s_data_b{
	long long int	state;
	long long int	ate;
	long long int	s_time;
	long long int	t_o_m;
	int				forks;
	int				index;
}					t_data_b;
t_params_b	params_b;

int						get_pid(void);
void					signal_handler(int signal);
int						nbr_size(long long int nbr);
char					*ft_convert_base(char *nbr);
char					*ft_strjoin(char *s1, char *s2);
int						get_args(int argc, char *argv[], t_params *pa);
long long int			timestamp(void);
unsigned long long int	ft_atoi(const char *str);
void					ft_putaction(t_params *pa, char *str, long long int index, int size);
void					drop_forks_odd_b(long long int index, \
long long int upper_ind);
char					*ft_putnbr_base(char *tab, long long int nb, \
char *base, int *index);
int						siz(long long int nbr);
int						take_fork(sem_t *sem, unsigned int index);
int						drop_forks(sem_t *sem, unsigned int index);
int						take(sem_t *sem, t_data_b *data_b);
int						eat_b(t_data_b *data_b, sem_t *sem);
int						sleep_think_b(t_data_b *data_b, sem_t *sem);
int						check_dead_b(sem_t *sem, long long int index, \
long long int t_o_m, int forks);
void					binary(char *str, unsigned int pid);
void					send_message(unsigned int pid, char *str);
size_t					count_digits(unsigned int n);
char					*ft_itoa(unsigned int n);
int						send_pid(unsigned int index, unsigned int pid);
void					ft_myputnbr(unsigned int n, char *arr, int *c);
void					kill_processes(int signal);

#endif
