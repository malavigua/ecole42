/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_for_mains1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:13:43 by malmany           #+#    #+#             */
/*   Updated: 2026/01/23 11:26:50 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"

bool	ft_is_number(char *c)
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

bool	ft_contains_duplicate(int *int_tab, int size_int_tab)
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

bool	ft_is_all_num(int size_args, char **args)
{
	int	i;

	i = 0;
	while (i < size_args)
	{
		if (!ft_is_number(args[i]))
			return (false);
		i++;
	}
	return (true);
}
