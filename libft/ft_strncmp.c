/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:01:09 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/29 19:01:09 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
/*
#include <stdio.h>
#include <string.h>
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while ((s1[idx] != 0 || s2[idx] != 0) && (idx < n))
	{
		if (s1[idx] != s2[idx])
		{
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		}
		idx++;
	}
	return (0);
}

/*
int	main(void)
{

	printf("%d\n",ft_strncmp("test\200", "test\0", 6));
	printf("%d\n",strncmp("test\200", "test\0", 6));
}
*/
