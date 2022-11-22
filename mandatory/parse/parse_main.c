#include "../../include/cub3d.h"
#include "../../include/parse.h"
#include "../../gnl/ft_gnl.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static int	is_all_found_identifier(t_type_ident *p_type, int *p_all_found)
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

int	is_end_with_extension(char *file_name, char *extension, int *p_valid);

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

int	init_type_ident(t_type_ident *p_type);
int	parse_identifier_line(char *line, \
	t_parse_info *p_parse, t_type_ident *p_type);

static int	parse_identifier(int fd, t_parse_info *p_parse, int *p_read_cnt)
{
	char					*line;
	t_type_ident	type;
	int						all_found_identifier;

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

char	*find_first_line(int file_fd, int *read_count);
int		set_map_size(int file_fd, t_map_info *p_map, int read_count);
int		set_map_data(char *file_name, t_map_info *p_map, int map_start_count);
int		is_map_error(t_map_info *p_map, t_game_info *p_game);

static int	get_map(int file_fd, char *file_name, \
	t_game_info *p_game, int read_count)
{
	char	*line;

	line = find_first_line(file_fd, &read_count);
	if (line == 0)
		return (FAIL);
	if (set_map_size(file_fd, &(p_game->parse.map), read_count) == FAIL)
	{
		close(file_fd);
		return (FAIL);
	}
	close(file_fd);
	if (set_map_data(file_name, &(p_game->parse.map), read_count) == FAIL)
		return (FAIL);
	if (is_map_error(&(p_game->parse.map), p_game) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	init_parse_and_player_info(t_game_info *p_game, char *file_name)
{
	int	read_count;
	int	file_fd;
	int	valid_name;

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
