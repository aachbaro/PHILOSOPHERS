/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:03:52 by aachbaro          #+#    #+#             */
/*   Updated: 2021/10/21 13:40:15 by aachbaro         ###   ########.fr       */
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
	printf("philosophes = %d\ndie = %d\neat = %d\nsleep = %d\nend = %d\n",
			data.param.nb_philo, data.param.die_t, data.param.eat_t, data.param.sleep_t, data.param.simul_end);
}
