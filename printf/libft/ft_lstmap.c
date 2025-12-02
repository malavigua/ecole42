/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:25:09 by malmany           #+#    #+#             */
/*   Updated: 2025/11/21 12:30:01 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdio.h>

static t_list	*f_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

static void	f_lstadd_back(t_list **lst, t_list *new)
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

static void	f_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while ((*lst))
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = temp;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*node;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = f_lstnew(content);
		if (!node)
		{	
			del(content);
			f_lstclear(&res, del);
			return (NULL);
		}
		f_lstadd_back(&res, node);
		lst = lst->next;
	}
	return (res);
}

/*void *f(void * list_content)
{
	char	*c;
	c = malloc(1);
        if(*(char*)list_content >= 'a' && *(char*)list_content <= 'z')
             *c = *(char*)list_content -= 32;
	return(c);
}

void  del(void *lst_content)
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

       t_list *res = ft_lstmap(list, f, del);

        printf("%c\n", *(char*)res->content);
        printf("%c\n", *(char*)res->next->content);
        printf("%c\n", *(char*)res->next->next->content);

}

*/
