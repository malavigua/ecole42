/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_pushswap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:38:05 by malmany           #+#    #+#             */
/*   Updated: 2026/01/22 21:06:17 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static void	ft_init_and_sort_stack(int *int_tab, int size_args)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = ft_stack_new(int_tab, size_args);
	b = NULL;
	if (!a)
		return ;
	ft_sort_stack(&a, &b);
	ft_stack_clear(&a);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		size_args;
	int		*int_tab;

	if (argc < 2)
		return (0);
	if (!ft_get_args_and_sizeargs(argc, argv, &args, &size_args))
		return (write(2, "Error\n", 6), 1);
	if (!ft_parse_and_validate(args, size_args, &int_tab))
	{
		ft_clean_args_split(args, argc);
		return (write(2, "Error\n", 6), 1);
	}
	ft_init_and_sort_stack(int_tab, size_args);
	ft_clean_args_split(args, argc);
	return (0);
}
