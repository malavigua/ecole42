/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:11:00 by malmany           #+#    #+#             */
/*   Updated: 2025/12/03 12:11:06 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *st)
{
	size_t	res;

	if (!st)
		return (0);
	res = 0;
	while (st[res])
		res++;
	return (res);
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	if (!dst)
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*res;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	len = 0;
	while (s[len])
	{
		res[len] = s[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}

char	*f_strcpy_after_nl(char *src)
{
	size_t		i;
	size_t		j;
	char		*dst;

	i = 0;
	j = 0;
	if (!src)
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		i++;
	if (!src[i])
		return (free(src), NULL);
	dst = malloc(ft_strlen(src) - i + 1);
	if (!dst)
		return (free(src), NULL);
	while (src[i])
		dst[j++] = src[i++];
	dst[j] = '\0';
	free(src);
	return (dst);
}
