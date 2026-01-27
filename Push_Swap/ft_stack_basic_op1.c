/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_basic_op1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:34:49 by malmany           #+#    #+#             */
/*   Updated: 2026/01/22 21:25:59 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"

void	ft_stack_swap(t_stack_node *st, char stack_name, bool print)
{
	int	val;

	if (!st || !st->next)
		return ;
	val = st->value;
	st->value = st->next->value;
	st->next->value = val;
	if (print)
	{
		write(1, "s", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	ft_stack_swap_both(t_stack_node *a, t_stack_node *b, bool print)
{
	ft_stack_swap(a, 'a', false);
	ft_stack_swap(b, 'b', false);
	if (print)
		write(1, "ss\n", 3);
}

void	ft_stack_push(t_stack_node **from, t_stack_node **to,
		char stack_name, bool print)
{
	t_stack_node	*tmp;

	if (!from || !to || !*from)
		return ;
	tmp = *from;
	*from = tmp->next;
	if (*from)
		(*from)->prev = NULL;
	tmp->prev = NULL;
	tmp->next = *to;
	if (*to)
		(*to)->prev = tmp;
	*to = tmp;
	if (print)
	{
		write(1, "p", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}
