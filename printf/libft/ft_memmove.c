/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:57:04 by malmany           #+#    #+#             */
/*   Updated: 2025/11/19 13:21:53 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static void	f_memcpy(size_t *n, const unsigned char *s, unsigned char *d)
{
	size_t	i;

	i = 0;
	while (i < *n)
	{
		d[i] = s[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t					i;
	const unsigned char		*s;
	unsigned char			*d;

	s = src;
	d = dest;
	if (n == 0 || dest == src)
		return (dest);
	if (d > s && d < s + n)
	{
		i = n;
		while (i > 0 && s[i])
		{
			i--;
			d[i] = s[i];
		}
	}
	else
	{	
		f_memcpy(&n, s, d);
	}
	return (dest);
}

/*#include<string.h>
int main()
{
        char dest[] = "destdest";
	char src[] = "ii";
        printf(" avant ft_memmove dest: %s\n ", dest);
        ft_memmove(src, dest , 4);
        printf(" apres ft_memmove dest: %s\n ", dest);
}
*/
