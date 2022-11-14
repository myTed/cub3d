/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:33:10 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/22 18:22:50 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
#include <stdlib.h>
*/
void	put_number(int n, int fd, int *pminus)
{
	char			ch;
	long long int	long_number;

	if (n < 0)
	{
		long_number = (long long int)n * -1;
		*pminus = 1;
	}
	else
		long_number = n;
	if (long_number / 10 != 0)
		put_number(long_number / 10, fd, pminus);
	else
	{
		if (*pminus)
			write(fd, "-", 1);
	}
	ch = (long_number % 10) + '0';
	write(fd, &ch, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	minus;

	if (fd < 0)
		return ;
	minus = 0;
	put_number(n, fd, &minus);
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);

	ft_putnbr_fd(atoi(argv[1]), 1);
}
*/
