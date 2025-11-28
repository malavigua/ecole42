/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:12:51 by malmany           #+#    #+#             */
/*   Updated: 2025/11/21 15:18:02 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include<stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (little[0] == '\0')
		return ((char *) big);
	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			k = i;
			while (k < len && big[k] && little[j] && big[k] == little[j])
			{
				k++;
				j++;
			}
			if (little[j] == '\0')
				return ((char *)big + i);
		}		
		i++;
	}
	return (NULL);
}

/*#include<bsd/string.h>

int main()
{
	const char big[] = "abcdefghijkl";
	const char *little = "efgh";
	printf("%s\n", strnstr(big, little, 9));
	printf("%s\n", ft_strnstr(big, little, 9));
}
*/
