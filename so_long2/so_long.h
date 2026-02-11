/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:47:02 by malmany           #+#    #+#             */
/*   Updated: 2026/02/10 15:55:29 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <X11/keysym.h>

// ===== STRUCTS =====

typedef struct s_map
{
	char	**data;
	int		height;
	int		width;
	int		start_pos_x;
	int		start_pos_y;
	int		nb_collectible;
}	t_map;

typedef struct s_counter
{
	int	nb_c;
	int	nb_e;
	int	nb_p;
}	t_counter;

typedef struct s_sprites
{
	void	*background;
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*obstacle;
	void	*collectible;
	void	*entry;
	void	*exit;
	int		w;
	int		h;
}	t_sprites;

typedef enum e_dir
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
}	t_dir;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		nb_collectible_collected;
	int		nb_moves;
	t_dir	dir;
}	t_player;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	t_sprites	sprites;
	t_map		*map;
	t_player	player;
}	t_mlx_data;

// map
t_map	*new_map(int height);
void	clear_map_data(char **data, int size);
void	free_t_map(t_map *map);

//check map file and is stucture
bool	is_valid_file(char *filename, int *nb_line);
bool	check_middle_line(char *line, t_map *map, t_counter *count, int pos_y);
bool	only_contains_one(char *line);
bool	check_last_line(char *line, int width);
t_map	*create_map(char *filename);

// check pqth
bool	check_path_valid(t_map *map);

// ===== Sprites =====
void	destroy_all_sprites(t_mlx_data *d);
bool	load_all_sprites(t_mlx_data *d);

// function for key_hook
int		handle_input(int keysym, t_mlx_data *d);

// diplay map and the images
void	display_tile(t_mlx_data *d, char c, int x, int y);
void	display_map(t_mlx_data *d);

// close window
int		close_win(t_mlx_data *data);

//
void	ft_putnbr_fd(int n, int fd);
char    *ft_itoa(int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*collected_col(int nb_col_collected, int nb_tot_col);
void	reset_first_line_wall(t_mlx_data *d);
void	print_info_first_line(t_mlx_data *d);
#endif
