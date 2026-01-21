/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:34:49 by malmany           #+#    #+#             */
/*   Updated: 2026/01/21 15:13:31 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"
#include <stdio.h>

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

void	ft_stack_print(t_stack_node *st)
{
	while (st)
	{
		printf("%d", st->value);
		if (st->next)
			printf(" / ");
		st = st->next;
	}
	printf("\n");
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
			return (NULL);
		}
		ft_stack_add_back(&res, n1);
		i++;
	}
	return (res);
}

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

/*int main(void)
{
    int tab[] = {10, 20, 15, 40, 60, 5, 9, 80, 13};
    size_t size = 9;
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;
    a = ft_stack_new(tab, size);
    if (!a)
    {
        printf("Erreur: allocation de la stack a échoué.\n");
        return (1);
    }

    printf("Initial state:\n");
    printf("a:\n");
    ft_stack_print(a);
    printf("b:\n");
    ft_stack_print(b);

    ft_sort_stack(&a, &b);
    printf("After sorting:\n");
    printf("a:\n");
    ft_stack_print(a);
    printf("b:\n");
    ft_stack_print(b);


    ft_stack_clear(&a);
    ft_stack_clear(&b);
    if (!a && !b)
        printf("\nStacks cleared successfully\n");

    return 0;
}
*/
