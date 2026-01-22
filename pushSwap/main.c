/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:38:05 by malmany           #+#    #+#             */
/*   Updated: 2026/01/22 16:08:16 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	main(int argc, char **argv)
{
	char	**args;
	int		size_args;
	int		*int_tab;

	if (argc < 2)
		return (0);
	if (!get_args_and_sizeargs(argc, argv, &args, &size_args))
		return (write(1, "Error\n", 6), 1);
	if (!parse_and_validate(args, size_args, &int_tab))
	{
		clean_args_split(args, argc);
		return (write(1, "Error\n", 6), 1);
	}
	init_and_sort_stack(int_tab, size_args);
	clean_args_split(args, argc);
	free(int_tab);
	return (0);
}
