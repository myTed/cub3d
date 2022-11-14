/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:03:43 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/18 19:54:10 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				idx;
	const unsigned char	*src;

	idx = 0;
	src = (const unsigned char *)s;
	while (idx < n)
	{
		if (src[idx] == (unsigned char)c)
		{
			return ((void *)&src[idx]);
		}
		idx++;
	}
	return (0);
}

/*
int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);

	printf("%p\n",ft_memchr(argv[1], argv[2][0], strlen(argv[1])));
	printf("%p\n",memchr(argv[1], argv[2][0], strlen(argv[1])));
	
}
*/
