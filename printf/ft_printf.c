/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:21:54 by malmany           #+#    #+#             */
/*   Updated: 2025/11/28 16:20:33 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <limits.h>

static int	is_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

static void	make_conv_and_print(char conv, va_list arg_ptr, int *res, int *i)
{
	*res = *res - 1;
	if (conv == 'c')
		print_char_and_set_res(arg_ptr, res);
	else if (conv == 's')
		print_str_and_set_res(arg_ptr, res);
	else if (conv == 'p')
		print_pointer_and_set_res(arg_ptr, res);
	else if (conv == 'd' || conv == 'i')
		print_int_and_set_res(arg_ptr, res);
	else if (conv == 'u')
		print_unsigned_int_and_set_res(arg_ptr, res);
	else if (conv == 'x' || conv == 'X')
		print_hex_l_u_and_set_res(arg_ptr, res, conv);
	else
		write(2, "\nconversion not valid\n", 10);
	*i = *i + 1;
}

static int	is_valid_number_of_pct(const char *str, int *i, int *res)
{
	int	j;
	int	is_conv;

	j = 0;
	while (str[j] == '%')
		j++;
	is_conv = is_conversion(str[j]);
	if (j % 2 != 0)
		*i = *i + (j - 2);
	else
		*i = *i + (j - 1);
	if (j % 2 != 0 && !is_conv)
		return (0);
	j = j / 2;
	*res = *res + j - 1;
	while (j > 0)
	{
		write(1, "%", 1);
		j--;
	}
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg_ptr;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(arg_ptr, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (is_conversion(s[i + 1]))
				make_conv_and_print(s[i + 1], arg_ptr, &res, &i);
			else if (s[i + 1] == '%')
				is_valid_number_of_pct(s + i, &i, &res);
			else
				write(2, "\nerror conversion not valid\n", 28);
		}
		else
			write(1, &s[i], 1);
		res++;
		i++;
	}
	return (res);
}

int	main()
{
    void *p;
    p = 0;
    printf("p:%d\n", printf("%p dcds\n", p));
    //ft_printf("p:%d\n", ft_printf("%u\n", UINT_MAX - 2000000000));

    //ft_printf("f:%d\n", ft_printf("%u\n",INT_MIN));  

}
