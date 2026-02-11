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
	if (n > 10)
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

char    *ft_itoa(int n)
{
    char        *str;
    long        nb;
    int         len;

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

char	*collected_col(int nb_col_collected, int nb_tot_col)
{
	char	*cur;
	char	*tot;
	char	*res;
	int		len;

	cur = ft_itoa(nb_col_collected);
	if (!cur)
		return (NULL);
	tot = ft_itoa(nb_tot_col);
	if (!tot)
		return (free(cur), NULL);
	len = ft_strlen("Collectibles : ") + ft_strlen(cur) + 1 + ft_strlen(tot) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (free(cur), free(tot), NULL);
	ft_memcpy(res, "Collectibles : ", ft_strlen("Collectibles : "));
	ft_memcpy(res + ft_strlen("Collectibles : "),
		cur, ft_strlen(cur));
	res[ft_strlen("Collectibles : ") + ft_strlen(cur)] = '/';
	ft_memcpy(res + ft_strlen("Collectibles : ") + ft_strlen(cur) + 1,
		tot, ft_strlen(tot));
	res[len - 1] = '\0';
	free(cur);
	free(tot);
	return (res);
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

void	reset_first_line_wall(t_mlx_data *d)
{
	int	x;

	x = 0;
	while (x < d->map->width)
	{
		mlx_put_image_to_window(d->mlx, d->win,
			d->sprites.obstacle, x * 32, 0);
		x++;
	}
}


void	print_info_first_line(t_mlx_data *d)
{
	char *s1;
	char *s2;
	char *msg;

	reset_first_line_wall(d);

	s1 = ft_itoa(d->player.nb_moves);
	s2 = collected_col(d->player.nb_collectible_collected,
			d->map->nb_collectible);
	if (s1 && s2)
	{
		msg = ft_strjoin("Moves: ", s1);
		if(msg)
		{
			mlx_string_put(d->mlx, d->win, 0, 10, 0xFFFFFF, msg);
			free(msg);
		}
		mlx_string_put(d->mlx, d->win, 0, 25, 0xFFFFFF, s2);
	}
	free(s1);
	free(s2);
}
