/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 02:21:57 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/28 23:59:20 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>
*/
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	idx;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	idx = 0;
	while ((src[idx] != 0) && (idx + dst_len + 1 < size))
	{
		dest[dst_len + idx] = src[idx];
		idx++;
	}
	if (idx != 0)
		dest[dst_len + idx] = 0;
	if (size < dst_len)
		return (src_len + size);
	else
		return (dst_len + src_len);
}
/*
int	main(void)
{
	char	*dest;
	char 	dest1[15];
	//char dest2[20] = "ajsdkf";
	//char src[20] = "AAAA";
	printf("%ld\n",sizeof(*dest));
	memset(dest1, 'r', 15);
	printf("strlcat    :%ld\n",ft_strlcat(dest1,"lorem ipsum dolor sit amet", 5));
	write(1, dest1, 15);
	//printf("%s\n",dest1);	
	//printf("ft_strlcat :%ld\n",ft_strlcat(dest1,src,-1));
	//printf("%s\n",dest2);
}
*/
