/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:55:44 by malmany           #+#    #+#             */
/*   Updated: 2026/02/10 13:55:46 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_valid_file_name(char *filename)
{
	int	len;

	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len < 5)
		return (false);
	if (filename[len - 1] != 'r' || filename[len - 2] != 'e'
		|| filename[len - 3] != 'b' || filename[len - 4] != '.')
		return (false);
	return (true);
}

static int	get_nb_line(char *filename)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

bool	is_valid_file(char *filename, int *nb_line)
{
	*nb_line = get_nb_line(filename);
	if (!is_valid_file_name(filename))
		return (write(2, "error\nMap must be a .ber file\n", 29), false);
	if (*nb_line <= 0)
		return (write(2, "error\nMap is empty\n", 19), false);
	if (*nb_line < 3)
		return (write(2, "error\nMap must contain at least 3 lines\n", 41),
			false);
	return (true);
}
