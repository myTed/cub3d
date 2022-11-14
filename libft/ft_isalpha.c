/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:22:02 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/10 14:18:06 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <ctype.h>
*/
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	printf("ft_isaplha : %d\n", ft_isalpha(argv[1][0]));
	printf("isaplha    : %d\n", isalpha(argv[1][0]));

}
*/
