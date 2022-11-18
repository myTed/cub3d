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

#include "cub3d.h"
#include <fcntl.h>

#define SUCCESS 0
#define FAIL 1

#define TYPE_MAX		6
#define	TEXTURE_MAX		4
#define	COLOR_NUM_MAX	3

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
	p_type->idx = 0;
	return (SUCCESS);
}

int	is_end_with(char *file_name, char *extension)
{
	size_t	file_len;
	size_t	ext_len;

	file_len = ft_strlen(file_name);	
	ext_len = ft_strlen(file_name);
	if (file_len < ext_len)
		return (FAIL);
	if (strncmp(file_name + file_len - ext_len, extension, ext_len))
		return (FAIL);
	return (SUCCESS);
}

int	check_type_str(char *file_type_str, t_type_ident *p_type, int *p_found_idx)
{
	int	idx;

	idx = 0;
	while (idx < TYPE_MAX)
	{
		if (!ft_strncmp(file_type_str, p_type->type_str[idx]))
		{
			*p_found_idx = idx;
			return (SUCESS);
		}
		idx++;
	}
	printf("Error\nunknown type found!!\n");
	return (FALSE);
}


int	check_texture(char *path_name, int found_idx, t_parse_info *p_parse)
{
	int		fd;
	size_t	len;
	char	*tmp_path;

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
	p_parse->arry[found_idx] = path_name; 
	close(fd);
	return (SUCCESS);
}


int	check_color_value(char **splited_str)
{
	if (splited_str == 0)
		return (FAIL);
	idx = 0;
	while (idx < COLOR_NUM_MAX)
	{
		color_value = ft_atoi(splited_str[idx]);
		if (color_value > 255)
		{
			free_split(splited_str);
			return (FAIL);
		}
		idx++;
	}
	return (SUCESS);
}


int	check_color(char *color_str, int found_idx, t_parse_info *p_parse)
{
	char 	**splited_str;
	int		color_num;
	int		idx;
	int		color_value;

	splited_str = ft_split(color_str, ',');
	if (splited_str == 0)
	{
		perror("Error\n");
		return (FAIL);
	}
	idx = 0;
	//color 갯수 체크
	while (splited_str[idx++]);
	if (idx > COLOR_NUM_MAX)
	{
		free_split(splited_str);
		return (FAIL);
	}
	//color 값 체크
	if (check_color_value(splited_str) == FAIL)
	{
		free_split(splited_str);
		return (FAIL);
	}
	return (SUCCESS);
}


int	parse_identifier_line(char *line, t_parse_info *p_parse, t_type_ident *p_type)
{
	char 	**split_arry;
	size_t	line_cnt;
	int		found_type_idx;

	split_arry = ft_split(line, ' ');
	line_cnt = 0;
	while (split_arry[line_cnt++]);
	if (line_cnt != 2)
		return (FAIL);
	if (check_type_str(split_arry[0], p_type, &found_type_idx) == FAIL)
		return (FAIL);
	if (found_type_idx < TEXTURE_MAX)
	{
		if (check_texture(split_arry[1], found_type_idx, p_parse) == FAIL)
	}		return (FAIL);
	else
	{
		if (check_color(split_arry[1], found_type_idx, p_parse) == FAIL)
			return (FAIL);
	}
	return (SUCESS);
}

int	is_all_found_identifier(t_type_ident *p_type, int p_all_found)
{
	int	idx;
	int	found_sum;

	if (p_type == 0)
		return (FAIL);
	idx = 0;
	found_sum = 0;
	while (idx < TYPE_MAX)
	{
		found_sum = p_type->found[idx];
		idx++;
	}
	if (found_sum == TYPE_MAX)
		*p_all_found = 1;
	return (SUCESS);
}

int	parse_identifier(int fd, t_parse_info *p_parse, int *p_read_cnt)
{
	char 			*line;
	t_type_ident	type;
	int				ret;
	int				all_found_identifier;

	all_found_identifier = 0;
	while (get_next_line(fd, &line))
	{
		ret = parse_identifier_line(line, p_parse, &type);
		free(line);
		if (ret == FAIL)
			return (FAIL);
		*p_read_cnt++;
		if (is_all_found_identifier(&type, &all_found_identifier) == FAIL)
			return (FAIL);
		if (all_found_identifier)
			break ;
	}
	return (SUCESS);
}

void	parsing_file(t_parse_info *p_parse, char *filename)
{
	int			read_count;
	int			file_fd;

	read_count = 0;

	if (is_end_with(file_name, ".cub") == FAIL)
		return (FAIL);
	file_fd = open(file_name, O_RDONLY);
	if (file_fd == -1)
		return (FAIL);
	if (parse_identifier(file_fd, p_parse, &read_count) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
