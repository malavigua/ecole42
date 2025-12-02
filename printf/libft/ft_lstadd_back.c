/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:33:55 by malmany           #+#    #+#             */
/*   Updated: 2025/11/18 17:29:18 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include<stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = (*lst);
	if (!(*lst))
		(*lst) = new;
	else
	{
		if (new)
		{
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
	}
}

/*int main()
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
	list_2_item -> next = NULL;
	printf(" count before %d\n", ft_lstsize(list));
        ft_lstadd_back(&list, new);
	printf(" count after %d\n", ft_lstsize(list));

        printf("%d\n", *(int*)list->content);
        printf("%d\n", *(int*)list->next->content);
	printf("%d\n", *(int*)list->next->next->content);

}
*/
