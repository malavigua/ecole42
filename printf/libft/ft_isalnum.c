/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:47:57 by malmany           #+#    #+#             */
/*   Updated: 2025/11/18 19:13:02 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		|| (c >= '0' && c <= '9'));
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
                printf("valeur de isalnum de %c = %d\n",
                        argv[i][0], isalnum(argv[i][0]));
                printf("valeur de ft_isalnum de %c = %d\n",
                        argv[i][0], ft_isalnum(argv[i][0]));

                i++;
        }

}
*/
