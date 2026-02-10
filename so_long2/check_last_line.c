/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:18:04 by malmany           #+#    #+#             */
/*   Updated: 2026/02/10 14:18:06 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

bool	only_contains_one(char *line)
{
	int	i;

	if (!line)
		return (false);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	check_last_line_length(char *line, int width)
{
	int	i;

	i = ft_strlen(line);
	if (line[i - 1] == '\n')
		return (i - 1 == width);
	return (i == width);
}

bool	check_last_line(char *line, int width)
{
	if (!only_contains_one(line))
		return (write(2, "error\nLast line must contain only walls\n", 41),
			false);
	if (!check_last_line_length(line, width))
		return (write(2, "error\nLast line must match the map width\n", 42),
			false);
	return (true);
}
