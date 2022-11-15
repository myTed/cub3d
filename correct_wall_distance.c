#include "cube.h"

void set_correct_wall_distance(t_game_info *p_game, t_wall_info *p_wall, t_vector *p_ray) {
	if (p_wall->hit_side == WALL_VERTICAL)
	{
		if (p_ray->x > 0)
			p_wall->corrected_distance = (p_wall->pos.x - p_game->player.pos.x) / p_ray->x;
		else
			p_wall->corrected_distance = ((p_wall->pos.x + 1) - p_game->player.pos.x) / p_ray->x;
	}
	else /* (hitted_side == WALL_HORIZON) */
	{
		if (p_ray->y > 0)
			p_wall->corrected_distance = (p_wall->pos.y - p_game->player.pos.y) / p_ray->y;
		else
			p_wall->corrected_distance = ((p_wall->pos.y + 1) - p_game->player.pos.y) / p_ray->y;
	}
}