/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:24:09 by malmany           #+#    #+#             */
/*   Updated: 2025/11/19 18:27:59 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stddef.h>
#include<stdlib.h>

char	*ft_strdup(const char *s)
{
	int		len;
	char	*res;

	len = 0;
	while (s[len])
		len++;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	len = 0;
	while (s[len])
	{
		res[len] = s[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}

/*#include<string.h>
#include<stdio.h>
int main()
{
	char t[] = "test";
	char *res;
	res = ft_strdup(t);
	printf("%s\n", res);
}*/
