/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:19:56 by aachbaro          #+#    #+#             */
/*   Updated: 2021/10/21 12:30:20 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo(void *philo)
{
	while (1)
	{

	}
}

void	philo_sleep(t_philo *philo)
{
	int	i;
	
	philo->is_sleeping = 1;
	ft_usleep(philo->param.sleep_t);
	philo->is_sleeping = 0;
}
