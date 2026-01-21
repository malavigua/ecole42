/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:56:18 by malmany           #+#    #+#             */
/*   Updated: 2026/01/21 15:13:14 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdio.h>

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

void	ft_set_a_before_push_to_b(t_stack_node **a, t_stack_node **b)
{
	ft_set_index_and_above_median(*a);
	ft_set_index_and_above_median(*b);
	ft_set_target_a_from_b(*a, *b);
	ft_set_push_cost(*a, *b);
	ft_set_cheapest(*a);
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
