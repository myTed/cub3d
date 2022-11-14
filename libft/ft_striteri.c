/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:58:33 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/22 16:25:06 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"
/*
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
*/
/*
void my_toupper(unsigned int a, char *pch)
{
	*pch = toupper(*pch);
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len;
	size_t	idx;

	if ((s == 0) || (f == 0))
		return ;
	len = ft_strlen(s);
	idx = 0;
	while (idx < len)
	{
		f(idx, &s[idx]);
		idx++;
	}
}

/*
int	main(int argc, char *argv[])
{
	char *str;

	if (argc != 2)
		return (0);
	str = NULL;
	str = malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));
	if (str == NULL)
		return (-1);
	
	strncpy(str, argv[1],ft_strlen(argv[1]));
	str[ft_strlen(argv[1])] = 0;

	ft_striteri(str, my_toupper);
	printf("%s\n",str);
	return (0);
}
*/
