/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:48:43 by malmany           #+#    #+#             */
/*   Updated: 2025/11/18 16:53:20 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdio.h>

static void	f_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{	
	t_list	*temp;

	while ((*lst))
	{	
		temp = (*lst)->next;
		f_lstdelone(*lst, del);
		(*lst) = temp;
	}
}

/*void  del(void *lst_content)
{
        lst_content = NULL;
        if(lst_content)
                printf("%c\n", *(char*)lst_content);
}

int main()
{
        t_list *list;
        char b = 'f';
        list = ft_lstnew(&b);

        t_list *list_2_item;
        char c = 'c';
        list_2_item = ft_lstnew(&c);

        list->next = list_2_item;

	t_list *list_3_item;
        char d = 'p';
        list_3_item = ft_lstnew(&d);

        list_2_item->next = list_3_item;


        printf("%c\n", *(char*)list->content);
        printf("%c\n", *(char*)list->next->content);
	printf("%c\n", *(char*)list->next->next->content);

        ft_lstclear(&list_2_item, del);

}

*/
