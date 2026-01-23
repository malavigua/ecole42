/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_sort_stack3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:56:18 by malmany           #+#    #+#             */
/*   Updated: 2026/01/23 11:43:17 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_move_cheapest_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = ft_get_cheapest(*a);
	if (!a || !b || !*a || !cheapest_node)
		return ;
	if (cheapest_node->is_above_median
		&& cheapest_node->target_node->is_above_median)
	{
		while ((*a && (*a) != cheapest_node)
			&& (*b && (*b) != cheapest_node->target_node))
			ft_stack_rotate_both(a, b, true);
		ft_set_index_and_above_median(*a);
		ft_set_index_and_above_median(*b);
	}
	else if (!(cheapest_node->is_above_median)
		&& !(cheapest_node->target_node->is_above_median))
	{
		while ((*a && (*a) != cheapest_node)
			&& (*b && (*b) != cheapest_node->target_node))
			ft_stack_reverse_rotate_both(a, b, true);
		ft_set_index_and_above_median(*a);
		ft_set_index_and_above_median(*b);
	}
	ft_verify_and_set_stacks(a, b, cheapest_node);
	ft_stack_push(a, b, 'b', true);
}

void	ft_set_a_before_push_to_b(t_stack_node **a, t_stack_node **b)
{
	ft_set_index_and_above_median(*a);
	ft_set_index_and_above_median(*b);
	ft_set_target_a_from_b(*a, *b);
	ft_set_push_cost(*a, *b);
	ft_set_cheapest(*a);
}

void	ft_set_min_at_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = ft_stack_get_min(*a);
	if (min->is_above_median)
		while ((*a)->value != min->value)
			ft_stack_rotate(a, 'a', true);
	else
		while ((*a)->value != min->value)
			ft_stack_reverse_rotate(a, 'a', true);
}
