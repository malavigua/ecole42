/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:04:10 by malmany           #+#    #+#             */
/*   Updated: 2025/11/12 17:09:35 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	ps = s;
	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			ps[i] = '\0';
			i++;
		}
	}
}

/*#include<stdio.h>

int main()
{
	char test[] = "test";
	ft_bzero(test, 2);
	printf("%s\n", test);
}*/
