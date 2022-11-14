/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:48:06 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/18 19:53:52 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t		idx;
	const char	*tmp;

	idx = 0;
	tmp = 0;
	while (s[idx] != 0)
	{
		if (s[idx] == (char)c)
			tmp = &s[idx];
		idx++;
	}
	if (c == 0)
		return ((char *)&s[idx]);
	return ((char *)tmp);
}
/*
int	main(int argc, char *argv[])
{
	char	*tmp;
	char	*tmp2;

	if (argc != 3)
		return (0);
	tmp = 0;
	tmp = ft_strrchr(argv[1],0);
	tmp2 = strrchr(argv[1],0);

	printf("%p\n",tmp);
	printf("%p\n",tmp2);
	return (0);
}
*/
