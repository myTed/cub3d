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
