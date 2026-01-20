/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:34:54 by malmany           #+#    #+#             */
/*   Updated: 2026/01/20 20:23:53 by malmany          ###   ########.fr       */
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
	int			value;
	int			index;
	int			push_cost;
	bool		is_above_median;
	bool		is_cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*prev;
	struct s_stack_node		*next;
}	t_stack_node;

t_stack_node	*ft_stack_node_new(int value);
void			ft_stack_add_front(t_stack_node **st, t_stack_node *new);
int	ft_stack_size(t_stack_node *st);
t_stack_node	*ft_stack_last(t_stack_node *st);
void			ft_stack_delone(t_stack_node *st);
void			ft_satck_clear(t_stack_node **st);
void			ft_stack_print(t_stack_node *st);
bool			ft_stack_is_sorted_asc(t_stack_node *st);
t_stack_node	*ft_stack_new(int *tab, int size);

t_stack_node    *ft_stack_get_max(t_stack_node *st);
void    ft_set_index_and_above_median(t_stack_node *st);
void    ft_set_target_a_from_b(t_stack_node *a, t_stack_node *b);
void    ft_set_push_cost(t_stack_node *st1, t_stack_node *st2);
void    ft_set_cheapest(t_stack_node *st);
t_stack_node    *ft_get_cheapest(t_stack_node *st);
void    ft_move_cheapest_a_to_b(t_stack_node **a, t_stack_node **b);
void verify_and_set_top_before_push(t_stack_node **st, t_stack_node *to_be_top, char stack_name);
/*stack sorting operation functions*/
void			ft_stack_swap(t_stack_node *st, char stack_name, bool print);
void			ft_stack_push(t_stack_node **from, t_stack_node **to,
					char stack_name, bool print);
void			ft_stack_rotate(t_stack_node **st, char stack_name, bool print);
void    		ft_stack_rotate_both(t_stack_node **a, t_stack_node **b, bool print);
void			ft_stack_reverse_rotate(t_stack_node **st, char stack_name,
					bool print);
void			ft_stack_reverse_rotate_both(t_stack_node **a, t_stack_node **b, bool print);
/* stack sorting functions*/
void	ft_stack_sort_three(t_stack_node **st);
void    ft_sort_stack(t_stack_node **a, t_stack_node **b);
#endif
