/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_sort_stack1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:56:18 by malmany           #+#    #+#             */
/*   Updated: 2026/01/23 10:34:47 by malmany          ###   ########.fr       */
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

// target  is the lowest greater of the node b in a
// or the Minimum if there is no value greater than it
void	ft_set_target_b_from_a(t_stack_node *a, t_stack_node *b)
{
	long				smaller_greater;
	t_stack_node		*target;
	t_stack_node		*ca;

	if (!a || !b)
		return ;
	while (b)
	{
		smaller_greater = LONG_MAX;
		ca = a;
		while (ca)
		{
			if (ca->value > b->value && ca->value < smaller_greater)
			{
				smaller_greater = ca->value;
				target = ca;
			}
			ca = ca->next;
		}
		if (smaller_greater == LONG_MAX)
			b->target_node = ft_stack_get_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

// if is_above_median number of rotate needed
// else number of reverse rotate needed
void	ft_set_push_cost(t_stack_node *st1, t_stack_node *st2)
{
	int	size_st1;
	int	size_st2;

	size_st1 = ft_stack_size(st1);
	size_st2 = ft_stack_size(st2);
	while (st1)
	{
		if (st1->is_above_median)
			st1->push_cost = st1->index;
		else
			st1->push_cost = size_st1 - st1->index;
		if (st1->target_node->is_above_median)
			st1->push_cost += st1->target_node->index;
		else
			st1->push_cost += size_st2 - st1->target_node->index;
		st1 = st1->next;
	}
}
