/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:10:12 by malmany           #+#    #+#             */
/*   Updated: 2025/12/03 17:34:42 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include<stdio.h>

int	ft_strln(const char *st)
{
	int	res;

	res = 0;
	while (st[res])
		res++;
	return (res);
}


char	*str_concat_until_nl(char *dst, char *src)
{
	size_t	len_dest;
	size_t	i;
	size_t	j;
	size_t	len_src;
	char	*res;

	len_dest = ft_strln(dst);
	len_src = ft_strln(src);
	i = 0;
	j = 0;
	res = malloc(len_dest + len_src + 1);
	if (!res)
		return (NULL);
	while (i < len_dest)
	{	
		res[i] = dst[i];
		i++;
	}
	while (j < len_src && src[j] != '\n')
	{
		res[i] = src[j];
		i++;
		j++;
	}
	if (src[j] == '\n')
	{
		res[i] = '\n';
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	is_in_str(char *s, char c)
{
	int		i;
	char	*str;

	str = s;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static ssize_t	buf_size;
	ssize_t			r;
	char			*buf;
	char			*res;
	int				end_of_line;

	res = "";
	r = 1;
	end_of_line = 0;
	buf_size = 5;
	buf = malloc(buf_size);
	if (buf)
	{
		while (r > 0 && !(end_of_line))
		{
			r = read(fd, buf, buf_size);
			end_of_line = is_in_str(buf, '\n');
			res = str_concat_until_nl(res, buf);
		}
		if (r == -1 || res[0] == '\0')
			return (NULL);
		else
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
		char *s = get_next_line(fd);

		if (s)
			printf("%s", s);
		else
			printf("NULL");
	}
}*/
