CC = cc
CFLAGS = -Wall -Wextra 
SRC =  ft_printf.c ft_printf2.c ft_printf3.c
NAME = libftprintf.a
OBJ = $(SRC:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all : $(LIBFT) $(NAME)

$(LIBFT) :
	make -C $(LIBFT_DIR)

.c.o :
	$(CC) $(CFLAGS) -I. -c $< -o $@ 

$(NAME): $(OBJ) $(LIBFT)
	ar -x $(LIBFT)
	ar rcs $(NAME) *.o

clean : 
	$(RM) *.o
	make clean -C ./libft

fclean : clean
	$(RM) $(NAME) 
	make fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re
