/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:36:25 by malmany           #+#    #+#             */
/*   Updated: 2026/02/10 13:36:28 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

t_map	*new_map(int height)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->data = malloc(sizeof(char *) * (height + 1));
	if (!map->data)
	{
		free(map);
		return (NULL);
	}
	map->data[height] = NULL;
	map->height = height;
	map->width = 0;
	map->start_pos_x = 0;
	map->start_pos_y = 0;
	map->nb_collectible = 0;
	return (map);
}

void	clear_map_data(char **data, int size)
{
	int	i;

	if (!data)
		return ;
	i = 0;
	while (i < size)
	{
		free(data[i]);
		i++;
	}
	free(data);
}

void	free_t_map(t_map *map)
{
	if (!map)
		return ;
	clear_map_data(map->data, map->height);
	free(map);
}
