/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:07:02 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/26 21:45:12 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stdio.h>

void *change_to_string(void *str)
{
	return	("abcde");
}

void del_content(void *content)
{
	if (content == 0)
		return ;
	printf("free %s\n",(char *)content);
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*tmp;

	if (lst == 0 || f == 0)
		return (0);
	start = ft_lstnew(f(lst->content));
	if (start != 0)
	{
		while (lst->next != 0)
		{
			lst = lst->next;
			tmp = ft_lstnew(f(lst->content));
			if (tmp == 0)
				ft_lstclear(&start, del);
			ft_lstadd_back(&start, tmp);
		}
	}
	return (start);
}

/*
int	main(void)
{
	t_list	*start;
	t_list	*new;
	t_list	*tmp;

	start = ft_lstnew("aaa");
	ft_lstadd_back(&start, ft_lstnew("bbb"));
	ft_lstadd_back(&start, ft_lstnew("ccc"));
	ft_lstadd_back(&start, ft_lstnew("ddd"));
	ft_lstadd_back(&start, ft_lstnew("eee"));

	tmp = start;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	new = ft_lstmap(start, change_to_string, del_content);
	while (new != 0)
	{
		printf("%s\n", (char *)new->content);
		new = new->next;
	}

	return (0);
}
*/
