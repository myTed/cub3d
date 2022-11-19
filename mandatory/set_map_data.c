#include "../include/cub3d.h"
#include "../libft/libft.h"
#include "../gnl/ft_gnl.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define FAIL 1
#define SUCCESS 0

void go_nth_line(int fd, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		get_next_line(fd);
		i++;
	}
}

int set_all_line(int file_fd, t_map_info *p_map)
{
	char *line_dest;
	char *line_src;
	int i;

	i = 0;
	while (i < p_map->height)
	{
		line_dest = ft_calloc(1, p_map->width);
		if (line_dest == 0)
		{
			perror("Error\n");
			return (FAIL);
		}
		line_src = get_next_line(file_fd);
		line_src = ft_strtrim(line_src, "\n");
		//printf("%s", line_src);//////////////////////////////////////
		ft_strlcpy(line_dest, line_src, ft_strlen(line_src) + 1);
		p_map->data[i] = line_dest;
		free(line_src);
		i++;
	}
	return (SUCCESS);
}

int set_map_data(char *file_name, t_map_info *p_map, int map_start_count)
{
	int file_fd;

	//맵 최소사이즈 체크
	if (p_map->width < 3 || p_map->height < 3)
	{
		printf("Error\n: less than minimum size!!");
		return (FAIL);
	}

	//파일 열기
	file_fd = open(file_name, O_RDONLY);
	if (file_fd < 0)
	{
		perror("Error\n");
		return (FAIL);
	}

	//넘어가기
	go_nth_line(file_fd, map_start_count);

	//높이만큼 할당
	p_map->data = ft_calloc(sizeof(int *), p_map->height);
	if (p_map->data == 0)
	{
		perror("Error\n");
		close(file_fd);
		return (FAIL);
	}

	//할당 후  gnl로 받은 거 복사하기
	set_all_line(file_fd, p_map);
	close(file_fd);

	return (SUCCESS);
}
