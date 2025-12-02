/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:46:18 by malmany           #+#    #+#             */
/*   Updated: 2025/11/21 17:00:19 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>

static int	num_of_word_to_split(char const *s, char c)
{
	int	i;
	int	res;
	int	in_word;

	res = 0;
	i = 0;
	in_word = 0;
	if (!s || s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (in_word && s[i] == c)
			in_word = 0;
		if (s[i] && s[i] != c && !in_word)
		{
			res++;
			in_word = 1;
		}
		i++;
	}
	return (res);
}

static void	free_char(char **res, int m)
{
	while (m > 0)
	{
		m--;
		free(res[m]);
	}
	free(res);
}

static char	*f_strlcpy(const char *src, int *word_siz, char **res, int *m)
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	res[*m] = malloc((*word_siz) + 1);
	if (!res[*m])
	{	
		free_char(res, *m);
		return (NULL);
	}
	while (src[len])
		len++;
	while (src[i] && i < (*word_siz))
	{
		res[*m][i] = src[i];
		i++;
	}
	res[*m][i] = '\0';
	*m = *m + 1;
	*word_siz = 0;
	return (res[(*m) - 1]);
}

static int	f_wordsize(char const *s, char c, int *word_end)
{
	int	word_siz;

	word_siz = 0;
	while (s[*word_end] && s[*word_end] != c)
	{
		word_siz++;
		*word_end += 1;
	}
	return (word_siz);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		word_end;
	int		m;
	int		word_siz;
	char	**res;

	j = 0;
	m = 0;
	res = malloc((num_of_word_to_split(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[j])
	{
		word_end = j;
		word_siz = f_wordsize(s, c, &word_end);
		if (word_siz > 0)
			if (!f_strlcpy(s + j, &word_siz, res, &m))
				return (NULL);
		if (word_end > j)
			j = word_end;
		else
			j++;
	}
	res[m] = 0;
	return (res);
}

/*int main ()
{
	char *s = "gggggggggggfsdfsggddddg";
	char **res;
	res = ft_split(s, 'g');
	int i = num_of_word_to_split(s, 'g');
	printf("%d\n", i);
	printf("%s\n", res[0]);
}*/
