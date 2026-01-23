/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort_min_max.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:56:18 by malmany           #+#    #+#             */
/*   Updated: 2026/01/23 11:35:09 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack_node	*ft_stack_get_max(t_stack_node *st)
{
	int				max;
	t_stack_node	*max_node;

	if (!st)
		return (NULL);
	max = st->value;
	max_node = st;
	while (st)
	{
		if (st->value > max)
		{
			max = st->value;
			max_node = st;
		}
		st = st->next;
	}
	return (max_node);
}

t_stack_node	*ft_stack_get_min(t_stack_node *st)
{
	int				min;
	t_stack_node	*min_node;

	if (!st)
		return (NULL);
	min = st->value;
	min_node = st;
	while (st)
	{
		if (st->value < min)
		{
			min = st->value;
			min_node = st;
		}
		st = st->next;
	}
	return (min_node);
}

void	ft_stack_sort_three(t_stack_node **st)
{
	if (!st || !*st || ft_stack_size(*st) != 3 || ft_stack_is_sorted_asc(*st))
		return ;
	if ((*st)->value == ft_stack_get_max(*st)->value)
		ft_stack_rotate(st, 'a', true);
	else if ((*st)->next->value == ft_stack_get_max(*st)->value)
		ft_stack_reverse_rotate(st, 'a', true);
	if (!ft_stack_is_sorted_asc(*st))
		ft_stack_swap(*st, 'a', true);
}

void	ft_stack_sort_size_greater_three(t_stack_node **a, t_stack_node **b)
{
	int			stack_size;

	if (!a || !*a || ft_stack_size(*a) <= 3 || ft_stack_is_sorted_asc(*a))
		return ;
	stack_size = ft_stack_size(*a);
	if (stack_size-- > 3 && !ft_stack_is_sorted_asc(*a))
		ft_stack_push(a, b, 'b', true);
	if (stack_size-- > 3 && !ft_stack_is_sorted_asc(*a))
		ft_stack_push(a, b, 'b', true);
	while (stack_size-- > 3 && !ft_stack_is_sorted_asc(*a))
	{
		ft_set_a_before_push_to_b(a, b);
		ft_move_cheapest_a_to_b(a, b);
	}
	ft_stack_sort_three(a);
	while (*b)
	{
		ft_set_index_and_above_median(*a);
		ft_set_index_and_above_median(*b);
		ft_set_target_b_from_a(*a, *b);
		ft_verify_and_set_top_before_push(a, (*b)->target_node, 'a');
		ft_stack_push(b, a, 'a', true);
	}
	ft_set_index_and_above_median(*a);
	ft_set_min_at_top(a);
}

void	ft_sort_stack(t_stack_node **a, t_stack_node **b)
{
	if (!a || !*a || ft_stack_is_sorted_asc(*a))
		return ;
	if (ft_stack_size(*a) == 2)
	{	
		ft_stack_swap(*a, 'a', true);
		return ;
	}
	if (ft_stack_size(*a) == 3)
	{
		ft_stack_sort_three(a);
		return ;
	}
	else
	{
		ft_stack_sort_size_greater_three(a, b);
		return ;
	}
}
