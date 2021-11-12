/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:19:56 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/10 16:41:25 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_all(t_data *data)
{
	int		i;
	t_list	*cpy;

	i = 0;
	while (i < data->param.nb_philo)
	{
		while (data->philo[i].hist)
		{
			cpy = data->philo[i].hist->next;
			free(data->philo[i].hist);
			data->philo[i].hist = cpy;
		}
		pthread_mutex_destroy(&data->philo[i].mut_hist);
		pthread_mutex_destroy(&data->philo[i].mut_meal_shit);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	free(data->philo);
}

long int	get_time(void)
{
	struct timeval	time;
	int				ret;

	gettimeofday(&time, NULL);
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

void	ft_usleep(long int usec)
{
	long int	start;

	start = get_time();
	while (get_time() - start < usec)
		usleep(usec / 10);
}
