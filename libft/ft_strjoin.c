/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:03:06 by malmany           #+#    #+#             */
/*   Updated: 2025/11/13 19:40:17 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdlib.h>
#include<stddef.h>

static size_t	f_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		j;
	int		i;
	char	*res;

	j = 0;
	i = 0;
	size = f_strlen(s1) + f_strlen(s2) + 1;
	res = malloc(size);
	if (!res)
		return (NULL);
	while (s1[j])
	{
		res[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		res[j] = s2[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

/*#include<stdio.h>

int main()
{
	char  *s1 = "sssss";
	char s2[] = "";
	char *s3;
	s3 = ft_strjoin(s1, s2);
	printf("%s\n", s3);
}*/
