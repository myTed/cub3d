/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:52:33 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/10 14:17:49 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;

	printf("ft_isdigit: %d\n",ft_isdigit(argv[1][0]));
	printf("isdigit:    %d\n",isdigit(argv[1][0]));
	return (0);
}
*/
