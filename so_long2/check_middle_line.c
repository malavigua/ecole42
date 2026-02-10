/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_middle_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:09:42 by malmany           #+#    #+#             */
/*   Updated: 2026/02/10 14:09:45 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	error_rect(void)
{
	write(2, "error\nMap must be rectangular and closed by walls\n", 51);
	return (0);
}

static bool	valid_nb_entry_exit(int nb, char type)
{
	if (nb > 1)
	{
		if (type == 'E')
			write(2, "error\nTo much exit\n", 19);
		else if (type == 'P')
			write(2, "error\nTo much entry\n", 20);
		return (false);
	}
	return (true);
}

static bool	handle_starting_pos(t_map *map, int *nb_p, int x, int y)
{
	map->start_pos_x = x;
	map->start_pos_y = y;
	(*nb_p)++;
	if (!valid_nb_entry_exit(*nb_p, 'P'))
		return (false);
	return (true);
}

static bool	handle_char(char car, int *nb_e, int *nb_c)
{
	if (car == 'E')
	{
		(*nb_e)++;
		if (!valid_nb_entry_exit(*nb_e, 'E'))
			return (false);
	}
	else if (car == 'C')
		(*nb_c)++;
	else if (car != '0' && car != '1' && car != 'P')
		return (write(2, "error\nInvalid character in map\n", 31), false);
	return (true);
}

bool	check_middle_line(char *line, t_map *map, t_counter *count, int pos_y)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(line) -1;
	if (len != map->width || line[0] != '1' || line[len - 1] != '1')
		return (error_rect(), false);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'P'
			&& !handle_starting_pos(map, &(count->nb_p), i, pos_y))
			return (false);
		else if (!handle_char(line[i], &(count->nb_e), &(count->nb_c)))
			return (false);
		i++;
	}
	return (true);
}
