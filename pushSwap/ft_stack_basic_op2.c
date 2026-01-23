/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_basic_op2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:34:49 by malmany           #+#    #+#             */
/*   Updated: 2026/01/22 21:28:14 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"

void	ft_stack_rotate(t_stack_node **st, char stack_name, bool print)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!st || !*st || !(*st)->next)
		return ;
	first = *st;
	last = ft_stack_last(*st);
	*st = first->next;
	(*st)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (print)
	{
		write(1, "r", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	ft_stack_rotate_both(t_stack_node **a, t_stack_node **b, bool print)
{
	ft_stack_rotate(a, 'a', false);
	ft_stack_rotate(b, 'b', false);
	if (print)
		write(1, "rr\n", 3);
}

void	ft_stack_reverse_rotate(t_stack_node **st, char stack_name, bool print)
{
	t_stack_node	*last;
	t_stack_node	*before_last;

	if (!st || !*st || !(*st)->next)
		return ;
	last = ft_stack_last(*st);
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = *st;
	(*st)->prev = last;
	*st = last;
	if (print)
	{
		write(1, "rr", 2);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	ft_stack_reverse_rotate_both(t_stack_node **a, t_stack_node **b,
	bool print)
{
	ft_stack_reverse_rotate(a, 'a', false);
	ft_stack_reverse_rotate(b, 'b', false);
	if (print)
		write(1, "rrr\n", 4);
}
