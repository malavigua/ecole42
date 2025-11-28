/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:40:27 by malmany           #+#    #+#             */
/*   Updated: 2025/11/21 11:50:28 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stddef.h>
#include<stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*res;

	s_len = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[s_len])
		s_len++;
	if (start + len > s_len)
		len = s_len - start;
	if (start >= s_len)
		res = malloc(1);
	else
		res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (start < s_len)
	{
		while (i < len && s[start])
			res[i++] = s[start++];
	}	
	res[i] = '\0';
	return (res);
}

/*#include<stdio.h>
int main()
{
	char t[] = "texte";
	char *s;
	s = ft_substr(t, 10, 10);
	if (s)
		printf("%s\n", s);


}
*/
