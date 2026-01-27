/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:34:54 by malmany           #+#    #+#             */
/*   Updated: 2026/01/27 12:50:28 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_STACK_H
# define FT_STACK_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				is_above_median;
	bool				is_cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

/* stack basic functions in file ft_stack_basic1.c && ft_stack_basic2.c*/
t_stack_node	*ft_stack_node_new(int value);

void			ft_stack_add_front(t_stack_node **st, t_stack_node *new);

int				ft_stack_size(t_stack_node *st);

t_stack_node	*ft_stack_last(t_stack_node *st);

void			ft_stack_add_back(t_stack_node **st, t_stack_node *new);

void			ft_stack_delone(t_stack_node *st);

void			ft_stack_clear(t_stack_node **st);

t_stack_node	*ft_stack_new(int *tab, int size);

bool			ft_stack_is_sorted_asc(t_stack_node *st);

/*stack  basic operation functions 
 * in ft_stack_basic_op1.c && ft_stack_basic_op2.c*/

void			ft_stack_swap(t_stack_node *st, char stack_name, bool print);

void			ft_stack_swap_both(t_stack_node *a, t_stack_node *b,
					bool print);

void			ft_stack_push(t_stack_node **from, t_stack_node **to,
					char stack_name, bool print);

void			ft_stack_rotate(t_stack_node **st, char stack_name, bool print);

void			ft_stack_rotate_both(t_stack_node **a, t_stack_node **b,
					bool print);

void			ft_stack_reverse_rotate(t_stack_node **st, char stack_name,
					bool print);

void			ft_stack_reverse_rotate_both(t_stack_node **a, t_stack_node **b,
					bool print);

/* stack sorting functions and get max and min of a stack 
 * in ft_stack_sort_min_max.c*/
;
t_stack_node	*ft_stack_get_max(t_stack_node *st);

t_stack_node	*ft_stack_get_min(t_stack_node *st);

void			ft_stack_sort_three(t_stack_node **st);

void			ft_stack_sort_size_greater_three(t_stack_node **a,
					t_stack_node **b);

void			ft_sort_stack(t_stack_node **a, t_stack_node **b);

/* functions used in ft_sort_stack 
 * in ft_func_sort_stack1.c && ft_func_sort_stack2.c && ft_func_sort_stack3.c*/

void			ft_set_index_and_above_median(t_stack_node *st);

void			ft_set_target_a_from_b(t_stack_node *a, t_stack_node *b);

int				ft_get_cost(t_stack_node *st, int size_st);

int				get_push_cost(t_stack_node *st1, int size_st1, int size_st2);

void			ft_set_push_cost(t_stack_node *st1, t_stack_node *st2);

void			ft_set_cheapest(t_stack_node *st);

t_stack_node	*ft_get_cheapest(t_stack_node *st);

void			ft_set_target_b_from_a(t_stack_node *a, t_stack_node *b);

void			ft_verify_and_set_top_before_push(t_stack_node **st,
					t_stack_node *to_be_top, char stack_name);

void			ft_verify_and_set_stacks(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);

void			ft_move_cheapest_a_to_b(t_stack_node **a, t_stack_node **b);

void			ft_set_a_before_push_to_b(t_stack_node **a, t_stack_node **b);

void			ft_set_min_at_top(t_stack_node **a);

/* split in ft_split.c */

char			**ft_split(char const *s, char c);

/* functions used in both main */
/*files : ft_func_for_mains1.c && ft_func_for_mains2.c*/

bool			ft_is_number(char *c);

long			ft_atol(char *s);

bool			ft_contains_duplicate(int *int_tab, int size_int_tab);

bool			ft_is_all_num(int size_args, char **args);

int				*ft_create_int_tab(int size_args, char **args);

bool			ft_get_args_and_sizeargs(int argc, char **argv, char ***args,
					int *size_args);

bool			ft_parse_and_validate(char **args, int size_args,
					int **int_tab);

void			ft_clean_args_split(char **args, int argc);

/*functions for checker in ft_func_for_checker.c*/
int				ft_strcmp(const char *s1, const char *s2);

bool			ft_make_op_to_stack(t_stack_node **a, t_stack_node **b,
					char *line);

bool			ft_read_and_apply_op(t_stack_node **a, t_stack_node **b);

void			ft_clean_stacks_and_args(t_stack_node **a, t_stack_node **b,
					char **args, int argc);

void			ft_verify_stack_is_sorted(t_stack_node *a, t_stack_node *b);

#endif
