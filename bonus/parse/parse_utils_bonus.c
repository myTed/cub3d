/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:25:34 by yehan             #+#    #+#             */
/*   Updated: 2022/11/24 19:32:33 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
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
	{
		free(data);
		return (TRUE);
	}
	else
	{
		free(data);
		return (FALSE);
	}
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

void	free_map_info(
			t_map_info *p_map
		)
{
	int	i;

	i = 0;
	if (p_map != 0)
	{
		while (i < p_map->height)
		{
			free(p_map->data[i]);
			i++;
		}
		free(p_map->data);
	}
}

int	free_path_info_texture(
		t_path_info *p_path
	)
{
	char	**path_arry;
	int		idx;

	if (p_path == 0)
		return (FAIL);
	path_arry = p_path->arry;
	idx = 0;
	while (idx < TEXTURE_MAX)
	{
		if (path_arry[idx] != 0)
			free(path_arry[idx]);
		idx++;
	}
	return (SUCCESS);
}
