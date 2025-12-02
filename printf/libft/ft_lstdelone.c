/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:58:12 by malmany           #+#    #+#             */
/*   Updated: 2025/11/17 18:37:04 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdio.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

/*void	del(void *lst_content)
{
	lst_content = NULL;
	if(lst_content)
		printf("%c\n", *(char*)lst_content);
}

int main()
{
        t_list *new;

        char a = 'p';
        new = ft_lstnew(&a);

        t_list *list;
        char b = 'f';
        list = ft_lstnew(&b);

        t_list *list_2_item;
        char c = 'c';
        list_2_item = ft_lstnew(&c);

        list->next = list_2_item;

        ft_lstadd_front(&list, new);
        printf("%c\n", *(char*)list->content);
        printf("%c\n", *(char*)list->next->content);
        printf("%c\n", *(char*)list->next->next->content);

	ft_lstdelone(list_2_item, del);

}
*/
