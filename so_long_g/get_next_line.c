/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:10:12 by malmany           #+#    #+#             */
/*   Updated: 2025/12/12 18:00:33 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	free(s1);
	return (res);
}

int	is_in_str(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*extract_line(char *c)
{
	size_t		i;
	size_t		j;
	char		*res;

	i = 0;
	j = 0;
	if (!c || c[0] == '\0')
		return (NULL);
	while (c[i] && c[i] != '\n')
		i++;
	if (c[i] == '\n')
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	while (j < i)
	{
		res[j] = c[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*read_until_nl(int fd, char *extract_char)
{
	char	*buf;
	ssize_t	r;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(extract_char), NULL);
	r = 1;
	while (r > 0 && !is_in_str(extract_char, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (free(buf), free(extract_char), NULL);
		if (r == 0 && extract_char && extract_char[0] == '\0')
		{
			free(extract_char);
			extract_char = NULL;
			return (free(buf), NULL);
		}
		buf[r] = '\0';
		extract_char = ft_strjoin(extract_char, buf);
		if (!extract_char)
			return (free(buf), NULL);
	}
	free(buf);
	return (extract_char);
}

char	*get_next_line(int fd)
{
	static char	*extract_char;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!extract_char)
	{
		extract_char = ft_strdup("");
		if (!extract_char)
			return (NULL);
	}
	extract_char = read_until_nl(fd, extract_char);
	if (!extract_char)
		return (NULL);
	line = extract_line(extract_char);
	if (!line)
	{
		free(extract_char);
		extract_char = NULL;
		return (NULL);
	}
	extract_char = f_strcpy_after_nl(extract_char);
	return (line);
}

/*#include <fcntl.h>
  int main()
  {
  char* fileName = "test.txt";
  int fd = open(fileName, O_RDONLY);

  if (fd == -1)
  {
  printf("error opening file");
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
  }*/
