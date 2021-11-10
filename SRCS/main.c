/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:03:52 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/10 12:02:28 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_philo(t_philo philo)
{
	printf("number = %d\n", philo.number);
	printf("right_f = %p\n", philo.right_f);
	printf("left_f = %p\n\n", philo.left_f);
}

int	main(int ac, char **av)
{
	t_data	data;
	int	i;

	i = 0;
	if (param_handler(&data.param, ac, av) == -1)
	{
		printf("Error\n");
		return (-1);
	}
	if (init_all(&data) == -1)
		return (-1);
	//while (i < data.param.nb_philo)
	//	print_philo(data.philo[i++]);
	thread_handler(&data);
	free_all(&data);
	return (0);
}
