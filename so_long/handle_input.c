/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:00:38 by malmany           #+#    #+#             */
/*   Updated: 2026/02/10 15:00:40 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include<stdio.h>

static bool	can_move_to(t_mlx_data *d, int nx, int ny)
{
	char	next;

	if (nx < 0 || ny < 0 || nx >= d->map->width || ny >= d->map->height)
		return (false);
	next = d->map->data[ny][nx];
	if (next == '1')
		return (false);
	if (next == 'E'
		&& d->player.nb_collectible_collected < d->map->nb_collectible)
		return (false);
	return (true);
}

static void	handle_collectible(t_mlx_data *d, int nx, int ny)
{
	if (d->map->data[ny][nx] == 'C')
	{
		d->player.nb_collectible_collected++;
		d->map->data[ny][nx] = '0';
		write(1, "Collectibles :", 14);
		ft_putnbr_fd(d->player.nb_collectible_collected, 1);
		write(1, "/", 1);
		ft_putnbr_fd(d->map->nb_collectible, 1);
		write(1, "\n", 1);
	}
}

static void	update_player_pos(t_mlx_data *d, int nx, int ny)
{
	display_tile(d,
		d->map->data[d->player.pos_y][d->player.pos_x],
		d->player.pos_x, d->player.pos_y);
	d->player.pos_x = nx;
	d->player.pos_y = ny;
	display_tile(d, 'X', d->player.pos_x, d->player.pos_y);
	d->player.nb_moves++;
	write(1, "Moves :", 7);
	ft_putnbr_fd(d->player.nb_moves, 1);
	write(1, "\n", 1);
}

static void	move_player(t_mlx_data *d, int dx, int dy)
{
	int		nx;
	int		ny;
	char	next;

	nx = d->player.pos_x + dx;
	ny = d->player.pos_y + dy;
	if (!can_move_to(d, nx, ny))
		return ;
	next = d->map->data[ny][nx];
	handle_collectible(d, nx, ny);
	update_player_pos(d, nx, ny);
	print_info_first_line(d);
	if (next == 'E'
		&& d->player.nb_collectible_collected == d->map->nb_collectible)
	{
		write(1, "Level completed!\n", 17);
		close_win(d);
	}
}

int	handle_input(int keysym, t_mlx_data *d)
{
	if (keysym == XK_Escape)
		close_win(d);
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left
		|| keysym == XK_q || keysym == XK_Q)
	{
		d->player.dir = DIR_LEFT;
		move_player(d, -1, 0);
	}
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
	{
		d->player.dir = DIR_RIGHT;
		move_player(d, 1, 0);
	}
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up
		|| keysym == XK_z || keysym == XK_Z)
	{
		d->player.dir = DIR_UP;
		move_player(d, 0, -1);
	}
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
	{
		d->player.dir = DIR_DOWN;
		move_player(d, 0, 1);
	}
	return (0);
}
