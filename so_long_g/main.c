#include "minilibx-linux/mlx.h"

#include "so_long.h"
#include <stdio.h>
#include "get_next_line.h"
#include <X11/keysym.h>



bool is_valid_file_name(char *filename)
{
	int len;

	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len < 5) // ".ber" + au moins 1 char avant
		return (false);
	if (filename[len - 1] != 'r' || filename[len - 2] != 'e' || filename[len - 3] != 'b' || filename[len - 4] != '.')
		return (false);
	return (true);
}


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

int get_nb_line(char *filename)
{
	int i;
	char *line;
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

static bool check_file(char *filename, int *nb_line)
{
	*nb_line = get_nb_line(filename);
	if (!is_valid_file_name(filename))
		return (write(2, "error\nMap must be a .ber file\n", 29), false);
	if (*nb_line <= 0)
		return (write(2, "error\nMap is empty\n", 19), false);
	if (*nb_line < 3)
		return (write(2, "error\nMap must contain at least 3 lines\n", 41), false);
	return (true);
}

t_map *new_map(int height)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		return NULL;
	map->data = malloc(sizeof(char *) * (height + 1));
	if (!map->data)
	{
		free(map);
		return NULL;
	}
	map->data[height] = NULL;
	map->height = height;
	map->width = 0;
	map->start_pos_x = 0;
	map->start_pos_y = 0;
	map->nb_collectible = 0;
	return map;
}

int error_wall_top(void)
{
	write(2, "error\nFirst line must contain only walls\n", 42);
	return (0);
}

int error_rect(void)
{
	write(2, "error\nMap must be rectangular and closed by walls\n", 51);
	return (0);
}

void clear_map_data(char **data, int size)
{
	int i;
	if (!data)
		return;

	i = 0;
	while (i < size)
	{
		free(data[i]);
		i++;
	}
	free(data);
}

void free_t_map(t_map *map)
{
	if (!map)
		return;
	clear_map_data(map->data, map->height);
	free(map);
}

t_counter init_counter(void)
{
	t_counter c;

	c.nb_c = 0;
	c.nb_p = 0;
	c.nb_e = 0;
	return (c);
}

bool    valid_nb_entry_exit(int nb, char type)
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

bool handle_starting_pos(t_map *map, int *nb_p, int x, int y)
{
    map->start_pos_x = x;
    map->start_pos_y = y;
    (*nb_p)++;
    if (!valid_nb_entry_exit(*nb_p, 'P'))
        return false;
    return true;
}

bool    handle_char(char car, int *nb_e, int *nb_c)
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

bool check_middle_line(char *line, t_map *map, t_counter *count, int pos_y)
{
	int len;
	int i;

	i = 0;
 	len = ft_strlen(line) -1;
	if (len != map->width || line[0] != '1' || line[len - 1] != '1')
		return (error_rect(), false);
	while (line[i] && line[i] != '\n')
    {
		if (line[i] == 'P' && !handle_starting_pos(map, &(count->nb_p), i, pos_y))
    		return (false);
		else  if (!handle_char(line[i], &(count->nb_e), &(count->nb_c)))
            return (false);
        i++;
    }
	return (true);
}

bool check_at_least_one_c_e_p(t_counter count)
{
    bool has_error;

    has_error = false;
    if (count.nb_c == 0)
    {
        if (!has_error)
            write(2, "error\n", 6);
        write(2, " - There must be at least one collectible\n", 42);
        has_error = true;
    }
    if (count.nb_p == 0)
    {
        if (!has_error) 
            write(2, "error\n", 6);
        write(2, " - There must be at least one entry\n", 36);
        has_error = true;
    }
    if (count.nb_e == 0)
    {
        if (!has_error)
            write(2, "error\n", 6);
        write(2, " - There must be at least one exit\n", 35);
        has_error = true;
    }
    return !has_error;
}

bool check_last_line_length(char *line, int width)
{
	int i;

	i = ft_strlen(line);
	if(line[i-1] =='\n')
		return(i == width);
	return(i == width -1);
}

