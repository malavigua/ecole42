NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c get_next_line.c get_next_line_utils.c check_path.c map.c \
		check_file.c check_middle_line.c check_first_last_line.c \
		create_map.c sprites.c handle_input.c display.c\
		func_util.c display_nb_col_moves_bonus.c
OBJ = $(SRC:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLXFLAGS = -lX11 -lXext -lm

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_LIB) $(MLXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX_LIB)
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
