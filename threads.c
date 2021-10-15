/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:31:54 by aachbaro          #+#    #+#             */
/*   Updated: 2021/10/15 17:29:15 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct		s_client
{
	pthread_t		being;
	int				number;
	int				pocket;
}					t_client;

typedef struct		s_shop
{
	pthread_t		place;
	int				stock;
	int				money;
	int				prev_money;
	pthread_mutex_t	me_stock;
	pthread_mutex_t	me_money;
	t_client		*client;
	int				nb_cli;
}					t_shop;

int		get_rand(int max)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_usec % max);
}

void	game_state(t_shop shop)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	system("clear");
	printf("\nADAM :\nMONEY : %d\nSTOCK : ", shop.money);
	while (i < shop.stock)
	{
		printf("0");
		i++;
	}
	printf("\n\n");
	i = 0;
	while (i < shop.nb_cli)
	{
		printf("CLIENT %d : ", i);
		j = 0;
		while (j < shop.client[i].pocket)
		{
			printf("0");
			j++;
		}
		printf("\n");
		i++;
	}
}

void	*crackos(void *shop)
{
	int	want_some;
	t_shop	*cpy;

	want_some = 0;
	cpy = (t_shop *)shop;
	while (1)
	{
		pthread_mutex_lock(&cpy->me_stock);
		pthread_mutex_lock(&cpy->me_money);
		want_some = get_rand(5) + 1;
		if (want_some <= cpy->stock)
		{
			cpy->stock -= want_some;
			cpy->money += want_some * 10;
			cpy->client[cpy->client->number].pocket += want_some;
			usleep(50000);
		}
		else
		{
			want_some = cpy->stock;
			cpy->stock -= want_some;
			cpy->money += want_some * 10;
			cpy->client[cpy->client->number].pocket += want_some;
			usleep(50000);
		}
		pthread_mutex_unlock(&cpy->me_stock);
		pthread_mutex_unlock(&cpy->me_money);
	}
	return (NULL);
}

void	*adamdma(void *shop)
{
	t_shop	*cpy;
	int		prev_money;

	cpy = (t_shop *)shop;
	while (1)
	{
		//pthread_mutex_lock(&cpy->me_stock);
		//pthread_mutex_lock(&cpy->me_money);
		if (prev_money != cpy->money)
		{
			game_state(*cpy);
			//usleep(50000);
		}
		else if (cpy->stock == 0)
		{
			game_state(*cpy);
			return (NULL);
		}
		prev_money = cpy->money;
		//pthread_mutex_unlock(&cpy->me_stock);
		//pthread_mutex_unlock(&cpy->me_money);
	}
}

int	main(int ac, char **av)
{
	t_shop	adam;
	int		i;

	adam.stock = atoi(av[1]);
	pthread_mutex_init(&adam.me_stock, NULL);
	adam.money = 0;
	pthread_mutex_init(&adam.me_money, NULL);
	adam.nb_cli = atoi(av[2]);
	adam.client = malloc(sizeof(pthread_t) * adam.nb_cli);
	i = 0;
	pthread_create(&adam.place, NULL, &adamdma, &adam);
	while (i < adam.nb_cli)
	{
		adam.client[i].pocket = 0;
		adam.client[i].number = i;
		pthread_create(&adam.client[i].being, NULL, &crackos, &adam);
		i++;
	}
	i = 0;
//	while (i < adam.nb_cli)
//	{
//		pthread_join(adam.client[i].being, NULL);
//		i++;
//	}
	pthread_join(adam.place, NULL);
	return (0);
}
