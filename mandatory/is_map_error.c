#include "../include/cub3d.h"
#include <stdio.h>

int is_valid_char(char c)
{
	if (c == WALL || c == GROUND ||
		c == PLAYER_NORTH || c == PLAYER_SOUTH ||
		c == PLAYER_WEST || c == PLAYER_EAST ||
		c == OUTSIDE1 || c == OUTSIDE2)
		return (TRUE);
	return (FALSE);
}

int	is_ground(char c)
{
	if (c == GROUND ||
		c == PLAYER_NORTH || c == PLAYER_SOUTH ||
		c == PLAYER_WEST || c == PLAYER_EAST)
		return (TRUE);
	return (FALSE);
}

int is_outside(char c)
{
	if (c == OUTSIDE1 || c == OUTSIDE2)
		return (TRUE);
	else
		return (FALSE);
}

int is_ground_meet_outside(t_map_info *p_map, int x,  int y)
{
	if (x == 0 || x == p_map->width
		|| y == 0 || y == p_map->height
		|| is_outside(p_map->data[y][x + 1]) == TRUE
		|| is_outside(p_map->data[y][x - 1]) == TRUE
		|| is_outside(p_map->data[y + 1][x]) == TRUE
		|| is_outside(p_map->data[y - 1][x]) == TRUE)
	{
		return (TRUE);
	}
	return (FALSE);
}

int	is_player(char c)
{
	if (c == PLAYER_NORTH || c == PLAYER_SOUTH ||
		c == PLAYER_WEST || c == PLAYER_EAST)
		return (TRUE);
	return (FALSE);
}

void	init_player_dir(t_game_info *p_game, t_map_info *p_map, int x, int y)
{
	static char dir_x[4] = {0, 0, -1, 1};
	static char dir_y[4] = {-1, 1, 0, 0};

	if (p_map->data[y][x] == 'N')
	{
		p_game->player.dir.x = dir_x[0];
		p_game->player.dir.y = dir_y[0];
	}
	else if (p_map->data[y][x] == 'S')
	{
		p_game->player.dir.x = dir_x[1];
		p_game->player.dir.y = dir_y[1];
	}
	else if (p_map->data[y][x] == 'W')
	{
		p_game->player.dir.x = dir_x[2];
		p_game->player.dir.y = dir_y[2];
	}
	else
	{
		p_game->player.dir.x = dir_x[3];
		p_game->player.dir.y = dir_y[3];
	}
}

int	init_player_info(t_game_info *p_game, t_map_info *p_map, int x, int y)
{
	static int is_done = FALSE;

	if (is_done == 1)
		return (FAIL);
	p_game->player.pos.x = x;
	p_game->player.pos.y = y;
	p_game->player.view.x = VIEW_X;
	p_game->player.view.x = VIEW_Y;
	init_player_dir(p_game, p_map, x, y);
	is_done = TRUE;
	return (SUCCESS);
}

int is_map_error(t_map_info *p_map, t_game_info *p_game)
{
	int x;
	int y;

	y = 0;
	while (y < p_map->height)
	{
		x = 0;
		while (x < p_map->width)
		{
			if (is_valid_char(p_map->data[y][x]) == FALSE)
			{
				printf("Error\n: invalid character!!\n");
				return (FAIL);
			}
			if (is_ground(p_map->data[y][x]) == TRUE)
			{
				if (is_ground_meet_outside(p_map, x, y) == TRUE)
				{
					printf("Error\n: ground is not closed by the wall!!\n");
					return (FAIL);
				}
			}
			if (is_player(p_map->data[y][x]) == TRUE)
			{
				if (init_player_info(p_game, p_map, x, y) == FAIL)
				{
					printf("Error\n: more than 1 player!!\n");
					return (FAIL);
				}
			}

			x++;
		}
		y++;
	}
	if (init_player_info(p_game, p_map, 0, 0) == SUCCESS)
	{
			printf("Error\n: no player!!\n");
			return (FAIL);
	}
	return (SUCCESS);
}
