/*
int init_game_info(t_game_info *p_game, char *filename)
{
	if (init_parse_info(&(p_game->parse), filename) == FAIL)
		return (FAIL);
	if (check_map_error(p_game->parse.map) == FAIL)
		return (FAIL);
	if (init_player_info(&(p_game->player)) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
*/

#include "../include/cub3d.h"
#include "../libft/libft.h"
#include "../gnl/ft_gnl.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define SUCCESS 0
#define FAIL 1

int	free_split(char **split)
{
	int idx;

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

int	init_type_ident(t_type_ident *p_type)
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

int	is_end_with_extension(char *file_name, char *extension, int *p_valid)
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


int	check_texture_path(char *path_name, int found_idx, t_parse_info *p_parse)
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


int	check_color_value(
		char **splited_str,
		int found_idx,
		t_parse_info *p_parse
){
	int	idx;
	int	color_value;
	int	color_idx;

	if ((splited_str == 0) || (p_parse == 0))
		return (FAIL);
	idx = 0;
	while (idx < COLOR_NUM_MAX)
	{
		color_value = ft_atoi(splited_str[idx]);
		if ((color_value > COLOR_VALUE_MAX) || (color_value < COLOR_VALUE_MIN))
		{
			printf("Error\n: color value more than 255 or less than 0!\n");
			return (FAIL);
		}
		color_idx = 2 - idx;
		if (found_idx == FLOOR_IDX)
			((unsigned char *)(&(p_parse->floor)))[color_idx] = color_value;
		else if (found_idx == CEILING_IDX)
			((unsigned char *)(&(p_parse->ceiling)))[color_idx] = color_value;
		idx++;
	}
	return (SUCCESS);
}

int	check_color_cnt(char **splited_str)
{
	int	idx;

	if (splited_str == 0)
		return (FAIL);
	
	idx = 0;
	while (splited_str[idx])
		idx++;
	if (idx != COLOR_NUM_MAX)
	{
		printf("Error\n: color should be only 3 colors\n");
		return (FAIL);
	}
	return (SUCCESS);
}


int	check_color_comma(char *color_str)
{
	int	comma_cnt;
	int	idx;

	if (color_str == 0)
		return (FAIL);
	comma_cnt = 0;
	idx = 0;
	while (color_str[idx])
	{
		if (color_str[idx] == ',')
				comma_cnt++;
		idx++;
	}
	if (comma_cnt != 2)
	{
		printf("Error\n: comma cnt should be 2!");
		return (FAIL);
	}
	return (SUCCESS);
}

int	check_color(char *color_str, int found_idx, t_parse_info *p_parse)
{
	char 	**splited_str;

	if ((color_str == 0) || (p_parse == 0))
		return (FAIL);
	splited_str = ft_split(color_str, ',');
	if (splited_str == 0)
	{
		perror("Error\n");
		return (FAIL);
	}
	if ((check_color_comma(color_str) == FAIL) ||
			(check_color_cnt(splited_str) == FAIL) ||
			(check_color_value(splited_str, found_idx, p_parse) == FAIL))
	{
		free_split(splited_str);
		return (FAIL);
	}
	free_split(splited_str);
	return (SUCCESS);
}

int	is_space_or_newline(char **split_arry, int line_cnt, int *p_found)
{

	if ((split_arry == 0) || (p_found == 0))
		return (FAIL);
	if (line_cnt == 0)
		*p_found = 1;
	else if ((line_cnt == 1) && (split_arry[0][0] == '\n')\
				&& (split_arry[0][1] == 0))
		*p_found = 1;
	return (SUCCESS);
}


int	check_line_cnt_by_delimiter(char **split_arry, int *p_empty_line)
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

int	check_valid_type_other(
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

int	check_valid_type(char *file_type_str, t_type_ident *p_type, int *p_found_idx)
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

int	is_all_found_identifier(t_type_ident *p_type, int *p_all_found)
{
	int	idx;
	int	found_cnt;

	if ((p_type == 0) || (p_all_found == 0))
		return (FAIL);
	idx = 0;
	found_cnt = 0;
	while (idx < TYPE_MAX)
	{
		found_cnt += p_type->found[idx];
		idx++;
	}
	if (found_cnt == TYPE_MAX)
		*p_all_found = 1;
	return (SUCCESS);
}

int	parse_identifier(int fd, t_parse_info *p_parse, int *p_read_cnt)
{
	char 			*line;
	t_type_ident	type;
	int				all_found_identifier;

	if ((p_parse == 0) || (p_read_cnt == 0))
		return (FAIL);
	if (init_type_ident(&type) == FAIL)
		return (FAIL);
	all_found_identifier = 0;
	while (!all_found_identifier)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		if (parse_identifier_line(line, p_parse, &type) == FAIL)
		{
			free(line);
			return (FAIL);
		}
		free(line);
		(*p_read_cnt)++;
		if (is_all_found_identifier(&type, &all_found_identifier) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}


int	is_valid_file_name(char *file_name, int *p_valid)
{
	if (file_name == 0)
	{
		printf("Error\n: No file_name!\n");
		return (FAIL);
	}
	if (is_end_with_extension(file_name, ".cub", p_valid) == FAIL)
		return (FAIL);
	if (*p_valid == 0)
		printf("Error\n: Not valid Map extension name! .cub\n");
	return (SUCCESS);
}

int	get_map(int file_fd, char *file_name, t_game_info *p_game, int read_count);

int	parsing_file(t_game_info *p_game, char *file_name)
{
	int			read_count;
	int			file_fd;
	int			valid_name;

	if (p_game == 0)
		return (FAIL);
	valid_name = 0;
	if (is_valid_file_name(file_name, &valid_name) == FAIL)
		return (FAIL);
	if (valid_name == 0)
		return (FAIL);
	file_fd = open(file_name, O_RDONLY);
	if (file_fd == -1)
	{
		perror("Error\n");
		return (FAIL);
	}
	read_count = 0;
	if (parse_identifier(file_fd, &(p_game->parse), &read_count) == FAIL)
		return (FAIL);
	if (get_map(file_fd, file_name, p_game, read_count) == FAIL)
		return (FAIL);


	return (SUCCESS);
}

// 그냥 예시용
//void	display_result(t_parse_info *p_parse, int read_count)
//{
//	printf("north texture_path : %s\n", p_parse->path.texture.north);
//	printf("south texture_path : %s\n", p_parse->path.texture.south);
//	printf("west texture_path : %s\n", p_parse->path.texture.west);
//	printf("east texture_path : %s\n", p_parse->path.texture.east);
//	printf("floor color : r %d g %d b %d\n", p_parse->floor.red, p_parse->floor.green,
//					p_parse->floor.blue);
//	printf("ceiling color : r %d, g %d, b %d\n", p_parse->ceiling.red, p_parse->ceiling.green, p_parse->ceiling.blue);
//	printf("total read_count: %d\n", read_count);
//}
