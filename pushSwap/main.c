/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:13:43 by malmany           #+#    #+#             */
/*   Updated: 2026/01/21 18:23:06 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stack.h"
#include <stdio.h>

bool	is_number(char *c)
{
	int	i;

	if (!c)
		return (false);
	i = 0;
	if (c[0] == '+' || c[0] == '-')
		i++;
	while (c[i])
	{
		if(!(c[i] >= '0' && c[i] <= '9'))
			return(false);
		i++;
	}
	return (true);
}

long	ft_atol(char *s)
{
	int	i;
	long	res;
	int	mul;

	res = 0;
	i = 0;
	mul = 1;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if ((s[i] == '-' || s[i] == '+'))
	{
		if (s[i] == '-')
			mul *= -1;
		i++;
	}
	while((s[i] >= '0' && s[i] <= '9'))
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * mul);
}

bool contains_duplicate(int *int_tab, int size_int_tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_int_tab)
	{
		j = i + 1;
		while (j < size_int_tab)
		{
			if (int_tab[i] == int_tab[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool is_all_num(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if(!is_number(argv[i]))
		{
			write(1, "Error\n", 6);
                        return(false);
		}
		i++;
	}
	return(true);
}

int	*create_int_tab(int argc, char **argv)
{
	int * int_tab;
	int	i;
	long	l;

	int_tab = malloc(sizeof(int) * (argc-1));
        i = 1;

        while (i < argc)
        {
                l = ft_atol(argv[i]);
                if(l >= INT_MIN && l <= INT_MAX)
                        int_tab[i-1]=l;
                else
                {
                        write(1, "Error\n", 6);
                        free(int_tab);
                        return(NULL);
                }
                i++;
        }
	return(int_tab);

}

int	main(int argc, char **argv)
{
	int	*int_tab;
	t_stack_node *a;
	t_stack_node *b;

	b = NULL;
	if (argc < 2 || !is_all_num(argc, argv))
		return (0);
	
	int_tab = create_int_tab(argc, argv);
	if(!int_tab)
		return(1);
	if(contains_duplicate(int_tab, argc-1))
	{
		write(1, "Error\n", 6);
		free(int_tab);
		return(1);
	}
	a = ft_stack_new(int_tab, argc-1);
	ft_sort_stack(&a, &b);
	ft_stack_clear(&a);
	return (0);
}








