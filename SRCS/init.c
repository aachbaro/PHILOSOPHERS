/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:04:20 by aachbaro          #+#    #+#             */
/*   Updated: 2021/10/19 16:04:59 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../thread.h"

int	init_scene(t_scene *scene, int ini_stock, int nb_clients)
{
	int	i;

	i = 0;
	scene->shop.stock = ini_stock;
	pthread_mutex_init(&scene->shop.locker, NULL);
	scene->nb_cli = nb_clients;
	scene->clients = malloc(sizeof(t_client) * nb_clients);
	if (!scene->clients)
		return (-1);
	while (i < nb_clients)
	{
		scene->clients[i].pocket = 0;
		scene->clients[i].number = i;
		scene->clients[i].is_ready = 0;
		i++;
	}
	return (0);
}

void	thread_launcher(t_scene *scene)
{
	int	i;

	i = 0;
	pthread_create(&scene->shop.thrd, NULL, &seller, scene);
	while (i < scene->nb_cli)
	{
		pthread_create(&scene->client[i].thrd, NULL, &ienclar, scene);
	}
}
