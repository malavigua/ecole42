#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"

// ===== STRUCTS =====

typedef struct s_map 
{
    char **data;
    int height;
    int width;
    int	start_pos_x;
    int	start_pos_y;
    int	nb_collectible;
} t_map;



typedef struct s_counter
{
    int nb_c;  // Collectibles
    int nb_e;  // Exits
    int nb_p;  // Entries
} t_counter;

typedef struct s_sprites
{
    void    *background;
    void    *player;
    void    *player_left;
    void    *player_right;
    void    *obstacle;
    void    *collectible;
    void    *entry;
    void    *exit;
    int     w;
    int     h;
}   t_sprites;

typedef enum e_dir
{
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
}   t_dir;

typedef struct s_player
{
    int     pos_x;
    int     pos_y;
    int     nb_collectible_collected;
    int     nb_moves;
    t_dir   dir;
}   t_player;


typedef struct s_mlx_data
{
    void        *mlx;
    void        *win;
    t_sprites   sprites;
    t_map       *map;
    t_player    player;
}   t_mlx_data;






#endif

