/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:15:56 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/23 13:06:59 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*start;

	start = ft_lstnew("aaa");
	ft_lstadd_front(&start, ft_lstnew("bbb"));
	ft_lstadd_front(&start, ft_lstnew("ccc"));
	ft_lstadd_front(&start, ft_lstnew("ccc"));
	printf("%s\n",ft_lstlast(start)->content);
	return (0);
}
*/
