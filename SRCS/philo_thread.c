/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:19:56 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/09 18:04:37 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo(void *philo)
{

	while (1)
	{
		philo_sleep((t_philo *)philo);
		philo_think((t_philo *)philo);
	}
	return (NULL);
}

void	philo_sleep(t_philo *philo)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	printf("\nOK\n");
	hist_addback(&philo->hist, 2, time.tv_usec);
	usleep(philo->param.sleep_t);
}

void	philo_think(t_philo *philo)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	hist_addback(&philo->hist, 3, time.tv_usec);
}
