/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:55:40 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/24 11:05:28 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

void	ft_print_content(void *content)
{
	printf("%s\n",(char *)content);
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == 0 || f == 0)
		return ;
	while (lst != 0)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
int	main(void)
{
	t_list	*start;
	start = ft_lstnew("aaa");
	ft_lstadd_back(&start, ft_lstnew("bbb"));
	ft_lstadd_back(&start, ft_lstnew("ccc"));
	ft_lstadd_back(&start, ft_lstnew("ddd"));
	ft_lstadd_back(&start, ft_lstnew("eee"));
	ft_lstiter(start, ft_print_content);
	return (0);
}
*/
