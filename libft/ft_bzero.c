/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:12:49 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/18 20:34:03 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		*((unsigned char *)s + idx) = 0;
		idx++;
	}
}
/*
int	main(void)
{
	char	buff[10] = {1,1,1,1,1,1,1,1,1,1};
	char	buff2[10] = {1,1,1,1,1,1,1,1,1,1};

	ft_bzero(buff, sizeof(buff) - 1);
	bzero(buff2, sizeof(buff) - 1);
}
*/
