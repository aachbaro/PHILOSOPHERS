/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:19:56 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/09 14:04:22 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->param.nb_philo);
	if (!data->philo)
		return (-1);
	while (i < data->param.nb_philo)
	{
		data->philo[i].number = i;
		data->philo.ate = 0;
		data->philo.hist = NULL;
		data->philo[i].param = data->param;
		i++;
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->param.nb_philo);
	if (!data->forks)
		return (-1);
	while (i < data->param.nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

void	link_forks_to_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->param.nb_philo - 1)
	{
		data->philo[i].right_f = &data->forks[i];
		data->philo[i].left_f = &data->forks[i + 1];
		i++;
	}
	data->philo[i].right_f = &data->forks[i];
	data->philo[i].left_f = &data->forks[0];
}

int	init_narator(t_data *data)
{
	int	i;

	i = 0;
	data->narator.old_phi = data->philo;
	data->narator.start = data->start;
	data->narator.ate_n_time = malloc(sizeof(int) * data->param.nb_philo);
	if (!data->narator.ate_n_time)
		return (-1);
	while (i < data->param.nb_philo)
		data->narator.ate_n_time[i++] = 0;
	return (0);
}

int	init_all(t_data *data)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	data->start = time.tv_usec;
	if (init_philo(data) == -1)
		return (-1);
	if (init_forks(data) == -1)
	{
		free(data->philo);
		return (-1);
	}
	if (init_narator(data) == -1)
	{
		free(data->philo);
		free(data->forks);
		return (-1);
	}
	link_forks_to_philo(data);
	return (0);
}
