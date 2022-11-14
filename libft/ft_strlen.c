/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:23:48 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/28 23:26:59 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
*/
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != 0)
		idx++;
	return (idx);
}
/*
int	main(void)
{
	char buf[4] = {10,10,10,10};

	printf("%ld\n",strlen(buf));
	return (0);
}
*/
/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);

	printf("%ld\n", ft_strlen(argv[1]));
	printf("%ld\n", strlen(argv[1]));
}
*/
