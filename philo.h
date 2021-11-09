#ifndef	THREAD_H
# define THREAD_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct	s_list
{
	int		type;
	int		time;
	struct s_list	*next;
}				t_list;

typedef	struct	s_param
{
	int			nb_philo;
	int			die_t;
	int			eat_t;
	int			sleep_t;
	int			simul_end;
}				t_param;

typedef struct		s_philo
{
	int					number;
	int					meal;
	int					last_meal;
	pthread_t			thread;
	pthread_mutex_t		*left_f;
	pthread_mutex_t		*right_f;
	t_param				param;
	t_list				*hist;
}			t_philo;

typedef struct	s_narator
{
	pthread_t	thread;
	int			start;
}		t_narator;

typedef struct	s_data
{
	t_param		param;
	t_philo		*philo;
	pthread_mutex_t	*forks;
	t_narator	narator;
	int		start;
}				t_data;

int	ft_atoi(const char *str);
char	*ft_itoa(int n);
int	ft_isdigit(int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	**ft_split(const char *str, char c); 
int	param_handler(t_param *param, int ac, char **av);
int	check_digit(char *str);
int 	check_param(int ac, char **av);
int	init_philo(t_data *data);
int	init_forks(t_data *data);
void	link_forks_to_philo(t_data *data);
int	init_narator(t_data *data);
int	init_all(t_data *data);
void	free_all(t_data *data);
void	ft_usleep(int usec);
void	hist_addback(t_list **start, int type, int time);
void	ft_putnbr(int nb);
void	ft_putstr(char *s);
void	hist_write(t_list **start, t_narator nar, int philo);
void	*philo(void *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	*narator(void *data);
void	thread_handler(t_data *data);

#endif
