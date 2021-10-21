#ifndef	THREAD_H
# define THREAD_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef	struct	s_param
{
	int			nb_philo;
	int			die_t;
	int			eat_t;
	int			sleep_t;
	int			simul_end;
}				t_param;

typedef struct	s_data
{
	t_param		param;
}				t_data;

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	**ft_split(const char *str, char c); 
int		param_handler(t_param *param, int ac, char **av);
int		check_digit(char *str);
int 	check_param(int ac, char **av);

#endif
