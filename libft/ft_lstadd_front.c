/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:22:26 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/24 16:10:55 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"
/*
#include <stdio.h>
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == 0 || new == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
int	main(void)
{
	t_list	*start;
	start = ft_lstnew("aaa");
	ft_lstadd_front(&start,ft_lstnew("bbb"));
	ft_lstadd_front(&start,ft_lstnew("ccc"));
	while (start != 0)
	{
		printf("%s\n",start->content);
		start = start->next;
	}

	return (0);
}
*/
