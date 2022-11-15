#include "cub3d.h"
#include <math.h>

typedef struct s_wall_info
{
	double	dist_vertical;
	double	dist_horizon;
	double	delta_dist_vertical;
	double	delta_dist_horizon;
	int		step_vertical;
	int		step_horizon;
} t_wall_dist_info;

int	update_ray_vector(const *t_player p_player, int width_idx, t_vector *p_ray)
{
	double view_factor;

	if ((p_player == 0) || (p_ray == 0))
		return (-1);
	view_factor = (2 * width_idx / SCREEN_WIDTH) - 1;
	p_ray->x = p_player->dir.x + (p_player->view.x * view_factor);
	p_ray->y = p_player->dir.y + (p_player->view.y * view_factor);
	return (0);
}

static int	init_distance_info(
				t_game_info *pgi,
				t_vector *p_ray,
				t_wall_dist_info *pwi
){
	if ((pgi == 0) || || (p_ray == 0) || (pwi == 0))
		return (-1);
	pwi->delta_dist_horizon = fabs(1/p_ray->y);
	pwi->delta_dist_vertical = fabs(1/p_ray->x);
	if (p_ray->y < 0)
		pwi->dist_horizon = pwi->delta_dist_horizon *\
							(pgi->player.pos.y - pgi->map.y);
	else
		pwi->dist_horizon = pwi->delta_dist_horizon *\
							(pgi->map.y + 1 - pgi->player.pos.y);
	if (p_ray->x < 0)
		pwi->dist_vertical = pwi->delta_dist_vertical *\
							 (pgi->player.pos.x - pgi->map.x);
	else
		pwi->dist_vertical = pwi->delta_dist_vertical *\
							 (pgi->map.x + 1- pgi->player.pos.x);
	return (0);
}

static int	init_step_info(
				const t_vector *p_ray,
				t_wall_dist_info *p_walldist
){
	if ((p_ray == 0) || (p_walldist == 0))
		return (-1);
	if (p_ray->y < 0)
		p_walldist->step_horizon = -1;
	else
		p_walldist->step_horizon = 1;
	if (p_ray->x < 0)
		p_walldist->step_vertical = -1;
	else
		p_walldist->step_vertical = 1;
	return (0);
}

int	get_step_distance_and_side_to_nearest_wall(
		t_wall_dist_info *pwi, 
		t_hit *phit_side
){
	int		hitted;

	if ((pwi == 0) || (phit_side == 0))
		return (-1);
	hitted = 0;
	while (hitted == 0)
	{
		if (pwi->dist_horizon < pwi->dist_vertical)
		{
			pwi->dist_horizon += pwi->deta_dist_horizon;
			p_map->y += pwi->step_horizon;
			*p_hit_side = WALL_VERTICAL;
		}
		else
		{
			pwi->dist_vertical += pwi->wall.delta_dist_vertical;
			p_map->x += pwi->step_vertical;
			*p_hit_side = WALL_HORIZON;
		}
		if (pgi->map[p_map->y][p_map->x] == 1)
			hitted = 1;
	}
	return (0);
}

int	find_wall_distance(
		t_game_info *pgi,
		t_vector *pray,
		t_hit *phit
){
	t_wall_dist_info	wall_dist;
	int					hitted;

	if ((pmap == 0) || (pgi == 0) || (pray == 0))
		return (-1);
	if (init_distance_info(&wall_dist) < 0)
		return (-1);
	if (init_step_info(p_ray, &wall_dist) < 0)
		return (-1);
	if (get_step_distance_and_side_to_nearest_wall(&wall_dist, phit) < 0)
		return (-1);
	return (0);
}

