#include "../../include/cub3d.h"
#include "../../include/parse.h"
#include "../../libft/libft.h"
#include <stdio.h>

int	is_space_or_newline(char **split_arry, int line_cnt, int *p_found);
static int	check_line_cnt_by_delimiter(char **split_arry, int *p_empty_line)
{
	int	line_cnt;

	if ((split_arry == 0) || (p_empty_line == 0))
		return (FAIL);
	line_cnt = 0;
	while (split_arry[line_cnt])
		line_cnt++;
	if (line_cnt > 2)
	{
		printf("Error\n: too many information in a line\n");
		return (FAIL);
	}
	if (line_cnt == 1)
	{
		if (is_space_or_newline(split_arry, line_cnt, p_empty_line) == FAIL)
			return (FAIL);
		if (*p_empty_line)
			return (SUCCESS);
		printf("Error\n: wrong information in a line\n");
		return (FAIL);
	}
	return (SUCCESS);
}

int	check_color(char *color_str, int found_idx, t_parse_info *p_parse);
int	check_texture_path(char *path_name, int found_idx, t_parse_info *p_parse);
static int	check_valid_type_other(
			char *type_other_str,
			int found_type_idx,
			t_type_ident *p_type,
			t_parse_info *p_parse
){
	if ((type_other_str == 0) || (p_type == 0) || (p_parse == 0))
		return (FAIL);
	type_other_str[ft_strlen(type_other_str) - 1] = 0;
	if (found_type_idx < TEXTURE_MAX)
	{
		if (check_texture_path(type_other_str, found_type_idx, p_parse) == FAIL)
			return (FAIL);
	}
	else
	{
		if (check_color(type_other_str, found_type_idx, p_parse) == FAIL)
			return (FAIL);
	}
	p_type->found[found_type_idx] = 1;
	return (SUCCESS);
}

static int	check_valid_type(char *file_type_str, t_type_ident *p_type, int *p_found_idx)
{
	int	idx;
	int	type_len;

	if ((file_type_str == 0) || (p_type == 0) || (p_found_idx == 0))
		return (FAIL);
	idx = 0;
	while (idx < TYPE_MAX)
	{
		type_len = ft_strlen(p_type->str[idx]);
		if (!ft_strncmp(file_type_str, p_type->str[idx], type_len))
		{
			if (file_type_str[type_len] == 0)
			{
				*p_found_idx = idx;
				return (SUCCESS);
			}
		}
		idx++;
	}
	printf("Error\n:unknown type found!!\n");
	return (FAIL);
}

int	free_split(char **split);
int	parse_identifier_line(char *line, t_parse_info *p_parse, t_type_ident *p_type)
{
	char 	**split_arry;
	int		type_idx;
	int		ret;
	int		valid_line;
	int		empty_line;

	if ((line == 0) || (p_parse == 0) || (p_type == 0))
		return (FAIL);
	valid_line = 0;
	ret = SUCCESS;
	type_idx = 0;
	empty_line = 0;
	split_arry = ft_split(line, ' ');
	if (check_line_cnt_by_delimiter(split_arry, &empty_line) == FAIL)
		ret = FAIL;
	if ((ret == SUCCESS) && (empty_line == 0) &&\
		(check_valid_type(split_arry[0], p_type, &type_idx) == FAIL))
		ret = FAIL;
	if ((ret == SUCCESS) && (empty_line == 0) &&\
		(check_valid_type_other(split_arry[1], type_idx, p_type, p_parse)\
		 == FAIL))
		ret = FAIL;
	free_split(split_arry);
	return (ret);
}