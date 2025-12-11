/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:10:12 by malmany           #+#    #+#             */
/*   Updated: 2025/12/11 19:12:55 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include<stdio.h>

int	ft_strlen(const char *st)
{
    int	res;

    if (!st)
        return 0;
    res = 0;
    while (st[res])
        res++;
    return (res);
}

size_t	f_strcpy(char *dst, const char *src)
{
    int	i;

    i = 0;
    if(!dst)
        return(0);
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (i);
}

char	*f_strcpy_after_nl(char *src)
{
    int		i;
    int		j;
    char	*dst;
    int len;

    i = 0;
    j = 0;
    if(!src)
	    return(NULL);
    while (src[i] && src[i] != '\n')
        i++;
    len = ft_strlen(src);
    if (src[i] == '\n')
        i++;
    dst = malloc(len - i + 1);
    if (!dst)
        return (NULL);
    while (src[i])
        dst[j++] = src[i++];
    dst[j] = '\0';
    free(src);
    return (dst);
}

char    *ft_strjoin(char *s1, char  *s2)
{
        int             size;
        int             j;
        int             i;
        char    *res;

        j = 0;
        i = 0;
        size = ft_strlen(s1) + ft_strlen(s2) + 1;
        res = malloc(size);
        if (!res)
                return (NULL);
        while (s1[j])
        {
                res[j] = s1[j];
                j++;
        }
        while (s2[i])
        {
                res[j] = s2[i];
                j++;
                i++;
        }
        res[j] = '\0';
	if(s1)
		free(s1);
        return (res);
}

int	is_in_str(char *s, char c)
{
    int		i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char	*ft_strdup(const char *s)
{
    int		len;
    char	*res;

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

char	*extract_line(char *c)
{
	int	i;
	int 	j;
	char *res;
	i = 0;
	j =0;
	if (!c)
		return (NULL);
	while (c[i] && c[i] != '\n')
		i++;
	if(c[i] == '\n')
		i++;
	res = malloc(i + 1);
	if(!res)
		return(NULL);
	while(j < i)
	{
		res[j] = c[j];
		j++;
	}
	res[j] = '\0';
	return(res);
}

char	*get_next_line(int fd)
{
    ssize_t			r;
    char			*buf;
    static char		*extract_char;
    char			*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
        	return(NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if(!buf)
		return(NULL);
	if(!extract_char)
	{
		extract_char = ft_strdup("");
		if (!extract_char)
			return NULL;
	}

        buf[0] = '\0';

        r = 1;
	while (r > 0 && !(is_in_str(buf, '\n')))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(buf);
			free(extract_char);
			return NULL;
		}
		if(r == 0)
		{
			if(extract_char[0] == '\0')
			{	
				free(buf);
				free(extract_char);
				return (NULL);
			}
			return(extract_char);
		}
            buf[r] = '\0';
            extract_char = ft_strjoin(extract_char, buf);
        }
	if(extract_char && is_in_str(extract_char, '\n'))
		line = extract_line(extract_char);
	extract_char = f_strcpy_after_nl(extract_char);
	free(buf);
	return(line);
}

#include <fcntl.h>
  int main()
  {
  char* fileName = "test.txt";
  int fd = open(fileName, O_RDONLY);

  if (fd == -1)
  {
  printf("\nError Opening File!!\n");
  exit(1);
  }
  else
  {
  char *s = get_next_line(fd);
  if (s)
  printf("%s", s);
  else
  printf("NULL");

  s = get_next_line(fd);
  if (s)
  printf("%s", s);
  else
  printf("NULL");
  s = get_next_line(fd);
  if (s)
  printf("%s", s);
  else
  printf("NULL");
  s = get_next_line(fd);
  if (s)
  printf("%s", s);
  else
  printf("NULL");
  s = get_next_line(fd);
  if (s)
  printf("%s", s);
  else
  printf("NULL");
  s = get_next_line(fd);
  if (s)
  printf("%s", s);
  else
  printf("NULL");

  }
  }
