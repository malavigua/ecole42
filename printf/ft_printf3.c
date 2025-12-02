/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:14:37 by malmany           #+#    #+#             */
/*   Updated: 2025/11/28 16:31:15 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_hexa(uintptr_t u, char c)
{
	char	*hexa;

	hexa = malloc(16);
	if (!hexa)
		return ;
	if (c == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (u >= 16)
		print_hexa(u / 16, c);
	write(1, &hexa[u % 16], 1);
}

int size_unsigned_int_to_base_n(uintptr_t u, int base)
{
    int i;
    i = 1;
    while ( u >= (uintptr_t)base)
    {
        i++;
        u = u/base;
    }
    return i;
}

void	print_pointer_and_set_res(va_list arg_ptr, int *res)
{
	uintptr_t	u;
	void		*p;

	p = va_arg(arg_ptr, void *);
	if (!p)
	{
		write(2, "NIL", 3);
		return ;
	}
	u = (uintptr_t)p;
	write(1, "0x", 2);
    *res = *res + 2;
	print_hexa(u, 'x');
    *res = *res + size_unsigned_int_to_base_n(u, 16);
}

void	print_hex_l_u_and_set_res(va_list arg_ptr, int *res, char conv)
{
	unsigned int	i;

	i = va_arg(arg_ptr, unsigned int);
	print_hexa((uintptr_t) i, conv);
    *res = *res + size_unsigned_int_to_base_n((uintptr_t) i, 16);

}
