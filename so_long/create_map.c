/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:22:53 by malmany           #+#    #+#             */
/*   Updated: 2026/02/10 14:32:05 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static t_counter	init_counter(void)
{
	t_counter	c;

	c.nb_c = 0;
	c.nb_p = 0;
	c.nb_e = 0;
	return (c);
}

static bool	check_at_least_one_c_e_p(t_counter count)
{
	bool	has_error;

	has_error = false;
	if (count.nb_c == 0)
	{
		if (!has_error)
			write(2, "error\n", 6);
		write(2, " - There must be at least one collectible\n", 42);
		has_error = true;
	}
	if (count.nb_p == 0)
	{
		if (!has_error)
			write(2, "error\n", 6);
		write(2, " - There must be at least one entry\n", 36);
		has_error = true;
	}
	if (count.nb_e == 0)
	{
		if (!has_error)
			write(2, "error\n", 6);
		write(2, " - There must be at least one exit\n", 35);
		has_error = true;
	}
	return (!has_error);
}

static bool	fill_and_check_map(int fd, t_map *map)
{
	char		*line;
	int			i;
	t_counter	count;

	count = init_counter();
	i = 0;
	line = get_next_line(fd);
	if (!line || !check_first_line(line))
		return (free(line), false);
	map->data[i++] = line;
	map->width = ft_strlen(line) -1;
	while (i < map->height - 1)
	{
		line = get_next_line(fd);
		if (!line || !check_middle_line(line, map, &count, i))
			return (free(line), clear_map_data(map->data, i), false);
		map->data[i++] = line;
	}
	line = get_next_line(fd);
	if (!line || !check_last_line(line, map->width)
		|| !check_at_least_one_c_e_p(count))
		return (free(line), clear_map_data(map->data, i), false);
	map->data[i] = line;
	map->nb_collectible = count.nb_c;
	return (true);
}

t_map	*create_map(char *filename)
{
	int		fd;
	int		nb_line;
	t_map	*map;

	if (!is_valid_file(filename, &nb_line))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, "error\nCan not open the file\n", 28), NULL);
	map = new_map(nb_line);
	if (!map)
		return (close(fd), NULL);
	if (!fill_and_check_map(fd, map))
		return (close(fd), free(map), NULL);
	close(fd);
	return (map);
}
