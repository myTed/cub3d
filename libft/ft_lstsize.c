/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:49:36 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/23 12:05:50 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
*/
int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != 0)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/*
int	main(void)
{
	t_list	*start;

	start = ft_lstnew("aaa");
	ft_lstadd_front(&start, ft_lstnew("bbb"));
	ft_lstadd_front(&start, ft_lstnew("ccc"));
	ft_lstadd_front(&start, ft_lstnew("ddd"));
	printf("%d\n", ft_lstsize(start));
	ft_lstadd_front(&start, ft_lstnew("eee"));

	printf("%d\n", ft_lstsize(start));
	while (start != NULL)
	{
		printf("%s\n", start->content);
		start = start->next;
	}
}
*/
