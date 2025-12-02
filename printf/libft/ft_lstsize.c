/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:54:58 by malmany           #+#    #+#             */
/*   Updated: 2025/11/18 16:45:55 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*#include<stdio.h>
int main()
{
        t_list *new;

        int a = 10;
        new = ft_lstnew(&a);

        t_list *list;
        int b = 2;
        list = ft_lstnew(&b);

        t_list *list_2_item;
        int c = 3;
        list_2_item = ft_lstnew(&c);

        list->next = list_2_item;

        ft_lstadd_front(&list, new);
        //ft_lstadd_front(&list, new);


	int size = ft_lstsize(list);
	printf("%d\n", size);

	printf("%d\n", *(int*)list->content);   
        printf("%d\n", *(int*)list->next->content);
        printf("%d\n", *(int*)list->next->next->content);


}*/
