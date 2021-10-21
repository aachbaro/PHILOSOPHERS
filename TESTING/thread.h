#ifndef	THREAD_H
# define THREAD_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct		s_client
{
	pthread_t		thrd;
	int				pocket;
	int				number;
	int				is_ready;
}					t_client;

typedef struct		s_shop
{
	pthread_t		thrd;
	int				stock;
	pthread_mutex_t	locker;
}					t_shop;

typedef	struct		s_scene
{
	t_shop			shop;
	t_client		*clients;
	int				nb_cli;
}					t_scene;

int		rand_int(int max);
int		init_scene(t_scene *scene, int ini_stock, int nb_clients);

#endif
