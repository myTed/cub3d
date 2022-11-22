/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:25:14 by yehan             #+#    #+#             */
/*   Updated: 2022/11/22 19:02:39 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	free_split(
		char **split
	)
{
	int	idx;

	if (split == 0)
		return (FAIL);
	idx = 0;
	while (split[idx])
	{
		free(split[idx]);
		idx++;
	}
	free(split);
	return (SUCCESS);
}

int	init_type_ident(
		t_type_ident *p_type
	)
{
	if (p_type == 0)
		return (FAIL);
	p_type->str[0] = "NO";
	p_type->str[1] = "SO";
	p_type->str[2] = "WE";
	p_type->str[3] = "EA";
	p_type->str[4] = "F";
	p_type->str[5] = "C";
	ft_memset(p_type->found, 0, sizeof(int) * TYPE_MAX);
	return (SUCCESS);
}

int	is_end_with_extension(
		char *file_name,
		char *extension,
		int *p_valid
	)
{
	size_t	file_len;
	size_t	ext_len;

	if ((file_name == 0) || (extension == 0) || (p_valid == 0))
		return (FAIL);
	file_len = ft_strlen(file_name);
	ext_len = ft_strlen(extension);
	if (file_len < ext_len)
		return (SUCCESS);
	if (ft_strncmp(file_name + file_len - ext_len, extension, ext_len))
		return (SUCCESS);
	*p_valid = 1;
	return (SUCCESS);
}

int	is_space_or_newline(
		char **split_arry,
		int line_cnt,
		int *p_found
	)
{
	if ((split_arry == 0) || (p_found == 0))
		return (FAIL);
	if (line_cnt == 0)
		*p_found = 1;
	else if ((line_cnt == 1) && (split_arry[0][0] == '\n') \
				&& (split_arry[0][1] == 0))
		*p_found = 1;
	return (SUCCESS);
}

int	check_texture_path(
		char *path_name,
		int found_idx,
		t_parse_info *p_parse
	)
{
	int		fd;
	char	*tmp_path;

	if ((path_name == 0) || (p_parse == 0))
		return (FAIL);
	fd = open(path_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		return (FAIL);
	}
	tmp_path = ft_strdup(path_name);
	if (tmp_path == 0)
	{
		perror("Error\n");
		return (FAIL);
	}
	p_parse->path.arry[found_idx] = tmp_path;
	close(fd);
	return (SUCCESS);
}
