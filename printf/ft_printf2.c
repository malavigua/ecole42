/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:05:16 by malmany           #+#    #+#             */
/*   Updated: 2025/11/28 16:25:57 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_char_and_set_res(va_list arg_ptr, int *res)
{
	ft_putchar_fd((char)va_arg(arg_ptr, int), 1);
	*res = *res + 1;
}

void	print_str_and_set_res(va_list arg_ptr, int *res)
{
	char	*str;

	str = va_arg(arg_ptr, char *);
	ft_putstr_fd(str, 1);
	*res = *res + ft_strlen(str);
}

void	print_int_and_set_res(va_list arg_ptr, int *res)
{
	int	i;

	i = va_arg(arg_ptr, int);
	ft_putnbr_fd(i, 1);
	*res = *res + ft_strlen(ft_itoa(i));
}

void	print_unsigned_int(unsigned int i)
{
	char	a;

	if (i > 10)
		print_unsigned_int(i / 10);
	a = i % 10 + '0';
	write(1, &a, 1);
}

void	print_unsigned_int_and_set_res(va_list arg_ptr, int *res)
{
	unsigned int	i;

	i = va_arg(arg_ptr, unsigned int);
	print_unsigned_int(i);
	*res = *res + size_unsigned_int_to_base_n(i, 10);
}
