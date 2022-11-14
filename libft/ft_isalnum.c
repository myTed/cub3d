/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:10:27 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/29 00:01:04 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <ctype.h>
*/
static int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	else
		return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	else
		return (0);
}
/*
int	main(void)
{
	int	i;

	i = 0;
	while (i < 530)
	{
		printf("%d : ft_isalnum %d , isalnum %d,\
				ft_isalpha %d isalpha %d ft_isdigit %d isdigit %d\n", \
			   	i, ft_isalnum(i), isalnum(i), \
				ft_isalpha(i), isalpha(i), ft_isdigit(i), isdigit(i));
		i++;
	}
	return (0);
}
*/
