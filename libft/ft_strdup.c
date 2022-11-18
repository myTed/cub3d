/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:36:02 by kyolee            #+#    #+#             */
/*   Updated: 2022/11/18 16:12:07 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
/*
#include <string.h>
#include <stdio.h>
*/
static size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != 0)
		idx++;
	return (idx);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	idx;

	str = NULL;
	str = malloc(ft_strlen(s) + 1);
	idx = 0;
	if (str != NULL)
	{
		while (s[idx] != 0)
		{
			str[idx] = s[idx];
			idx++;
		}
		str[idx] = 0;
	}
	return (str);
}

//int	main(void)
//{
//	ft_strdup("");
//	return (0);
//}

/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("%s\n",ft_strdup(argv[1]));
	printf("%s\n",strdup(argv[1]));
	return (0);
}
*/
