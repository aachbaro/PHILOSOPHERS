/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:03:52 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/10 14:55:05 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (param_handler(&data.param, ac, av) == -1)
	{
		printf("Error\n");
		return (-1);
	}
	if (init_all(&data) == -1)
		return (-1);
	thread_handler(&data);
	free_all(&data);
	return (0);
}
