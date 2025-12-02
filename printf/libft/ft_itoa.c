/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:54:58 by malmany           #+#    #+#             */
/*   Updated: 2025/11/20 15:54:46 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdlib.h>
#include<stddef.h>
#include<stdio.h>

static int	size_int_to_char(long int n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		n = -n;
		res++;
	}
	while (n / 10 > 0)
	{
		res++;
		n = n / 10;
	}
	return (res + 1);
}

static int	is_neg(long int n)
{
	return (n < 0);
}

static	void	n_neg(long int *n, char *res)
{
	if (*n < 0)
	{
		res[0] = '-';
		*n = (*n) * (-1);
	}
}

char	*ft_itoa(int n)
{
	long int	num;
	int			res_size;
	int			is_nega;
	char		*res;

	num = (long int) n;
	is_nega = is_neg(num);
	res_size = size_int_to_char(num);
	res = malloc(res_size + 1);
	if (!res)
		return (NULL);
	n_neg(&num, res);
	res[res_size] = '\0';
	while (res_size > 1)
	{
		res[res_size - 1] = num % 10 + '0';
		num = num / 10;
		res_size--;
	}
	if (!is_nega)
		res[res_size - 1] = num + '0';
	return (res);
}

/*int main()
{

	printf("%s\n", ft_itoa(-214));
	
}*/
