/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:10:12 by malmany           #+#    #+#             */
/*   Updated: 2025/12/03 13:58:20 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int      ft_strln(const char *st)
{
        int     res;

        res = 0;
        while (st[res])
                res++;
        return (res);
}

size_t  ft_strlcat(char *dst, const char *src, size_t siz)
{
        size_t  len_dest;
        size_t  i;
        size_t  j;
        size_t  len_src;

        i = 0;
        len_dest = ft_strln(dst);
        len_src = ft_strln(src);
        j = len_dest;
        if (siz <= len_dest)
                return (siz + len_src);
        while (src[i] && i < (siz - len_dest - 1))
                dst[j++] = src[i++];
        dst[j] = '\0';
        return (len_dest + len_src);
}

int	is_in_str(char *s, char c)
{
        int             i;
        char    *str;

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
	ssize_t r;
	static ssize_t buf_size;
	char *buf;
	char *res;
	int	end_of_line;

	r = 1;
	end_of_line = 0;

	buf_size = 10;
	buf = malloc(buf_size);
	if (buf)
	{
		while(r > 0 && !(end_of_line))
		{
			r = read(fd, buf,buf_size);
			end_of_line = is_in_str(buf, '\n');
			if(!(end_of_line))
				ft_strlcat(res, buf, buf_size);
		}
		if( r == -1)
			return (NULL);
		else
			return (res);
	
	}
	return (NULL);
}
#include<stdio.h>
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
		printf("\nFile %s opened sucessfully!\n", fileName);
		char *s = get_next_line(fd);

		if (s)
			printf("%s", s);
	}
	
}
