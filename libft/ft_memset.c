/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:56:02 by malmany           #+#    #+#             */
/*   Updated: 2025/11/18 19:20:03 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	ps = s;
	i = 0;
	while (i < n)
	{
		ps[i] = c;
		i++;
	}
	return (s);
}

/*#include <string.h>
#include <stdio.h>

int main()
{
	int s[4] = {1, 2, 3, 4};
	int i;

	i = 0;
	while(i < 4)
	{
		printf(" valeur de s avant memset : %d\n", s[i]);
		i++;
	}
	ft_memset(s, 6, (sizeof(int)* 2));
	i = 0;
	while(i < 4)
        {
                printf(" valeur de s apres  memset : %d\n", s[i]);
		i++;
        }



}*/
