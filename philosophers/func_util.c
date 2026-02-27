/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 11:18:09 by malmany           #+#    #+#             */
/*   Updated: 2026/02/22 11:19:14 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

bool	ft_is_number_pos(char *c)
{
	int	i;

	if (!c)
		return (false);
	i = 0;
	while (c[i])
	{
		if (!(c[i] >= '0' && c[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_is_all_num(int nb_args, char **args)
{
	int	i;

	i = 0;
	while (i < nb_args)
	{
		if (!ft_is_number_pos(args[i]))
			return (false);
		i++;
	}
	return (true);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	mul;

	res = 0;
	i = 0;
	mul = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			mul *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * mul);
}
