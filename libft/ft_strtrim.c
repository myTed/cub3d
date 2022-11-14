/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:31:37 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/29 00:39:05 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
/*
#include <stdio.h>
*/
static int	is_duplicated(const char ch, char const *set)
{
	size_t	idx;

	idx = 0;
	while (set[idx] != 0)
	{
		if (ch == set[idx])
			return (1);
		idx++;
	}
	return (0);
}

static int	find_start_idx(char const *str, char const *set, int str_len)
{
	int	idx;

	idx = 0;
	while (idx < str_len)
	{
		if (is_duplicated(str[idx], set))
			idx++;
		else
			break ;
	}
	return (idx);
}

static int	find_end_idx(char const *str, char const *set, int str_len)
{
	int	idx;

	idx = 0;
	while (idx < str_len)
	{
		if (is_duplicated(str[str_len - 1 - idx], set))
		{
			idx++;
		}
		else
			break ;
	}
	return (str_len - 1 - idx);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_idx;
	int		end_idx;
	int		idx;
	char	*str;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	start_idx = find_start_idx(s1, set, (int)ft_strlen(s1));
	end_idx = find_end_idx(s1, set, (int)ft_strlen(s1));
	if (start_idx > (int)ft_strlen(s1) || end_idx < 0)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (end_idx - start_idx + 2));
	if (str == NULL)
		return (0);
	idx = 0;
	while (idx < end_idx - start_idx + 1)
	{
		str[idx] = s1[start_idx + idx];
		idx++;
	}
	str[idx] = 0;
	return (str);
}
/*
int	main(void)
{
	char s1[] = "           ";
	printf("%s\n", ft_strtrim(s1, " "));
	return (0);
}
*/
/*
int	main(int argc, char *argv[])
{
	char	*tmp;
	if (argc != 3)
		return (0);
	tmp = NULL;
	if ((tmp = ft_strtrim(argv[1],argv[2])) != NULL)
	{
		printf("%s\n",tmp);
	}
	return (0);
}
*/
/*
int	main(void)
{
	char	*tmp;
	if ((tmp = ft_strtrim("asdf",0)) != NULL)
	{
		printf("%s\n", tmp);
	}
	return (0);
}
*/
