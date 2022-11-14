/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:07:43 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/24 16:13:39 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stdio.h>
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		end = *lst;
		while (end->next != NULL)
			end = end->next;
		end->next = new;
	}
}

/*
int	main(void)
{
	t_list	*start;
	start = ft_lstnew("aaa");
	ft_lstadd_front(&start, ft_lstnew("bbb"));

	ft_lstadd_back(&start, ft_lstnew("ccc"));

	while (start != NULL)
	{
		printf("%s\n", start->content);
		start = start->next;
	}
	return (0);
}
*/
