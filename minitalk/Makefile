CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME_CLIENT = client
NAME_SERVER = server

SRC_CLIENT = client.c
SRC_SERVER = server.c
HEADER = minitalk.h

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(SRC_CLIENT) $(HEADER)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER) $(HEADER)
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

clean:
	echo "Nothing to clean."

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
