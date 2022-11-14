/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:47:48 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/24 10:09:00 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
/*
#include <stdio.h>

void	del_content(void *content)
{
	if (content == 0)
		return ;
	printf("free %s\n",(char *)content);
}
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == 0 || del == 0)
		return ;
	del(lst->content);
	free(lst);
}
/*
int	main(void)
{
	t_list	*start;

	start = ft_lstnew("aaa");
	ft_lstadd_front(&start, ft_lstnew("bbb"));
	ft_lstadd_back(&start, ft_lstnew("ccc"));
	ft_lstadd_back(&start, ft_lstnew("ddd"));
	ft_lstdelone(start->next->next->next, del_content);

	while (start != 0)
	{
		printf("%s\n",(char *)start->content);
		start = start->next;
	}
}
*/
