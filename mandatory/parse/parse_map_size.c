/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:25:31 by yehan             #+#    #+#             */
/*   Updated: 2022/11/22 17:31:05 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"
#include "../../gnl/ft_gnl.h"
#include <stdio.h>
#include <stdlib.h>

int	is_empty_line(char *line);

static int	is_remains(
				int file_fd,
				char *line
			)
{
	while (is_empty_line(line) == TRUE)
	{
		if (line == 0)
		{
			free(line);
			return (FALSE);
		}
		free(line);
		line = get_next_line(file_fd);
	}
	printf("Error\n: contents after map!!");
	free(line);
	return (TRUE);
}

int	set_map_size(
		int file_fd,
		t_map_info *p_map,
		int read_count
	)
{
	char	*line;
	int		line_len;
	int		map_start_count;

	map_start_count = read_count;
	p_map->width = 0;
	line = get_next_line(file_fd);
	read_count++;
	while (line != 0 && is_empty_line(line) == FALSE)
	{
		line_len = ft_strlen(line);
		if (p_map->width < line_len)
			p_map->width = line_len;
		free(line);
		line = get_next_line(file_fd);
		read_count++;
	}
	p_map->height = read_count - map_start_count;
	if (is_remains(file_fd, line) == TRUE)
		return (FAIL);
	return (SUCCESS);
}
