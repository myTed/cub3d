/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:49:47 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/18 19:30:00 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/
static int	ft_strlen(char *src)
{
	int	idx;

	idx = 0;
	while (src[idx] != 0)
		idx++;
	return (idx);
}

char	*ft_strcat(char *dest, char *src)
{
	int	idx;
	int	len;

	idx = 0;
	len = ft_strlen(dest);
	while (src[idx] != 0)
	{
		dest[len + idx] = src[idx];
		idx++;
	}
	dest[len + idx] = 0;
	return (dest);
}
/*
int	main(void)
{
	char str1[128] = "AAAAAAAAAAAA1";
	char str2[128] = "AAAAAAAAAAAA1";
	char *str3 = "asjdkfljaksl";

	printf("   strcat:%s\n", strcat(str1, str3));
	printf("ft_strcat:%s\n", ft_strcat(str2, str3));
	return (0);
}
*/
