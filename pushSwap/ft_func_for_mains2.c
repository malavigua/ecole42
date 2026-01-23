/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_for_mains2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:13:43 by malmany           #+#    #+#             */
/*   Updated: 2026/01/23 11:28:02 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"

int	*ft_create_int_tab(int size_args, char **args)
{
	int		*int_tab;
	int		i;
	long	l;

	int_tab = malloc(sizeof(int) * (size_args));
	i = 0;
	while (i < size_args)
	{
		l = ft_atol(args[i]);
		if (l >= INT_MIN && l <= INT_MAX)
			int_tab[i] = l;
		else
		{
			free(int_tab);
			return (NULL);
		}
		i++;
	}
	return (int_tab);
}

bool	ft_get_args_and_sizeargs(int argc, char **argv, char ***args,
		int *size_args)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		*args = ft_split(argv[1], ' ');
		if (!*args || !(*args)[0])
			return (false);
		while ((*args)[i])
			i++;
		*size_args = i;
	}
	else
	{
		*args = argv + 1;
		*size_args = argc - 1;
	}
	return (true);
}

bool	ft_parse_and_validate(char **args, int size_args, int **int_tab)
{
	*int_tab = NULL;
	if (!ft_is_all_num(size_args, args))
		return (false);
	*int_tab = ft_create_int_tab(size_args, args);
	if (!(*int_tab))
		return (false);
	if (ft_contains_duplicate(*int_tab, size_args))
	{
		free(*int_tab);
		*int_tab = NULL;
		return (false);
	}
	return (true);
}

void	ft_clean_args_split(char **args, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}
