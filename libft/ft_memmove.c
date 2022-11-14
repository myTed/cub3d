/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:37:40 by kyolee            #+#    #+#             */
/*   Updated: 2021/11/26 03:39:11 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
/*
#include <stddef.h>
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				idx;

	idx = 0;
	if ((char *)dest < (const char *)src)
	{
		while (idx < n)
		{
			*((char *)dest + idx) = *((const char *)src + idx);
			idx++;
		}
	}
	else
	{
		while (idx < n)
		{
			if ((dest == 0) && (src == 0))
				return (0);
			*((char *)dest + (n - 1 - idx)) = *((const char *)src + \
							(n - 1 - idx));
			idx++;
		}
	}
	return (dest);
}

/*
int	main(void)
{
	char	str[] = "memmove can be very useful......";
	char	str2[]= "memmove can be very useful......";
	char	str3[]= "1234567890";
	
	ft_memmove(0, 0, 5);
	memmove(NULL, NULL, 5);
	//ft_memmove(str3+1, str3, 9);
	
	printf("%s\n",str);
	printf("%s\n",str2);
	printf("%s\n",str3);
	
	return (0);
}
*/
