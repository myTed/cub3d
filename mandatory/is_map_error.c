#include "../include/cub3d.h"
#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define FAIL 1
#define SUCCESS 0

typedef enum e_charset
{
	WALL = '1',
	GROUND = '0',
	PLAYER_NORTH = 'N',
	PLAYER_SOUTH = 'S',
	PLAYER_EAST = 'E',
	PLAYER_WEST = 'W',
	OUTSIDE1 = ' ',
	OUTSIDE2 = '\0'
} t_charset;

int is_valid_char(char c)
{
	if (c == WALL || c == GROUND ||
		c == PLAYER_NORTH || c == PLAYER_SOUTH ||
		c == PLAYER_EAST || c == PLAYER_WEST ||
		c == OUTSIDE1 || c == OUTSIDE2)
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

int	is_ground(char c)
{
	if (c == GROUND ||
		c == PLAYER_NORTH || c == PLAYER_SOUTH ||
		c == PLAYER_EAST || c == PLAYER_WEST)
		return (TRUE);
	return (FALSE);
}

int is_ground_meet_outside(t_map_info *p_map, int x,  int y)
{
	//맵 가(끄트머리)에 있거나
	if (x == 0 || x == p_map->width
		|| y == 0 || y == p_map->height
	//맵 안쪽에 있는데, 주변에 바깥을 의미하는 문자가 있다
		|| is_outside(p_map->data[y][x + 1]) == TRUE
		|| is_outside(p_map->data[y][x - 1]) == TRUE
		|| is_outside(p_map->data[y + 1][x]) == TRUE
		|| is_outside(p_map->data[y - 1][x]) == TRUE)
	{
		return (TRUE);
	}
	return (FALSE);
}

int is_map_error(t_map_info *p_map/*, t_game_info *p_game*/)
{
	int x;
	int y;

	y = 0;
	while (y < p_map->height)
	{
		x = 0;
		while (x < p_map->width)
		{
			//허용된 문자인지 체크
			if (is_valid_char(p_map->data[y][x]) == FALSE)
			{
				printf("Error\n: invalid character!!");
				return (FAIL);
			}

			//길일 때 둘러싸여 있는지 체크
			if (is_ground(p_map->data[y][x]) == TRUE)
			{
				if (is_ground_meet_outside(p_map, x, y) == TRUE)
				{
					printf("Error\n: ground is not closed by the wall!!");
					return (FAIL);
				}
			}

			//player 정보 저장
			// if (is_player(p_map->data[x][y]) == TRUE)
			// {
			// 	init_player_info(p_map->data[x][y], x, y);
			// }

			x++;
		}
		y++;
	}
	return (SUCCESS);
}
