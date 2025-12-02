/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:39:17 by malmany           #+#    #+#             */
/*   Updated: 2025/11/15 12:48:44 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdlib.h>
#include<stddef.h>
#include<stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void  f_test(unsigned int i, char *c)
{
        if (i % 2 == 0)
		*c = '2';
}


int main()
{
        char s[]= "test";
        ft_striteri(s, &f_test);
        printf("%s\n", s);
}
*/
