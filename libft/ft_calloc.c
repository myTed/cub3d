/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:09:06 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/29 14:40:11 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
/*
#include <stdio.h>
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;
	size_t	idx;

	tmp = 0;
	tmp = malloc(count * size);
	idx = 0;
	if (tmp != 0)
	{
		while (idx < count * size)
		{
			*((unsigned char *)tmp + idx) = 0;
			idx++;
		}
	}
	return (tmp);
}
/*
int	main(void)
{
	char	*tmp;

	tmp = 0;
	printf("%p\n",ft_calloc(0, sizeof(int)));
	tmp = calloc(0, sizeof(int));
	printf("%d\n", errno);
	tmp = calloc(1, sizeof(int));
	printf("%d\n", errno);
	printf("%d\n",tmp[0]);
	
	free(tmp);
}
*/
