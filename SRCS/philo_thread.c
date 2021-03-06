/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:19:56 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/10 16:35:47 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo(void *philo)
{
	t_philo	*cpy;

	cpy = (t_philo *)philo;
	if (cpy->number % 2 == 0)
		ft_usleep(cpy->param.eat_t / 10);
	while (1)
	{
		philo_eat((t_philo *)philo);
		philo_sleep((t_philo *)philo);
		philo_think((t_philo *)philo);
	}
	return (NULL);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_hist);
	hist_addback(&philo->hist, 2, get_time());
	pthread_mutex_unlock(&philo->mut_hist);
	ft_usleep(philo->param.sleep_t);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_hist);
	hist_addback(&philo->hist, 3, get_time());
	pthread_mutex_unlock(&philo->mut_hist);
}

void	philo_eat(t_philo *philo)
{
	//philo take fork
	pthread_mutex_lock(philo->right_f);
	//philo add to hist
	pthread_mutex_lock(&philo->mut_hist);
	hist_addback(&philo->hist, 0, get_time());
	pthread_mutex_unlock(&philo->mut_hist);
	//philo take other fork
	pthread_mutex_lock(philo->left_f);
	//philo add it to hist
	pthread_mutex_lock(&philo->mut_hist);
	hist_addback(&philo->hist, 0, get_time());
	pthread_mutex_unlock(&philo->mut_hist);
	//philo add meal to hist
	pthread_mutex_lock(&philo->mut_hist);
	hist_addback(&philo->hist, 1, get_time());
	pthread_mutex_unlock(&philo->mut_hist);
	//philo set meal and last meal and wait	
	pthread_mutex_lock(&philo->mut_meal_shit);
	philo->last_meal = get_time();
	philo->meal++;
	pthread_mutex_unlock(&philo->mut_meal_shit);
	ft_usleep(philo->param.eat_t);
	//philo left his forks
	pthread_mutex_unlock(philo->right_f);
	pthread_mutex_unlock(philo->left_f);
}
