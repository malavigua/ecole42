/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_nb_col_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:39:21 by malmany           #+#    #+#             */
/*   Updated: 2026/02/12 10:39:29 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static char	*collected_col(int nb_col_collected, int nb_tot_col)
{
	char	*cur;
	char	*tot;
	char	*res;
	int		len;

	cur = ft_itoa(nb_col_collected);
	if (!cur)
		return (NULL);
	tot = ft_itoa(nb_tot_col);
	if (!tot)
		return (free(cur), NULL);
	len = ft_strlen("Col : ") + ft_strlen(cur) + 1 + ft_strlen(tot) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (free(cur), free(tot), NULL);
	ft_memcpy(res, "Col : ", ft_strlen("Col : "));
	ft_memcpy(res + ft_strlen("Col : "),
		cur, ft_strlen(cur));
	res[ft_strlen("Col : ") + ft_strlen(cur)] = '/';
	ft_memcpy(res + ft_strlen("Col : ") + ft_strlen(cur) + 1,
		tot, ft_strlen(tot));
	res[len - 1] = '\0';
	free(cur);
	free(tot);
	return (res);
}

static void	reset_first_line_wall(t_mlx_data *d)
{
	int	x;

	x = 0;
	while (x < d->map->width)
	{
		mlx_put_image_to_window(d->mlx, d->win,
			d->sprites.obstacle, x * 32, 0);
		x++;
	}
}

void	print_info_first_line(t_mlx_data *d)
{
	char	*s1;
	char	*s2;
	char	*msg;

	reset_first_line_wall(d);
	s1 = ft_itoa(d->player.nb_moves);
	s2 = collected_col(d->player.nb_collectible_collected,
			d->map->nb_collectible);
	if (s1 && s2)
	{
		msg = ft_strjoin("Moves: ", s1);
		if (msg)
		{
			mlx_string_put(d->mlx, d->win, 0, 10, 0xFFFFFF, msg);
			free(msg);
		}
		mlx_string_put(d->mlx, d->win, 0, 25, 0xFFFFFF, s2);
	}
	free(s1);
	free(s2);
}
