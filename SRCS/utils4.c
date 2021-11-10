/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:55:11 by aachbaro          #+#    #+#             */
/*   Updated: 2021/11/10 14:58:52 by aachbaro         ###   ########.fr       */
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
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->type = type;
	new->time = time;
	new->next = NULL;
	ptr = *start;
	if (*start == NULL)
		*start = new;
	else
	{
		ptr = hist_last(*start);
		ptr->next = new;
	}
}

void	ft_putnbr(int nb)
{
	long	cpy;

	cpy = nb;
	if (cpy < 0)
	{
		write(1, "-", 1);
		cpy = -cpy;
	}
	if (cpy > 9)
		ft_putnbr(cpy / 10);
	ft_putchar(cpy % 10 + '0');
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

void	hist_write(t_list **ptr, t_narator nar, int philo)
{
	t_list	*cpy;

	while (*ptr)
	{
		ft_putnbr((*ptr)->time - nar.start);
		write(1, " ", 1);
		ft_putnbr(philo);
		write(1, " ", 1);
		if ((*ptr)->type == 0)
			ft_putstr("has taken a fork\n");
		else if ((*ptr)->type == 1)
			ft_putstr("is eating\n");
		else if ((*ptr)->type == 2)
			ft_putstr("is sleeping\n");
		else if ((*ptr)->type == 3)
			ft_putstr("is thinking\n");
		cpy = (*ptr)->next;
		free(*ptr);
		*ptr = cpy;
	}
}
