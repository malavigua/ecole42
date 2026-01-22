/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:13:43 by malmany           #+#    #+#             */
/*   Updated: 2026/01/22 13:01:08 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"

bool	is_number(char *c)
{
	int	i;

	if (!c)
		return (false);
	if ((c[0] == '+' || c[0] == '-') && !c[1])
		return (false);
	i = 0;
	if (c[0] == '+' || c[0] == '-')
		i++;
	while (c[i])
	{
		if (!(c[i] >= '0' && c[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

long	ft_atol(char *s)
{
	int		i;
	int		mul;
	long	res;

	res = 0;
	i = 0;
	mul = 1;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if ((s[i] == '-' || s[i] == '+'))
	{
		if (s[i] == '-')
			mul *= -1;
		i++;
	}
	while ((s[i] >= '0' && s[i] <= '9'))
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * mul);
}

bool	contains_duplicate(int *int_tab, int size_int_tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_int_tab)
	{
		j = i + 1;
		while (j < size_int_tab)
		{
			if (int_tab[i] == int_tab[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_all_num(int size_args, char **args)
{
	int	i;

	i = 0;
	while (i < size_args)
	{
		if (!is_number(args[i]))
			return (false);
		i++;
	}
	return (true);
}

int	*create_int_tab(int size_args, char **args)
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

bool	get_args_and_sizeargs(int argc, char **argv, char ***args,
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

bool	parse_and_validate(char **args, int size_args, int **int_tab)
{
	*int_tab = NULL;
	if (!is_all_num(size_args, args))
		return (false);
	*int_tab = create_int_tab(size_args, args);
	if (!(*int_tab))
		return (false);
	if (contains_duplicate(*int_tab, size_args))
	{
		free(*int_tab);
		*int_tab = NULL;
		return (false);
	}
	return (true);
}

void	clean_args_split(char **args, int argc)
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

void	init_and_sort_stack(int *int_tab, int size_args)
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
