#include "../../include/cub3d.h"
#include "../../include/parse.h"

int	is_valid_char(char c)
{
	if (c == WALL || c == GROUND || \
		c == PLAYER_NORTH || c == PLAYER_SOUTH || \
		c == PLAYER_WEST || c == PLAYER_EAST || \
		c == OUTSIDE1 || c == OUTSIDE2)
		return (TRUE);
	return (FALSE);
}

int	is_map_ground(char c)
{
	if (c == GROUND || \
		c == PLAYER_NORTH || c == PLAYER_SOUTH || \
		c == PLAYER_WEST || c == PLAYER_EAST)
		return (TRUE);
	return (FALSE);
}

static int	is_outside(char c)
{
	if (c == OUTSIDE1 || c == OUTSIDE2)
		return (TRUE);
	else
		return (FALSE);
}

int	is_map_ground_meet_outside(t_map_info *p_map, int x, int y)
{
	if (x == 0 || x == p_map->width
		|| y == 0 || y == p_map->height
		|| is_outside(p_map->data[y][x + 1]) == TRUE
		|| is_outside(p_map->data[y][x - 1]) == TRUE
		|| is_outside(p_map->data[y + 1][x]) == TRUE
		|| is_outside(p_map->data[y - 1][x]) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	is_player(char c)
{
	if (c == PLAYER_NORTH || c == PLAYER_SOUTH || \
		c == PLAYER_WEST || c == PLAYER_EAST)
		return (TRUE);
	return (FALSE);
}
