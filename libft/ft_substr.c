/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:12:05 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/29 20:14:10 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
/*
#include <stdio.h>
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;
	size_t	idx;

	if (len == 0 || s == 0)
		return (ft_strdup(""));
	str_len = ft_strlen(s);
	if (str_len <= start)
		return (ft_strdup(""));
	if (str_len < len)
		len = str_len;
	str = NULL;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		idx = 0;
		while ((s[idx] != 0) && (idx < len))
		{
			str[idx] = s[start + idx];
			idx++;
		}
		str[idx] = 0;
	}
	return (str);
}
/*
int	main(void)
{
	//char	*str = "i just wnat this part ##########";
	//size_t	size = 10;

	//printf("%s\n",NULL);
	printf("%s\n",ft_substr("aaa",0,42000));
	//printf("%s\n",ft_substr(NULL, 0, size));
}
*/
/*
int	main(int argc, char *argv[])
{
	char	*tmp;

	if (argc != 4)
		return (0);
	tmp = ft_substr(argv[1],atoi(argv[2]),atoi(argv[3]));
	if (tmp != NULL)
		printf("%s\n",tmp);
}
*/
