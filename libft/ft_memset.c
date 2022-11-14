/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:29:31 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/18 19:53:07 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <string.h>
#include <stdio.h>
*/
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		*((unsigned char *)(s) + idx) = (unsigned char)c;
		idx++;
	}
	return (s);
}
/*
int	main(void)
{
	int		buff[10];
	int		buff2[10];

	ft_memset(buff, 123, sizeof(buff));
	memset(buff2, 123, sizeof(buff2));

	return (0);
}
*/
