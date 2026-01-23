/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.basic2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:34:49 by malmany           #+#    #+#             */
/*   Updated: 2026/01/22 21:22:23 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"

void	ft_stack_delone(t_stack_node *st)
{
	if (!st)
		return ;
	free(st);
}

void	ft_stack_clear(t_stack_node **st)
{
	t_stack_node	*tmp;

	if (!st)
		return ;
	while (*st)
	{
		tmp = (*st)->next;
		ft_stack_delone(*st);
		*st = tmp;
	}
}

t_stack_node	*ft_stack_new(int *tab, int size)
{
	int				i;
	t_stack_node	*res;
	t_stack_node	*n1;

	if (!tab || size == 0)
		return (NULL);
	res = NULL;
	i = 0;
	while (i < size)
	{
		n1 = ft_stack_node_new(tab[i]);
		if (!n1)
		{
			ft_stack_clear(&res);
			free(tab);
			return (NULL);
		}
		ft_stack_add_back(&res, n1);
		i++;
	}
	free(tab);
	return (res);
}

bool	ft_stack_is_sorted_asc(t_stack_node *st)
{
	if (!st || !st->next)
		return (true);
	while (st->next)
	{
		if (st->value > st->next->value)
			return (false);
		st = st->next;
	}
	return (true);
}
