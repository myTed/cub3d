/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:55:51 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/22 15:42:20 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"
#include <stdlib.h>
/*
#include <ctype.h>
#include <stdio.h>
*/
/*
char	my_toupper(unsigned int a, char ch)
{
	return (toupper(ch));
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*str;
	size_t	idx;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		str[idx] = f(idx, s[idx]);
		idx++;
	}
	str[len] = 0;
	return (str);
}

/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("%s\n", ft_strmapi(argv[1],my_toupper));
	return (0);
}
*/
