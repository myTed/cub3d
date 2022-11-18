#include "cub3d.h"

#define TRUE 1
#define FALSE 0

#define FAIL 1
#define SUCCESS 0


int is_outside(char c)
{
	if (c == ' ' || c == '\n' || c == '\0')
		return (TRUE);
	else
		return (FALSE);
}

int is_ground_surrounded(t_map_info *p_map, int x,  int y)
{
	if (x == 0 || x == p_map->width
		|| y == 0 || y == p_map->height
		|| is_outside(map[y][x + 1]) == TRUE
		|| is_outside(map[y][x - 1]) == TRUE
		|| is_outside(map[y + 1][x]) == TRUE
		|| is_outside(map[y - 1][x]) == TRUE)
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
			//1, 0, N, S, E, W, space, newline인지 체크
			if (is_invalid_char(map[y][x]) == TRUE)
			{
				printf("Error\n: invalid char!!");
				return (FAIL);
			}

			//0, N, S, E, W 일 때 둘러싸여 있는지 체크
			if (is_ground(map[y][x]) == TRUE)
			{
				if (is_ground_surrounded(p_map, x, y) == FALSE)
				{
					printf("Error\n: ground is not closed by the wall");
					return (FAIL);
				}
			}

			//player 정보 저장
			if (is_player(map[x][y]) == TRUE)
			{
				init_player_info(map[x][y], x, y);
			}
		}
	}
}