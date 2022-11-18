#include "../include/cub3d.h"
#include "../libft/libft.h"
#include "../gnl/ft_gnl.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

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
			printf("Error: no map");
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
				return (FALSE);
			free(line);
			line = get_next_line(file_fd);
		}
		printf("Error: contents after map");
		return (TRUE);
}
int set_map_size(int file_fd, t_map_info *p_map, int pre_read_count)
{
	char *line;
	int read_count;
	int map_start_count;
	int line_len;

	//빈 라인 넘어가기
	read_count = pre_read_count;
	line = find_first_line(file_fd, &read_count);

	// 맵이 시작지점 저장
	map_start_count = read_count;

	//map 가로, 세로 저장
	p_map->width = 0;
	while (line != 0 && is_empty_line(line) == FALSE)
	{
		line_len = ft_strlen(line);//newline 같이 저장
		if (p_map->width < line_len)
	 		p_map->width = line_len;
		free(line);
		line = get_next_line(file_fd);
		read_count++;
	}
	p_map->height = read_count - map_start_count;

	//3. 맵 뒤에 정보 더 있는지 체크
	if (is_remains(file_fd, line) == TRUE)
		return (1);

	return (0);
}

int main()
{
	t_map_info map;
	int read_count;

	int fd = open("map.cub", O_RDONLY);
	if (fd == -1)
		return (1);
	read_count = 0;
	set_map_size(fd, &map, read_count);
	allocate_map(fd, &map);
	//printf("%d, %d", map.width, map.height);


}