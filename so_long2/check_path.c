/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:06:19 by malmany           #+#    #+#             */
/*   Updated: 2026/02/10 13:06:21 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	free_visited(bool **v, int h)
{
	int	i;

	i = 0;
	while (i < h)
		free(v[i++]);
	free(v);
}

static bool	**alloc_visited(int h, int w)
{
	bool	**v;
	int		i;
	int		j;

	i = 0;
	v = malloc(sizeof(bool *) * h);
	if (!v)
		return (NULL);
	while (i < h)
	{
		v[i] = malloc(sizeof(bool) * w);
		if (!v[i])
			return (free_visited(v, i), NULL);
		j = 0;
		while (j < w)
			v[i][j++] = false;
		i++;
	}
	return (v);
}

static void	flood_fill(t_map *map, bool **v, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (v[y][x] || map->data[y][x] == '1')
		return ;
	v[y][x] = true;
	flood_fill(map, v, x + 1, y);
	flood_fill(map, v, x - 1, y);
	flood_fill(map, v, x, y + 1);
	flood_fill(map, v, x, y - 1);
}

static bool	check_reachable(t_map *map, bool **v)
{
	int	i;
	int	j;
	int	c;
	int	exit;

	i = 0;
	c = 0;
	exit = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j] && map->data[i][j] != '\n')
		{
			if (map->data[i][j] == 'C' && v[i][j])
				c++;
			if (map->data[i][j] == 'E' && v[i][j])
				exit = 1;
			j++;
		}
		i++;
	}
	return (c == map->nb_collectible && exit);
}

bool	check_path_valid(t_map *map)
{
	bool	**v;
	bool	ok;

	v = alloc_visited(map->height, map->width);
	if (!v)
		return (false);
	flood_fill(map, v, map->start_pos_x, map->start_pos_y);
	ok = check_reachable(map, v);
	free_visited(v, map->height);
	if (!ok)
		write(2, "error\nNo valid path\n", 20);
	return (ok);
}
