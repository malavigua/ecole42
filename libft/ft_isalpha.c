/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:27:22 by malmany           #+#    #+#             */
/*   Updated: 2025/11/10 12:58:54 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z'));
}

/*
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i;
	i = 1;

	while( i < argc)
	{
		printf("valeur de isalpha de %c = %d\n", 
			argv[i][0], isalpha(argv[i][0]));
                printf("valeur de ft_isalpha de %c = %d\n", 
			argv[i][0], ft_isalpha(argv[i][0]));

		i++;
	}

}*/
