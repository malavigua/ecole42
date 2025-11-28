/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:24:52 by malmany           #+#    #+#             */
/*   Updated: 2025/11/19 17:44:28 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*ss1;
	unsigned char		*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && ss1[i] == ss2[i])
		i++;
	if (i == n)
		return (0);
	return (ss1[i] - ss2[i]);
}
/*#include<string.h>
#include<stdio.h>
int     main()
{
        char s1[] = "\xff\0\0\xaa\0\xde\xffMACOSX\xff";
        char s2[] = "\xff\0\0\xaa\0\xde\x00MBS";
        printf("%d\n", memcmp(s1, s2, 9));
        printf("%d\n", ft_memcmp(s1, s2, 9));

}
*/
