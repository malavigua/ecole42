/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_checker_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:13:16 by malmany           #+#    #+#             */
/*   Updated: 2026/01/26 19:23:26 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"
#include "get_next_line_bonus.h"

int	main(int argc, char **argv)
{
	char			**args;
	int				size_args;
	int				*int_tab;
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc < 2)
		return (0);
	if (!ft_get_args_and_sizeargs(argc, argv, &args, &size_args))
		return (free(args), write(2, "Error\n", 6), 1);
	if (!ft_parse_and_validate(args, size_args, &int_tab))
		return (ft_clean_args_split(args, argc), write(2, "Error\n", 6), 1);
	a = ft_stack_new(int_tab, size_args);
	b = NULL;
	if (!a)
		return (write(2, "Error\n", 6), 1);
	if (!ft_read_and_apply_op(&a, &b))
	{
		ft_clean_stacks_and_args(&a, &b, args, argc);
		return (write(2, "Error\n", 6), 1);
	}
	ft_verify_stack_is_sorted(a, b);
	ft_clean_stacks_and_args(&a, &b, args, argc);
	return (0);
}
