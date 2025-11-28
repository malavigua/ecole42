/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:04:52 by malmany           #+#    #+#             */
/*   Updated: 2025/11/18 16:55:12 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst)
	{	
		while (lst)
		{
			temp = lst->next;
			f(lst->content);
			lst = temp;
		}
	}
}

/*void	f(void * list_content)
{
	if(*(char*)list_content >= 'a' && *(char*)list_content <= 'z')
		*(char*)list_content -= 32;
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

        ft_lstiter(list, f);

	printf("%c\n", *(char*)list->content);
        printf("%c\n", *(char*)list->next->content);
        printf("%c\n", *(char*)list->next->next->content);

}
*/
