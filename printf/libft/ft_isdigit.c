/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:33:39 by malmany           #+#    #+#             */
/*   Updated: 2025/11/10 12:45:49 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
        int i;
        i = 1;

        while( i < argc)
        {
                printf("valeur de isdigit de %c = %d\n", 
                        argv[i][0], isdigit(argv[i][0]));
                printf("valeur de ft_isdigit de %c = %d\n", 
                        argv[i][0], ft_isdigit(argv[i][0]));

                i++;
        }

}
*/
