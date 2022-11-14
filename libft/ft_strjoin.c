/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:54:05 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/28 23:31:27 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
/*
#include <stdio.h>
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if ((s1 == 0) || (s2 == 0))
	{
		if (s1 == 0 && s2 == 0)
			return (NULL);
		else if (s1)
			return ((char *)s1);
		else
			return ((char *)s2);
	}
	str = NULL;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str != NULL)
	{
		ft_strlcpy(str, s1, ft_strlen(s1) + ft_strlen(s2) + 1);
		ft_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s1) + ft_strlen(s2) + 1);
		str[ft_strlen(s1) + ft_strlen(s2)] = 0;
	}
	return (str);
}
/*
int	main(void)
{
	char	*s1 = "my favorite animal is";
	char	*s2 = " ";
	char	*s3 = "the nyancat";

	char	*tmp = ft_strjoin(s1, s2);
	char	*res = ft_strjoin(tmp, s3);

	printf("%s\n", tmp);
	printf("%s\n",res);
}
*/
/*
int	main(void)
{
	printf("%s\n", ft_strjoin(0,0));
	printf("%s\n", ft_strjoin("asdjkfl",0));
	printf("%s\n", ft_strjoin(0,"sjsjjs"));
	printf("%s\n", ft_strjoin("aaa","bbb"));
}
*/
/*
int	main(int argc, char *argv[])
{
	char	*tmp;
	if (argc != 3)
		return (0);
	tmp = ft_strjoin(argv[1],argv[2]);
	if (tmp != NULL)
		printf("%s\n",tmp);
}
*/
