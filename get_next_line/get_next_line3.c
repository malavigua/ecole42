/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:10:12 by malmany           #+#    #+#             */
/*   Updated: 2025/12/08 17:56:23 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include<stdio.h>

int	ft_strlen(const char *st)
{
    int	res;

    res = 0;
    while (st[res])
        res++;
    return (res);
}

int	strlen_before_nl(const char *st)
{
    int	res;

    res = 0;
    while (st[res] && st[res] != '\n')
        res++;
    if (st[res] == '\n')
        res++;
    return (res);
}

size_t	f_strcpy(char *dst, const char *src)
{
    int	i;

    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (i);
}

char	*f_strcpy_after_nl(const char *src)
{
    int		i;
    int		j;
    char	*dst;
    int len;

    i = 0;
    j = 0;
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
    return (dst);
}

char	*str_concat_until_nl(char *dst, char *src)
{
    size_t	len_dst;
    size_t	i;
    size_t	j;
    size_t	len_src;
    char	*res;

    len_dst = ft_strlen(dst);
    len_src = strlen_before_nl(src);
    i = 0;
    j = 0;
    res = malloc(len_dst + len_src + 1);
    if (!res)
        return NULL;
    if (len_dst > 0)
        i = f_strcpy(res, dst);
    while (j < len_src && src[j] != '\n')
        res[i++] = src[j++];
    if (src[j] == '\n')
    {
        res[i] = '\n';
        i++;
    }
    res[i] = '\0';
    free(dst);
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

char	*get_next_line(int fd)
{
    static char		*char_after_nl;
    ssize_t			r;
    char			*buf;
    char			*res;
    char            *tmp;

    res = ft_strdup("");
    if (!res)
        return NULL;
    if (char_after_nl)
    {
        free(res);
        res = ft_strdup(char_after_nl);
    }
    if (is_in_str(res, '\n'))
    {
        if (char_after_nl)
            free(char_after_nl);
        char_after_nl = f_strcpy_after_nl(res);
        tmp =ft_strdup("");
        if(!tmp)
            return (NULL);
        res = str_concat_until_nl(tmp, res);
        return (res);
    }
    else
    {
        buf = malloc(BUFFER_SIZE + 1);
        if (!buf)
        {
            free(res);
            return (NULL);
        }
        buf[0] = '\0';
        r = 1;
        while (r > 0 && !(is_in_str(res, '\n')))
        {
            r = read(fd, buf, BUFFER_SIZE);
            if (r == -1)
            {
                free(buf);   
                free(res);   
                return NULL; 
            }
            if(r == 0)
			{
				free(buf);
                if(char_after_nl)
				    free(char_after_nl);
				if(res[0] == '\0')
				{
					free(res);
					return (NULL);
				}
				return(res);
			}
            buf[r] = '\0';
            res = str_concat_until_nl(res, buf);
        }
        	
        if (is_in_str(buf, '\n'))
        {
            if (char_after_nl)
                free(char_after_nl);
            char_after_nl = f_strcpy_after_nl(buf);
        }
            return (res);
        
    }
    return (NULL);
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
  /*get_next_line(fd);
  get_next_line(fd);
  get_next_line(fd);
  get_next_line(fd);
  get_next_line(fd);
  get_next_line(fd);*/
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
