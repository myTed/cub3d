/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:27:02 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/22 16:50:58 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdio.h>
*/
void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, (unsigned char *)&c, 1);
}

/*
int	main(void)
{
	
	ft_putchar_fd(-128, 1);
	ft_putchar_fd(127, 1);
	ft_putchar_fd(255, 1);
	ft_putchar_fd(0, 1);
	ft_putchar_fd('a', 1);
	//ft_putchar_fd(256, 1);
	//ft_putcarh_fd(-129, 1);

	printf("\n");	
	putchar(-128);
	putchar(127);
	putchar(255);
	putchar(0);
	putchar('a');
	//putchar(256);
	//putchar(-129);
}
*/
