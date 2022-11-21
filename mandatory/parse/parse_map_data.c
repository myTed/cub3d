#include "../../include/cub3d.h"
#include "../../libft/libft.h"
#include "../../gnl/ft_gnl.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	go_nth_line(int fd, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		get_next_line(fd);
		i++;
	}
}

static int	set_all_line(int file_fd, t_map_info *p_map)
{
	char	*line_dest;
	char	*line_src;
	int		i;

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
		ft_strlcpy(line_dest, line_src, ft_strlen(line_src) + 1);
		p_map->data[i] = line_dest;
		free(line_src);
		i++;
	}
	return (SUCCESS);
}

int	set_map_data(char *file_name, t_map_info *p_map, int map_start_count)
{
	int	file_fd;

	if (p_map->width < 3 || p_map->height < 3)
	{
		printf("Error\n: less than minimum size!!");
		return (FAIL);
	}
	file_fd = open(file_name, O_RDONLY);
	if (file_fd < 0)
	{
		perror("Error\n");
		return (FAIL);
	}
	go_nth_line(file_fd, map_start_count);
	p_map->data = ft_calloc(sizeof(int *), p_map->height);
	if (p_map->data == 0)
	{
		perror("Error\n");
		close(file_fd);
		return (FAIL);
	}
	set_all_line(file_fd, p_map);
	close(file_fd);
	return (SUCCESS);
}
