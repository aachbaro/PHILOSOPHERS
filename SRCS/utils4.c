/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:55:11 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/09 17:40:33 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_list	*hist_last(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	if (ptr)
		while (ptr->next)
			ptr = ptr->next;
	return (ptr);
}

void	hist_addback(t_list **start, int type, int time)
{
	t_list	*ptr;
	t_list	new;

	new.type = type;
	new.time = time;
	new.next = NULL;
	if (*start == NULL)
		*start = &new;
	else
	{
		ptr = hist_last(*start);
		ptr->next = &new;
	}
}

void	ft_putnbr(int nb)
{
	long	cpy;

	cpy = nb;
	if (!nb)
		write(1, "0", 1);
	if (cpy < 0)
	{
		write(1, "-", 1);
		cpy = -cpy;
	}
	if (cpy > 9)
		ft_putnbr(cpy / 10);
	write(1, (char *)(cpy % 10 + '0'), 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	hist_write(t_list **start, t_narator nar, int philo)
{
	t_list *cpy;

	cpy = *start;
	while (cpy)
	{
		ft_putnbr(cpy->time - nar.start);
		write(1, " ", 1);
		ft_putnbr(philo);
		write(1, " ", 1);
		if (cpy->type == 0)
			ft_putstr("has taken a fork\n");
		else if (cpy->type == 1)
			ft_putstr("is eating\n");
		else if (cpy->type == 2)
			ft_putstr("is sleeping\n");
		else if (cpy->type == 3)
			ft_putstr("is thinking\n");
		cpy = cpy->next;
	}
}
