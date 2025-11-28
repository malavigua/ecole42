/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:34:03 by malmany           #+#    #+#             */
/*   Updated: 2025/11/19 19:02:57 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (str + i);
		i++;
	}
	if ((char) c == '\0')
		return (str + i);
	return (NULL);
}

/*#include<string.h>
#include<stdio.h>
int main()
{
	char t[] = "teste";
	printf("%s\n", strchr(t, 'e'));
	printf("%s\n", ft_strchr(t, 'e'));
}*/
