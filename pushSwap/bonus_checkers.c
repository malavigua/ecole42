/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:13:16 by malmany           #+#    #+#             */
/*   Updated: 2026/01/22 18:16:32 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"
#include "get_next_line.h"
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

bool	make_op_to_stack(t_stack_node **a, t_stack_node **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_stack_swap(*a, 'a', false);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_stack_swap(*b, 'b', false);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_stack_swap_both(*a, *b, false);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_stack_push(b, a, 'a', false);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_stack_push(a, b, 'b', false);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_stack_rotate(a, 'a', false);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_stack_rotate(b, 'b', false);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_stack_rotate_both(a, b, false);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_stack_reverse_rotate(a, 'a', false);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_stack_reverse_rotate(b, 'b', false);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_stack_reverse_rotate_both(a, b, false);
	else
		return (false);
	return (true);
}

bool read_and_apply_op(t_stack_node **a, t_stack_node **b)
{
	char *line;
	
	line = get_next_line(0);
	while (line)
	{
		if(!make_op_to_stack(a, b,line))
		{
			free(line);
			return (false);
		}
		free(line);
		line = get_next_line(0);
	}
	return (true);
}

void	clean_stacks_and_args(t_stack_node **a, t_stack_node **b, char **args, int argc)
{
	ft_stack_clear(a);
	ft_stack_clear(b);
	clean_args_split(args, argc);
}

void verify_stack_is_sorted(t_stack_node *a, t_stack_node *b)
{
	if (ft_stack_is_sorted_asc(a) && b == NULL)
		write(1, "ok\n", 3);
	else
		write(1, "ko\n", 3);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		size_args;
	int		*int_tab;
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc < 2)
		return (0);
	if (!get_args_and_sizeargs(argc, argv, &args, &size_args))
		return (write(1, "Error\n", 6), 1);
	if (!parse_and_validate(args, size_args, &int_tab))
	{
		clean_args_split(args, argc);
		return (write(1, "Error\n", 6), 1);
	}
	a = ft_stack_new(int_tab, size_args);
	b = NULL;
	if (!a)
		return (write(1, "Error\n", 6), 1);
	if(!read_and_apply_op(&a, &b))
	{
		clean_stacks_and_args(&a, &b, args, argc);
		return (write(1, "Error\n", 6), 1);
	}
	verify_stack_is_sorted(a, b);
	clean_stacks_and_args(&a, &b, args, argc);
	return (0);
}
