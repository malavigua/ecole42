/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:56:49 by malmany           #+#    #+#             */
/*   Updated: 2025/11/19 17:23:04 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss;

	ss = (unsigned char *) s;
	i = 0;
	if (n <= 0)
		return (NULL);
	while (i < n)
	{
		if (ss[i] == (unsigned char) c)
			return (ss + i);
		i++;
	}
	return (NULL);
}

/*#include<string.h>
#include<stdio.h>
int main()
{
        char t[] = "test\0ddd";
        void *f = ft_memchr(t, '\0', 9);
	if ( f != NULL )
       	{
        	printf( "La valeur à la position calculée est %d\n", *((char *) f) );
	};
}*/
