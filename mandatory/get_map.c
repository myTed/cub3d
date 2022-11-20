#include "../include/cub3d.h"
#include "../libft/libft.h"
#include "../gnl/ft_gnl.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

#define FAIL 1
#define SUCCESS 0

char *find_first_line(int file_fd, int *read_count);
int set_map_size(int file_fd, t_map_info *p_map, int read_count);
int set_map_data(char *file_name, t_map_info *p_map, int map_start_count);
int is_map_error(t_map_info *p_map, t_game_info *p_game);

int	get_map(int file_fd, char *file_name, t_game_info *p_game, int read_count)
{
	char 				*line;

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

	//맵 출력
	//int i = 0;
	//while (i < p_game->parse.map.height)
	//{
	//	printf("%s\n", p_game->parse.map.data[i]);
	//	i++;
	//}

	//	//변수 체크
	// printf("dir: %f, %f\n", p_game->player.dir.x, p_game->player.dir.y);
	// printf("pos: %f, %f\n", p_game->player.pos.x, p_game->player.pos.y);

	// 	//변수 체크
	//printf("%d, %d\n", p_game->parse.map.width, p_game->parse.map.height);