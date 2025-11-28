/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:06:29 by malmany           #+#    #+#             */
/*   Updated: 2025/11/19 18:07:21 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdio.h>

static int	is_space(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

static int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

static int	char_to_int(const char *nptr, int *i, int *mul )
{
	int	j;
	int	res;

	j = 0;
	res = 0;
	while (nptr[*i] && is_num(nptr[*i]))
	{
		j++;
		*i = *i + 1;
	}
	while (j > 0)
	{
		*i = *i - 1;
		res += *mul * (nptr[*i] - '0');
		*mul = *mul * 10;
		j--;
	}
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	mul;

	res = 0;
	i = 0;
	mul = 1;
	while (is_space(nptr[i]))
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			mul *= -1;
		i++;
	}
	if (is_num(nptr[i]))
	{
		res = char_to_int(nptr, &i, &mul);
	}
	return (res);
}

/*#include<stdlib.h>
int main()
{
	char t[] = "-945";
	printf("%d\n", atoi(t));
	printf("%d\n", ft_atoi(t));
}
*/
