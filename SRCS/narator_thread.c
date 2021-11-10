/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   narator_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:47:38 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/10 15:00:29 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	*aff_death(int philo, int time)
{
	ft_putnbr(time);
	write(1, " ", 1);
	ft_putnbr(philo);
	write (1, " ", 1);
	ft_putstr("died\n");
	return (NULL);
}

int	check_end(t_data *data, int i)
{
	if (get_time() - data->philo[i].last_meal >= data->param.die_t)
	{
		aff_death(i, get_time() - data->start);
		return (-1);
	}
	if (data->philo[i].meal >= data->philo[i].param.simul_end)
		data->narator.philo_full++;
	if (data->narator.philo_full == data->param.nb_philo
		&& data->param.simul_end != -1)
		return (-1);
	return (0);
}

void	*narator(void *data)
{
	int		i;
	t_data	*cpy;

	cpy = (t_data *)data;
	while (1)
	{
		i = 0;
		cpy->narator.philo_full = 0;
		while (i < cpy->param.nb_philo)
		{
			pthread_mutex_lock(&cpy->philo[i].mut_hist);
			hist_write(&cpy->philo[i].hist, cpy->narator, i);
			pthread_mutex_unlock(&cpy->philo[i].mut_hist);
			if (check_end(cpy, i) == -1)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
