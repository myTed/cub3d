/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:36:31 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/18 20:37:33 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
*/
#include <stddef.h>

size_t	get_len_str(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != 0)
	{
		idx++;
	}
	return (idx);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t			idx;
	size_t			len;

	idx = 0;
	len = get_len_str(src);
	if (size != 0)
	{
		while (src[idx] != 0 && idx < size - 1)
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = 0;
	}
	return (len);
}

/*
int	main(int argc, char *argv[])
{
	char buff[128] = "AAA";
	char buff2[128] = "AAA";
	if (argc != 2)
	{
		printf("argument has to be 1");
		return (0);
	}
	
	ft_strlcpy(buff,argv[1],12);
	strlcpy(buff2, argv[1], 12);
	printf("ft_lcpy:%s\n",buff);
	printf("lcpy   :%s\n",buff2);
}
*/
