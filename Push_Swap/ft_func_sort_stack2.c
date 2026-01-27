/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_sort_stack2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:56:18 by malmany           #+#    #+#             */
/*   Updated: 2026/01/23 10:55:38 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_set_cheapest(t_stack_node *st)
{
	long				less_cost;
	t_stack_node		*cheapest_node;

	if (!st)
		return ;
	less_cost = LONG_MAX;
	while (st)
	{
		if (st->push_cost < less_cost)
		{
			less_cost = st->push_cost;
			cheapest_node = st;
		}
		st = st->next;
	}
	cheapest_node->is_cheapest = true;
}

t_stack_node	*ft_get_cheapest(t_stack_node *st)
{
	while (st)
	{
		if (st->is_cheapest)
			return (st);
		st = st->next;
	}
	return (NULL);
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

void	ft_verify_and_set_top_before_push(t_stack_node **st,
		t_stack_node *to_be_top, char stack_name)
{
	if (!st || !*st || *st == to_be_top)
		return ;
	if (to_be_top->is_above_median)
	{
		while ((*st && (*st) != to_be_top))
			ft_stack_rotate(st, stack_name, true);
		return ;
	}
	while ((*st && (*st) != to_be_top))
		ft_stack_reverse_rotate(st, stack_name, true);
}

void	ft_verify_and_set_stacks(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	ft_verify_and_set_top_before_push(a, cheapest_node, 'a');
	ft_verify_and_set_top_before_push(b, cheapest_node->target_node, 'b');
}
