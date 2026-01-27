/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_sort_stack1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:56:18 by malmany           #+#    #+#             */
/*   Updated: 2026/01/27 12:45:22 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_set_index_and_above_median(t_stack_node *st)
{
	int	i;
	int	median;

	if (!st)
		return ;
	i = 0;
	median = ft_stack_size(st) / 2;
	while (st)
	{
		st->index = i;
		if (i <= median)
			st->is_above_median = true;
		else
			st->is_above_median = false;
		i++;
		st = st->next;
	}
}

// target  is the bigger less of the node a in b
// or the Maximum if there is no value less than it
void	ft_set_target_a_from_b(t_stack_node *a, t_stack_node *b)
{
	long				bigger_less;
	t_stack_node		*target;
	t_stack_node		*cb;

	if (!a || !b)
		return ;
	while (a)
	{
		bigger_less = LONG_MIN;
		cb = b;
		while (cb)
		{
			if (cb->value < a->value && cb->value > bigger_less)
			{
				bigger_less = cb->value;
				target = cb;
			}
			cb = cb->next;
		}
		if (bigger_less == LONG_MIN)
			a->target_node = ft_stack_get_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

int	ft_get_cost(t_stack_node *st, int size_st)
{
	int	cost;

	if (st->is_above_median)
		cost = st->index;
	else
		cost = size_st - st->index;
	return (cost);
}

int	get_push_cost(t_stack_node *st1, int size_st1, int size_st2)
{
	int	cost_st1;
	int	cost_target_node;

	cost_st1 = ft_get_cost(st1, size_st1);
	cost_target_node = ft_get_cost(st1->target_node, size_st2);
	if (st1->is_above_median == st1->target_node->is_above_median)
	{
		if (cost_st1 > cost_target_node)
			return (cost_st1);
		return (cost_target_node);
	}
	return (cost_st1 + cost_target_node);
}

void	ft_set_push_cost(t_stack_node *st1, t_stack_node *st2)
{
	int	size_st1;
	int	size_st2;

	size_st1 = ft_stack_size(st1);
	size_st2 = ft_stack_size(st2);
	while (st1)
	{
		st1->push_cost = get_push_cost(st1, size_st1, size_st2);
		st1 = st1->next;
	}
}
