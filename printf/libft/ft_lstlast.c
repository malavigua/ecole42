/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:05:27 by malmany           #+#    #+#             */
/*   Updated: 2025/11/18 16:49:40 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*#include<stdio.h>
int main()
{
	t_list *las;
	int d = 13;
        las = ft_lstnew(&d);

        t_list *new;

        int a = 10;
        new = ft_lstnew(&a);

        t_list *list;
        int b = 4;
        list = ft_lstnew(&b);

        t_list *list_2_item;
        int c = 5;
        list_2_item = ft_lstnew(&c);

        list->next = list_2_item;

        ft_lstadd_front(&list, new);


        //int size = ft_lstsize(list);
        
	t_list * last = ft_lstlast(list);
	last->next = las;
	printf("%d\n", *(int*)last->content);
	printf("%d\n", *(int*)list->content);   
        printf("%d\n", *(int*)list->next->content);
        printf("%d\n", *(int*)list->next->next->content);
	printf("%d\n", *(int*)list->next->next->next->content);
}
*/
