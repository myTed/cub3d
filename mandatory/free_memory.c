#include "../include/cub3d.h"
#include <stdlib.h>

void	free_map(t_map_info *p_map)
{
	int	i;

	i = 0;
	if (p_map != 0)
	{
		while (i < p_map->height)
		{
			free(p_map->data[i]);
			i++;
		}
		free(p_map->data);
	}
}