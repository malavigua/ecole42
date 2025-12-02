/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:03:02 by malmany           #+#    #+#             */
/*   Updated: 2025/11/21 11:31:41 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		i;
	char		*res;

	i = 0;
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	while (i < nmemb * size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

/*#include<stdio.h>

int main()
{
	int *c;
	c = ft_calloc(0, 4);
	int i;
	i = 0;
	while (i < 5)
	{
		printf("%d\n", c[i]);
		i++;
	}
	free(c);
}*/
