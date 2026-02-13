/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:23:04 by malmany           #+#    #+#             */
/*   Updated: 2026/02/10 15:23:07 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	display_player(t_mlx_data *d, int x, int y)
{
	if (d->player.dir == DIR_LEFT)
		mlx_put_image_to_window(d->mlx, d->win,
			d->sprites.player_left, x * 32, y * 32);
	else if (d->player.dir == DIR_RIGHT)
		mlx_put_image_to_window(d->mlx, d->win,
			d->sprites.player_right, x * 32, y * 32);
	else
		mlx_put_image_to_window(d->mlx, d->win,
			d->sprites.player, x * 32, y * 32);
}

void	display_tile(t_mlx_data *d, char c, int x, int y)
{
	mlx_put_image_to_window(d->mlx, d->win, d->sprites.background,
		x * 32, y * 32);
	if (c == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->sprites.obstacle,
			x * 32, y * 32);
	else if (c == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->sprites.collectible,
			x * 32, y * 32);
	else if (c == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->sprites.exit,
			x * 32, y * 32);
	else if (c == 'P')
		mlx_put_image_to_window(d->mlx, d->win, d->sprites.entry,
			x * 32, y * 32);
	else if (c == 'X')
		display_player(d, x, y);
}

void	display_map(t_mlx_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->map->height)
	{
		x = 0;
		while (x < d->map->width)
		{
			display_tile(d, d->map->data[y][x], x, y);
			x++;
		}
		y++;
	}
}
