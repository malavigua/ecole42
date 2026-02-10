char    *ft_itoa(int n)
{
    char        *str;
    long        nb;
    int         len;

    nb = n;
    len = ft_intlen(n);
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
char    *build_col_string(t_mlx_data *d)
{
    char    *cur;
    char    *tot;
    char    *tmp;
    char    *msg;

    cur = ft_itoa(d->collected);
    if (!cur)
        return (NULL);
    tot = ft_itoa(d->map->nb_collectible);
    if (!tot)
        return (free(cur), NULL);
    tmp = ft_strjoin("Collectibles: ", cur);
    if (!tmp)
        return (free(cur), free(tot), NULL);
    msg = ft_strjoin(tmp, "/");
    if (!msg)
        return (free(cur), free(tot), free(tmp), NULL);
    free(tmp);
    tmp = ft_strjoin(msg, tot);
    if (!tmp)
        return (free(cur), free(tot), free(msg), NULL);
    free(cur);
    free(tot);
    free(msg);
    return (tmp);
}
