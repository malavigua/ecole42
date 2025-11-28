/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:21:17 by malmany           #+#    #+#             */
/*   Updated: 2025/11/19 16:05:51 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdio.h>

static int	f_strln(const char *st)
{
	int	res;

	res = 0;
	while (st[res])
		res++;
	return (res);
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	len_dest;
	size_t	i;
	size_t	j;
	size_t	len_src;

	i = 0;
	len_dest = f_strln(dst);
	len_src = f_strln(src);
	j = len_dest;
	if (siz <= len_dest)
		return (siz + len_src);
	while (src[i] && i < (siz - len_dest - 1))
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (len_dest + len_src);
}

/*#include<bsd/string.h>
#include<stdlib.h>
int main()
{
	char t1[] = "";
	char t2[] = "CCCCCAAAAAAAAA";
	//printf("%lu\n", sizeof(t1));
	//printf("%lu\n", sizeof(t2));
	printf("%zu\n", strlcat(t1, t2, -1));
	printf("%s\n", t1);
}*/
