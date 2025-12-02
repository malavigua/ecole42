/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:12:31 by malmany           #+#    #+#             */
/*   Updated: 2025/11/19 17:18:13 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	const unsigned char		*s;
	unsigned char			*d;

	if (n == 0 || dest == src)
		return (dest);
	if (n > 0)
	{
		i = 0;
		s = (unsigned char *)src;
		d = (unsigned char *)dest;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*#include<string.h>
#include<stdio.h>
int main()
{
	char src[] = "ss";
	char dest[] = "dsds";
	printf(" avant ft_memcpy dest: %s et src:%s\n", dest, src);
	ft_memcpy(dest, src, 5);
	printf(" apres ft_memcpy dest: %s et src:%s\n", dest, src);

}*/
