/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:18:13 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/26 16:14:33 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
*/
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				idx;
	const unsigned char	*src1;
	const unsigned char	*src2;

	idx = 0;
	src1 = s1;
	src2 = s2;
	while (idx < n)
	{
		if (src1[idx] != src2[idx])
			return (src1[idx] - src2[idx]);
		else
			idx++;
	}
	return (0);
}

/*
int	main(void)
{
	if (argc != 4)
		return 0;
	//printf("1\n");
	//ft_memcmp(0,0,1);
	//printf("2\n");
	//ft_memcmp(0,0,0);
	//printf("%d\n",ft_memcmp(argv[1], argv[2], atoi(argv[3])));
	//printf("%d\n",memcmp(argv[1], argv[2], atoi(argv[3])));
	char	*s1 ="\xff\xaa\xde\xffMACOSX\xff";
	char	*s2 ="\xff\xaa\xde\x02";
	size_t	size = 8;

	printf("%d\n", memcmp(s1, s2, size));
	printf("%d\n", ft_memcmp(s1, s2, size));
	
}
*/
