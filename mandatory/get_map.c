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

int	get_map(int file_fd, t_map_info *p_map, t_game_info *p_game, int read_count)
{
	char 				*line;

	//0.빈 라인 넘어가기
	line = find_first_line(file_fd, &read_count);
	if (line == 0)
		return (FAIL);

	//0.맵사이즈 얻고 (read_count는 map의 처음으로 픽스)
	if (set_map_size(file_fd, p_map, read_count) == FAIL)
	{
		close(file_fd);
		return (FAIL);
	}
	close(file_fd);

	//변수 체크
	//printf("%d, %d\n", map.width, map.height);

	//0.read_count부터 맵 정보 할당 후 저장
	set_map_data("map.cub", p_map, read_count);

	//맵 출력
	int i = 0;
	while (i < p_map->height)
	{
		printf("%s\n", p_map->data[i]);
		i++;
	}

	//0.맵 체크 및 플레이어 정보 저장
	if (is_map_error(p_map, p_game) == FAIL)
		return (FAIL);

	//변수 체크
	// printf("dir: %f, %f\n", game.player.dir.x, game.player.dir.y);
	// printf("pos: %f, %f\n", game.player.pos.x, game.player.pos.y);
	return (SUCCESS);
}

//테스트용 메인

int main()
{
	t_map_info	map;
	t_game_info game;
	int 				read_count;

	int fd = open("map.cub", O_RDONLY);
	if (fd == -1)
		return (1);

	read_count = 0;

	//kyolee님 함수

	//yehan function: read_count, map, game 받아온다
	if (get_map(fd, &map, &game, read_count) == FAIL)
		return (FAIL);

}
