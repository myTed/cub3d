/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:09:41 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/24 10:54:27 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
/*
#include <stdio.h>
*/
/*
void	del_content(void *content)
{
	if (content == 0)
		return ;
	printf("free %s\n",(char *)content);
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur_pos;
	t_list	*del_pos;

	if (lst == 0 || del == 0)
		return ;
	cur_pos = *lst;
	while (cur_pos != 0)
	{
		del_pos = cur_pos;
		cur_pos = cur_pos->next;
		del(del_pos->content);
		free(del_pos);
	}
	*lst = 0;
}
/*
int	main(void)
{
	t_list	*start;
	t_list	*tmp;

	start = ft_lstnew("aaa");
	ft_lstadd_back(&start, ft_lstnew("bbb"));
	ft_lstadd_back(&start, ft_lstnew("ccc"));
	ft_lstadd_back(&start, ft_lstnew("ddd"));

	tmp = start;
	while (tmp != 0)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	
	ft_lstclear(&start->next->next, del_content);

	tmp = start;
	while (tmp != 0)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
*/
