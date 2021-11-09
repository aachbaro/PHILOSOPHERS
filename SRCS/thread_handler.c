/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_heandler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:17:20 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/09 17:51:40 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	thread_handler(t_data *data)
{
	int	i;

	i = 0;
	pthread_create(&data->narator.thread, NULL, &narator, data);
	while (i < data->param.nb_philo)
	{
		pthread_create(&data->philo[i].thread, NULL, &philo, &data->philo[i]);
		i++;
	}
	pthread_join(data->narator.thread, NULL);
}
