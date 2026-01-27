CC = cc

CFLAGS = -Wall -Wextra -Werror

COMMON_SRC = ft_split.c ft_stack.basic1.c ft_stack.basic2.c\
			ft_stack_basic_op1.c ft_stack_basic_op2.c\
			ft_func_for_mains1.c ft_func_for_mains2.c\

MAIN_SRC =  ft_func_sort_stack1.c ft_func_sort_stack2.c\
			ft_func_sort_stack3.c ft_main_pushswap.c ft_stack_sort_min_max.c\

BONUS_SRC = ft_func_for_checker_bonus.c ft_main_checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

NAME = push_swap

NAME_BONUS = checker

COMMON_OBJ =  $(COMMON_SRC:.c=.o)
MAIN_OBJ = $(MAIN_SRC:.c=.o)
ALL_MAIN_OBJ = $(COMMON_SRC:.c=.o) $(MAIN_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
ALL_BONUS_OBJ = $(COMMON_SRC:.c=.o) $(BONUS_SRC:.c=.o)
ALL_OBJ = $(COMMON_OBJ) $(MAIN_OBJ) $(BONUS_OBJ)


all : $(NAME)

bonus : $(NAME_BONUS)

.c.o :
	$(CC) $(CFLAGS) -I. -c $< -o $@ 

$(NAME) : $(ALL_MAIN_OBJ)
	$(CC) $(CFLAGS) $(ALL_MAIN_OBJ) -o $(NAME)

$(NAME_BONUS) : $(ALL_BONUS_OBJ)
	$(CC) $(CFLAGS) $(ALL_BONUS_OBJ) -o $(NAME_BONUS)

clean : 
	$(RM) $(ALL_OBJ)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re
