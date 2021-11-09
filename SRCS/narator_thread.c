/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   narator_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:47:38 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/09 17:52:30 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*aff_death(int philo, int time)
{
	ft_putnbr(time);
	write(1, " ", 1);
	ft_putnbr(philo);
	write (1, " ", 1);
	ft_putstr("died\n");
	return (NULL);
}

void	*narator(void *data)
{
	int				i;
	struct timeval	time;
	t_data			*cpy;

	cpy = (t_data *)data;
	while (1)
	{
		i = 0;
		gettimeofday(&time, NULL);
		while (i < cpy->param.nb_philo)
		{
		//	if (time.tv_usec - cpy->philo[i].last_meal > cpy->param.die_t)
		//		return (aff_death(i, time.tv_usec - cpy->start));
		//	hist_write(&cpy->philo[i].hist, cpy->narator, i);
			i++;
		}
	}
	return (NULL);
}
