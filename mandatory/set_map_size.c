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

int set_map_data(char *file_name, t_map_info *p_map, int map_start_count);

int is_empty_line(char *line)
{
	char *data;

	if (line == 0)
		return (TRUE);
	data = ft_strtrim(line, " \n");
	if (ft_strlen(data) == 0)
		return (TRUE);
	else
		return (FALSE);
}

char *find_first_line(int file_fd, int *read_count)
{
	char *line;

	line = get_next_line(file_fd);
	while (is_empty_line(line) == TRUE)
	{
		if (line == 0)
		{
			printf("Error\n: no map!!");
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(file_fd);
		(*read_count)++;
	}
	return (line);
}

int is_remains(int file_fd, char *line)
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

int set_map_size(int file_fd, t_map_info *p_map, int read_count)
{
	char *line;
	int line_len;
	int map_start_count;

	// 맵 시작지점 저장
	map_start_count = read_count;

	//map 가로, 세로 저장
	p_map->width = 0;
	while (line != 0 && is_empty_line(line) == FALSE)
	{
		line = ft_strtrim(line, "\n");
		line_len = ft_strlen(line);
		if (p_map->width < line_len)
	 		p_map->width = line_len;
		free(line);
		line = get_next_line(file_fd);
		read_count++;
	}
	p_map->height = read_count - map_start_count;

	//3. 맵 뒤에 정보 더 있는지 체크
	if (is_remains(file_fd, line) == TRUE)
		return (FAIL);

	return (SUCCESS);
}

int main()
{
	t_map_info	map;
	int 				read_count;
	char 				*line;

	int fd = open("map.cub", O_RDONLY);
	if (fd == -1)
		return (1);

	read_count = 0;

	//kyolee님 함수

	//yehan function: read_count, map, game 받아온다

	//0.빈 라인 넘어가기
	line = find_first_line(fd, &read_count);
	if (line == 0)
		return (FAIL);

	//0.맵사이즈 얻고 (read_count는 map의 처음으로 픽스)
	if (set_map_size(fd, &map, read_count) == FAIL)
	{
		close(fd);
		return (FAIL);
	}
	close(fd);

	//printf("%d, %d\n", map.width, map.height);

	//0.read_count부터 맵 정보 저장
	set_map_data("map.cub", &map, read_count);

	//0.맵 체크 및 정보 저장
	//if (is_map_error(&map) == TRUE)
	//	return (FAIL);

	//체크용 함수
	int i = 0;
	while (i < map.height)
	{
		printf("%s\n", map.data[i]);
		//printf("%d", i);
		i++;
	}
}
