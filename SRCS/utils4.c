/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:55:11 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/09 14:04:20 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	hist_addback(t_list **start, int type, int time)
{
	t_list	*new;
	t_list	*cpy;

	cpy = *start;
	if (cpy)
	{
		while (cpy->next)
			cpy = cpy->next;
		cpy->next = new;
	}
	else
		cpy = new;
	new->type = type;
	new->time = time;
	new->next = NULL;
}
