#include "cub3d.h"
#include <fcntl.h>

#define SUCCESS 0
#define FAIL 1

int init_parse_info(t_parse_info *p_parse, char *filename)
{
	int			file_fd;
	char		*line;
	int			r;
	unsigned int	**map;

	if (is_end_with(filename, ".cub") == FAIL)
		return (FAIL);

	if ((file_fd = open(filename, O_RDONLY)) < 0)
		return (0);

	map = NULL;
	
	r = 1;
	while (get_next_line(file_fd, &line))
	{
		parse_line(p_parse, line, &map);//경우의 수 3가지에 대해서 작업
		free(line);
	}
	
	if (r && ft_strlen(line) > 0)
		r = !!str_add_back(&map, ft_strdup(line));
	free(line);
	close(file_fd);
	if (!r || !parse_map(p_parse, map))
		return (str_clear(&map));
	str_clear(&map);
	return (1);
}

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
