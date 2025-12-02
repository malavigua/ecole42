/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:11:42 by malmany           #+#    #+#             */
/*   Updated: 2025/11/21 14:34:02 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdlib.h>
#include<stdio.h>

static int	is_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{	
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	len_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	define_beg_and_end(char const *s1, char const *set,
		int *beg, int *end)
{
	char	*str;
	int		j;

	j = 0;
	str = (char *)s1;
	while (str[j] && is_in_set(str[j], (char *)set))
		j++;
	*beg = j;
	j = len_str(str) - 1;
	while (j > 0 && is_in_set(str[j], (char *)set))
		j--;
	*end = j;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		j;
	int		beg;
	int		end;
	char	*res;

	define_beg_and_end(s1, set, &beg, &end);
	if (beg > end && s1[0] != '\0')
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	res = (char *) malloc((end - beg) + 2);
	if (!res)
		return (NULL);
	j = 0;
	while (beg <= end)
	{
		res[j] = s1[beg];
		beg++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

/*int	main()
{
	char s1[]= "";
	char set[] = "";
	printf("%s", ft_strtrim(s1, set));
	
}*/
