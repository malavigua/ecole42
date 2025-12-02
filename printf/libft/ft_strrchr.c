/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:04:30 by malmany           #+#    #+#             */
/*   Updated: 2025/11/19 19:02:03 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*str;

	str = (char *) s;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
		{	
			j = i;
			while (s[j])
			{
				if (s[j] == (char) c)
					i = j;
				j++;
			}
			return (str + i);
		}
		i++;
	}
	if ((char)c == '\0')
		return (str + i);
	return (NULL);
}

/*#include<string.h>
#include<stdio.h>
int main()
{
        char t[] = "testddd";
        printf("%s", ft_strrchr(t, '\0'));
}
*/
