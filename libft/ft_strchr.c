/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:34:33 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/18 20:00:57 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/
#include <stddef.h>
/*
int	main(int argc, char *argv[])
{
	char	*buff;
	char	*buff2;

	if (argc != 3)
		return (0);
	buff = ft_strchr(argv[1], argv[2][0]);
	buff2 = strchr(argv[1], argv[2][0]);
	
	printf("%p\n",buff);
	printf("%p\n",buff2);
	return (0);
}
*/

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != 0)
	{
		if (s[idx] == (char)c)
			return ((char *)&s[idx]);
		idx++;
	}
	if (c == 0)
		return ((char *)&s[idx]);
	return (0);
}
/*
int	main(void)
{
	
	printf("strchr   : %s\n",strchr(0, 'a'));
	//printf("ft_strchr: %s\n",ft_strchr(0,'a'));
	return (0);
}
*/
