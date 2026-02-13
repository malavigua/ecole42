/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:48:16 by malmany           #+#    #+#             */
/*   Updated: 2026/02/10 15:48:18 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	a = n % 10 + '0';
	write(fd, &a, 1);
}

static int	size_int_to_char(long int n)
{
	int	res;

	res = 1;
	if (n < 0)
	{
		n = -n;
		res++;
	}
	while (n / 10 > 0)
	{
		res++;
		n = n / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char		*str;
	long		nb;
	int			len;

	nb = n;
	len = size_int_to_char(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	const unsigned char		*s;
	unsigned char			*d;

	if (n == 0 || dest == src)
		return (dest);
	if (n > 0)
	{
		i = 0;
		s = (unsigned char *)src;
		d = (unsigned char *)dest;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		j;
	int		i;
	char	*res;

	j = 0;
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(size);
	if (!res)
		return (NULL);
	while (s1[j])
	{
		res[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		res[j] = s2[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}
