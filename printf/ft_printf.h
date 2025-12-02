
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

void    print_char_and_set_res(va_list arg_ptr, int *res);
void    print_str_and_set_res(va_list arg_ptr, int *res);
void    print_int_and_set_res(va_list arg_ptr, int *res);
void    print_unsigned_int(unsigned int i);
void    print_unsigned_int_and_set_res(va_list arg_ptr, int *res);
void    print_hexa(uintptr_t u, char c);
void    print_pointer_and_set_res(va_list arg_ptr, int *res);
int size_unsigned_int_to_base_n(uintptr_t u, int n);
void    print_hex_l_u_and_set_res(va_list arg_ptr, int *res, char conv);
 int ft_printf(const char *s, ...);
#endif