bool check_last_line(char *line, int width)
{

	if (!only_contains_one(line))
        return(write(2, "error\nLast line must contain only walls\n", 41), false);
	if(!check_last_line_length(line, width))
		return(write(2, "error\nLast line must match the map width\n", 42), false);
	return (true);
}

bool fill_and_check_map(int fd, t_map *map)
{
	char *line;
	int width;
	int i;
	t_counter count;

	count = init_counter();
	i = 0;
	line = get_next_line(fd);
	if (!line || !only_contains_one(line))
		return (free(line), error_wall_top(), false);
	width = ft_strlen(line);
	map->data[i++] = line;
	map->width = width -1;
	while (i < map->height - 1)
	{
		line = get_next_line(fd);
		if (!line || !check_middle_line(line, map, &count, i))
			return (free(line), clear_map_data(map->data, i), false);
		map->data[i++] = line;
	}
	line = get_next_line(fd);
	if (!line || !check_last_line(line, width) || !check_at_least_one_c_e_p(count))
		return (free(line), clear_map_data(map->data, i), false);
	map->data[i] = line;
	map->nb_collectible =count.nb_c;
	return (true);
}

t_map *create_map(char *filename)
{
	int fd;
	int nb_line;
	t_map *map;

	if (!check_file(filename, &nb_line))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, "error\nCan not open the file\n", 28), NULL);
	map = new_map(nb_line);
	if (!map)
		return (close(fd), NULL);
	if (!fill_and_check_map(fd, map))
		return (close(fd), free(map), NULL);
	close(fd);
	return map;
}

void    free_visited(bool **v, int h)
{
    int i;

    i = 0;
    while (i < h)
        free(v[i++]);
    free(v);
}

bool    **alloc_visited(int h, int w)
{
    bool    **v;
    int     i;
    int     j;

    i = 0;
    v = malloc(sizeof(bool *) * h);
    if (!v)
        return (NULL);
    while (i < h)
    {
        v[i] = malloc(sizeof(bool) * w);
        if (!v[i])
            return (free_visited(v, i), NULL);
        j = 0;
        while (j < w)
            v[i][j++] = false;
        i++;
    }
    return (v);
}

void    flood_fill(t_map *map, bool **v, int x, int y)
{
    if (x < 0 || y < 0 || x >= map->width || y >= map->height)
        return;
    if (v[y][x] || map->data[y][x] == '1')
        return;
    v[y][x] = true;
    flood_fill(map, v, x + 1, y);
    flood_fill(map, v, x - 1, y);
    flood_fill(map, v, x, y + 1);
    flood_fill(map, v, x, y - 1);
}

bool    check_reachable(t_map *map, bool **v)
{
    int i;
    int j;
    int c;
    int exit;

    i = 0;
    c = 0;
    exit = 0;
    while (map->data[i])
    {
        j = 0;
        while (map->data[i][j] && map->data[i][j] != '\n')
        {
            if (map->data[i][j] == 'C' && v[i][j])
                c++;
            if (map->data[i][j] == 'E' && v[i][j])
                exit = 1;
            j++;
        }
        i++;
    }
    
    return (c == map->nb_collectible && exit);
}


bool    check_path_valid(t_map *map)
{
    bool    **v;
    bool    ok;

    v = alloc_visited(map->height, map->width);
    if (!v)
        return (false);
    flood_fill(map, v, map->start_pos_x, map->start_pos_y);
    ok = check_reachable(map, v);
    free_visited(v, map->height);
    if (!ok)
        write(2, "error\nNo valid path\n", 20);
    return (ok);
}

void    destroy_all_sprites(t_mlx_data *d)
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

int close_win(t_mlx_data *data)
{
    destroy_all_sprites(data);
    free_t_map(data->map);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
}



void    *load_img(void *mlx, char *path, int *w, int *h)
{
    void    *img;

    img = mlx_xpm_file_to_image(mlx, path, w, h);
    if (!img)
    {
        write(2, "error\nFailed to load image: ", 28);
        write(2, path, ft_strlen(path));
        write(2, "\n", 1);
    }
    return (img);
}

