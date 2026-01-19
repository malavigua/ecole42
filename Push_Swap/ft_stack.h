
#ifndef FT_STACK_H
# define FT_STACK_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdbool.h>

typedef struct s_stack_node
{
	int         value;
    int         index;
    int         push_cost;
    bool        is_above_median;
    bool        is_cheapest;
    struct s_stack_node   *target_node;
    struct s_stack_node   *prev;
	struct s_stack_node   *next;
}	t_stack_node;

t_stack_node  *ft_stack_node_new(int value);
void	ft_stack_add_front(t_stack_node **st, t_stack_node *new);
size_t  ft_stack_size(t_stack_node *st);
t_stack_node *ft_stack_last(t_stack_node *st);
void    ft_stack_delone(t_stack_node *st);
void	ft_satck_clear(t_stack_node **st);
void    ft_stack_print(t_stack_node *st);
bool ft_stack_is_sorted_asc(t_stack_node *st);
t_stack_node  *ft_stack_new(int * tab, size_t size);
void ft_stack_swap(t_stack_node *st, char stack_name);
void    ft_stack_push(t_stack_node **from, t_stack_node **to, char stack_name);
void ft_stack_rotate(t_stack_node **st, char stack_name, bool print);
void ft_stack_reverse_rotate(t_stack_node **st, char stack_name, bool print);

#endif
