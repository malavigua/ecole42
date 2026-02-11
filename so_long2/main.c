/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:44:27 by malmany           #+#    #+#             */
/*   Updated: 2026/02/10 10:44:34 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <stdio.h>

t_player	new_player(int x, int y)
{
	t_player	player;

	player.pos_x = x;
	player.pos_y = y;
	player.nb_collectible_collected = 0;
	player.nb_moves = 0;
	player.dir = DIR_UP;
	return (player);
}

int	close_win(t_mlx_data *data)
{
	destroy_all_sprites(data);
	free_t_map(data->map);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

static bool	init_data(t_mlx_data *d, char **argv)
{
	d->map = create_map(argv[1]);
	if (!d->map)
		return (false);
	if (!check_path_valid(d->map))
		return (free_t_map(d->map), false);
	d->mlx = mlx_init();
	if (!d->mlx)
		return (free_t_map(d->map), false);
	d->player = new_player(d->map->start_pos_x, d->map->start_pos_y);
	return (true);
}

static bool	init_window_and_sprites(t_mlx_data *d)
{
	d->win = mlx_new_window(d->mlx,
			d->map->width * 32, d->map->height * 32, "so_long");
	if (!d->win)
		return (false);
	if (!load_all_sprites(d))
		return (close_win(d), false);
	display_map(d);
	display_tile(d, 'X', d->player.pos_x, d->player.pos_y);
	return (true);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if (argc != 2)
		return (write(2, "error\nMust contain 1 parameter, the file name\n",
				46), 1);
	if (!init_data(&data, argv))
		return (1);
	if (!init_window_and_sprites(&data))
		return (1);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_hook(data.win, 17, 1L << 17, close_win, &data);
	mlx_loop(data.mlx);
	return (0);
}
