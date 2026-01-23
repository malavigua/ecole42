/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.basic1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:34:49 by malmany           #+#    #+#             */
/*   Updated: 2026/01/22 21:14:44 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"

t_stack_node	*ft_stack_node_new(int value)
{
	t_stack_node	*res;

	res = malloc(sizeof(t_stack_node));
	if (!res)
		return (NULL);
	res->value = value;
	res->index = 0;
	res->push_cost = 0;
	res->is_above_median = false;
	res->is_cheapest = false;
	res->target_node = NULL;
	res->prev = NULL;
	res->next = NULL;
	return (res);
}

void	ft_stack_add_front(t_stack_node **st, t_stack_node *new)
{
	if (!st || !new)
		return ;
	new->prev = NULL;
	new->next = *st;
	if (*st)
		(*st)->prev = new;
	*st = new;
}

int	ft_stack_size(t_stack_node *st)
{
	int	res;

	res = 0;
	while (st)
	{
		res++;
		st = st->next;
	}
	return (res);
}

t_stack_node	*ft_stack_last(t_stack_node *st)
{
	if (!st)
		return (NULL);
	while (st->next)
		st = st->next;
	return (st);
}

void	ft_stack_add_back(t_stack_node **st, t_stack_node *new)
{
	t_stack_node	*last;

	if (!st || !new)
		return ;
	new->next = NULL;
	if (*st == NULL)
	{
		new->prev = NULL;
		*st = new;
		return ;
	}
	last = ft_stack_last(*st);
	last->next = new;
	new->prev = last;
}