bool    load_all_sprites(t_mlx_data *d)
{
    t_sprites *s;
    s = &d->sprites;

    s->w = 32;
    s->h = 32;

    s->background = load_img(d->mlx, "img/background.xpm", &s->w, &s->h);
    s->obstacle = load_img(d->mlx, "img/wall2.xpm", &s->w, &s->h);
    s->player = load_img(d->mlx, "img/player.xpm", &s->w, &s->h);
    s->player_left = load_img(d->mlx, "img/player-left.xpm", &s->w, &s->h);
    s->player_right = load_img(d->mlx, "img/player-right.xpm", &s->w, &s->h);
    s->collectible = load_img(d->mlx, "img/collectible.xpm", &s->w, &s->h);
    s->entry = load_img(d->mlx, "img/entry2.xpm", &s->w, &s->h);
    s->exit = load_img(d->mlx, "img/exit2.xpm", &s->w, &s->h);

    if (!s->background || !s->obstacle || !s->player || !s->player_left
        || !s->player_right ||!s->collectible || !s->entry || !s->exit)
        return (false);

    return (true);
}

static void display_player(t_mlx_data *d, int x, int y)
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


static void display_tile(t_mlx_data *d, char c, int x, int y)
{
    mlx_put_image_to_window(d->mlx, d->win, d->sprites.background, x * 32, y * 32);

    if (c == '1')
        mlx_put_image_to_window(d->mlx, d->win, d->sprites.obstacle, x * 32, y * 32);
    else if (c == 'C')
        mlx_put_image_to_window(d->mlx, d->win, d->sprites.collectible, x * 32, y * 32);
    else if (c == 'E')
        mlx_put_image_to_window(d->mlx, d->win, d->sprites.exit, x * 32, y * 32);
    else if (c == 'P')
            mlx_put_image_to_window(d->mlx, d->win, d->sprites.entry, x * 32, y * 32);
    else if (c == 'X')
        display_player(d, x, y);

}

void    display_map(t_mlx_data *d)
{
    int x;
    int y;

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

static bool	can_move_to(t_mlx_data *d, int nx, int ny)
{
	char	next;

	if (nx < 0 || ny < 0 || nx >= d->map->width || ny >= d->map->height)
		return (false);
	next = d->map->data[ny][nx];
	if (next == '1' || next == 'P')
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
		printf("Collectibles: %d/%d\n",
			d->player.nb_collectible_collected,
			d->map->nb_collectible);
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
	printf("Moves: %d\n", d->player.nb_moves);
}

void	move_player(t_mlx_data *d, int dx, int dy)
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
	if (next == 'E'
		&& d->player.nb_collectible_collected == d->map->nb_collectible)
	{
		printf("Level completed!\n");
		close_win(d);
	}
}


int handle_input(int keysym, t_mlx_data *d)
{
    if (keysym == XK_Escape)
        close_win(d);
    else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
    {
        d->player.dir = DIR_LEFT;
        move_player(d, -1, 0);
    }
    else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
    {
        d->player.dir = DIR_RIGHT;
        move_player(d, 1, 0);
    }
    else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
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

t_player new_player(int x, int y)
{
    t_player player;

    player.pos_x = x;
    player.pos_y = y;
    player.nb_collectible_collected = 0;
    player.nb_moves = 0;
    player.dir = DIR_UP;

    return player;

}


static bool init_data(t_mlx_data *d, char **argv)
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

static bool init_window_and_sprites(t_mlx_data *d)
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

int main(int argc, char **argv)
{
    t_mlx_data  data;

    if (argc != 2)
        return (write(2, "error\nMust contain 1 parameter, the file name\n", 46), 1);
    if (!init_data(&data, argv))
        return (1);
    if (!init_window_and_sprites(&data))
        return (1);
    mlx_key_hook(data.win, handle_input, &data);
    mlx_hook(data.win, 17, 1L << 17, close_win, &data);
    mlx_loop(data.mlx);
    return (0);
}


