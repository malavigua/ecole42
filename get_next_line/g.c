/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:10:12 by malmany           #+#    #+#             */
/*   Updated: 2025/12/10 17:37:02 by malmany          ###   ########.fr       */
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
		return (NULL);
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

char    *f_strcpy_after_nl(const char *src)
{
        int             i;
        int             j;
        char    *dst;

        i = 0;
        j = 0;
        while (src[i] && src[i] != '\n')
                i++;
        dst = malloc((ft_strlen(src) - i) + 1);
        if (!dst)
                return (NULL);
        i++;
        while (src[i])
                dst[j++] = src[i++];
        dst[j] = '\0';
        return (dst);
}

char	*get_next_line(int fd)
{
	static char		*char_after_nl;
	ssize_t			r;
	char			*buf;
	char			*res;
	char			*tmp;
	
	if (char_after_nl)
		res = ft_strdup(char_after_nl);
	else
		res = ft_strdup("");
	if(!res)
		return(NULL);

	if (is_in_str(res, '\n'))
	{
		if(char_after_nl)
			free(char_after_nl);
		
		char_after_nl = f_strcpy_after_nl(res);
		tmp = ft_strdup("");
		if(!tmp)
		{
			free(res);
			return(NULL);
		}
		buf = res;
		free(res);
		res = str_concat_until_nl(tmp, buf);
		free(tmp);
		return (res);
	}
	else
	{
		r = 1;
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
		{
			free(res);
			return (NULL);
		}
		while (r > 0 && !(is_in_str(buf, '\n')))
		{
			r = read(fd, buf, BUFFER_SIZE);
			if(r == -1)
			{	
				free(res);
				free(buf);
				free(char_after_nl);
				return(NULL);
			}
			if(r == 0)
			{
				free(buf);
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
			if(char_after_nl)
                        	free(char_after_nl);
			char_after_nl = f_strcpy_after_nl(res);

		}
		return (res);
		
	}
	return (NULL);
}

/*#include <fcntl.h>
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
		//get_next_line(fd);
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


}*/
