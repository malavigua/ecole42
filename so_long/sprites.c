/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:53:37 by malmany           #+#    #+#             */
/*   Updated: 2026/02/10 14:53:40 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	destroy_all_sprites(t_mlx_data *d)
{
	if (d->sprites.background)
		mlx_destroy_image(d->mlx, d->sprites.background);
	if (d->sprites.obstacle)
		mlx_destroy_image(d->mlx, d->sprites.obstacle);
	if (d->sprites.player)
		mlx_destroy_image(d->mlx, d->sprites.player);
	if (d->sprites.player_left)
		mlx_destroy_image(d->mlx, d->sprites.player_left);
	if (d->sprites.player_right)
		mlx_destroy_image(d->mlx, d->sprites.player_right);
	if (d->sprites.collectible)
		mlx_destroy_image(d->mlx, d->sprites.collectible);
	if (d->sprites.entry)
		mlx_destroy_image(d->mlx, d->sprites.entry);
	if (d->sprites.exit)
		mlx_destroy_image(d->mlx, d->sprites.exit);
}

static void	*load_img(void *mlx, char *path, int *w, int *h)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, w, h);
	if (!img)
	{
		write(2, "error\nFailed to load image: ", 28);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
	}
	return (img);
}

bool	load_all_sprites(t_mlx_data *d)
{
	t_sprites	*s;

	s = &d->sprites;
	s->w = 32;
	s->h = 32;
	s->background = load_img(d->mlx, "textures/background.xpm", &s->w, &s->h);
	s->obstacle = load_img(d->mlx, "textures/wall2.xpm", &s->w, &s->h);
	s->player = load_img(d->mlx, "textures/player.xpm", &s->w, &s->h);
	s->player_left = load_img(d->mlx, "textures/player-left.xpm", &s->w, &s->h);
	s->player_right = load_img(d->mlx, "textures/player-right.xpm", &s->w,
			&s->h);
	s->collectible = load_img(d->mlx, "textures/collectible.xpm", &s->w, &s->h);
	s->entry = load_img(d->mlx, "textures/entry2.xpm", &s->w, &s->h);
	s->exit = load_img(d->mlx, "textures/exit2.xpm", &s->w, &s->h);
	if (!s->background || !s->obstacle || !s->player || !s->player_left
		|| !s->player_right ||!s->collectible || !s->entry || !s->exit)
		return (false);
	return (true);
}
