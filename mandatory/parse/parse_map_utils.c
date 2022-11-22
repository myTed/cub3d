/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:25:34 by yehan             #+#    #+#             */
/*   Updated: 2022/11/22 19:03:54 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "ft_gnl.h"
#include <stdio.h>
#include <stdlib.h>

int	is_empty_line(
		char *line
	)
{
	char	*data;

	if (line == 0)
		return (TRUE);
	data = ft_strtrim(line, " \n");
	if (ft_strlen(data) == 0)
		return (TRUE);
	else
		return (FALSE);
}

int	find_first_line(
			int file_fd,
			int *read_count
		)
{
	char	*line;

	line = get_next_line(file_fd);
	while (is_empty_line(line) == TRUE)
	{
		if (line == 0)
		{
			printf("Error\n: no map!!");
			free(line);
			return (FAIL);
		}
		free(line);
		line = get_next_line(file_fd);
		(*read_count)++;
	}
	free(line);
	return (SUCCESS);
}
