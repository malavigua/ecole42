/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:30:52 by malmany           #+#    #+#             */
/*   Updated: 2025/11/19 13:33:49 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (siz > 0)
	{
		while (src[i] && i < (siz - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

/*#include<bsd/string.h>
#include<stdio.h>
int main()
{
	char src[] = "jju";
	char dst[] = "";
	//printf("%zu\n",ft_strlcpy(dst, src, 6));
	printf("%zu\n", strlcpy(dst, src, 5));
	printf("%s\n", dst);
}*/
