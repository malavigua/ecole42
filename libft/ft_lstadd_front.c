/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:05:54 by malmany           #+#    #+#             */
/*   Updated: 2025/11/18 16:42:40 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = (*lst);
		(*lst) = new;
	}
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
	printf("%d\n", *(int*)list->content);	
	printf("%d\n", *(int*)list->next->content);
	printf("%d\n", *(int*)list->next->next->content);

	t_list *new2;
        int d = 14;
        new2 = ft_lstnew(&d);
	ft_lstadd_front(&list, new2);
        printf("%d\n", *(int*)list->content);
        printf("%d\n", *(int*)list->next->content);
        printf("%d\n", *(int*)list->next->next->content);
	printf("%d\n", *(int*)list->next->next->next->content);


}
*/
