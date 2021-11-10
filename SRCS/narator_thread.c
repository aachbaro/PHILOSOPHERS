/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   narator_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:47:38 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/10 13:38:13 by aachbaro         ###   ########.fr       */
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
	t_data			*cpy;

	cpy = (t_data *)data;
	while (1)
	{
		i = 0;
		while (i < cpy->param.nb_philo)
		{
			if (get_time() - cpy->philo[i].last_meal > cpy->param.die_t)
				return (aff_death(i, get_time() - cpy->start));
			pthread_mutex_lock(&cpy->philo[i].mut_hist);
			hist_write(&cpy->philo[i].hist, cpy->narator, i);
			pthread_mutex_unlock(&cpy->philo[i].mut_hist);
			i++;
		}
	}
	return (NULL);
}
