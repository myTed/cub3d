/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:06:09 by yehan             #+#    #+#             */
/*   Updated: 2022/11/24 18:57:58 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"
#include "raycast.h"
#include <math.h>

int	update_ray_vector(
			const t_player_info *p_player,
			int width_idx,
			t_vector *p_ray
		)
{
	double	view_factor;

	if ((p_player == 0) || (p_ray == 0))
		return (FAIL);
	view_factor = ((double)(2 * width_idx) / SCREEN_WIDTH) - 1;
	p_ray->x = p_player->dir.x + (p_player->view.x * view_factor);
	p_ray->y = p_player->dir.y + (p_player->view.y * view_factor);
	return (SUCCESS);
}

static int	init_distance_info(
							t_game_info *p_game,
							t_vector *p_ray,
							t_wall_dist_info *p_wall_dist,
							t_wall_info *p_wall
						)
{
	if ((p_game == 0) || (p_ray == 0) || (p_wall_dist == 0))
		return (FAIL);
	p_wall_dist->delta_horizon = fabs(1 / p_ray->y);
	p_wall_dist->delta_vertical = fabs(1 / p_ray->x);
	if (p_ray->y < 0)
		p_wall_dist->horizon = p_wall_dist->delta_horizon * \
			(p_game->player.pos.y - p_wall->pos.y);
	else
		p_wall_dist->horizon = p_wall_dist->delta_horizon * \
			(p_wall->pos.y + 1 - p_game->player.pos.y);
	if (p_ray->x < 0)
		p_wall_dist->vertical = p_wall_dist->delta_vertical * \
			(p_game->player.pos.x - p_wall->pos.x);
	else
		p_wall_dist->vertical = p_wall_dist->delta_vertical * \
			(p_wall->pos.x + 1 - p_game->player.pos.x);
	return (SUCCESS);
}

static int	init_step_info(
							const t_vector *p_ray,
							t_wall_dist_info *p_walldist
						)
{
	if ((p_ray == 0) || (p_walldist == 0))
		return (FAIL);
	if (p_ray->y < 0)
		p_walldist->step_horizon = -1;
	else
		p_walldist->step_horizon = 1;
	if (p_ray->x < 0)
		p_walldist->step_vertical = -1;
	else
		p_walldist->step_vertical = 1;
	return (SUCCESS);
}

static int	get_step_distance_and_side_to_nearest_wall(
							t_parse_info *p_parse,
							t_wall_dist_info *p_wall_dist,
							t_wall_info *p_wall,
							t_hit *p_hit_side
						)
{
	int		hitted;
	char	**p_map;

	if ((p_wall_dist == 0) || (p_hit_side == 0))
		return (FAIL);
	hitted = 0;
	p_map = p_parse->map.data;
	while (hitted == 0)
	{
		if (p_wall_dist->horizon < p_wall_dist->vertical)
		{
			p_wall_dist->horizon += p_wall_dist->delta_horizon;
			p_wall->pos.y += p_wall_dist->step_horizon;
			*p_hit_side = HORIZON;
		}
		else
		{
			p_wall_dist->vertical += p_wall_dist->delta_vertical;
			p_wall->pos.x += p_wall_dist->step_vertical;
			*p_hit_side = VERTICAL;
		}
		if (p_map[p_wall->pos.y][p_wall->pos.x] == WALL)
			hitted = 1;
	}
	return (SUCCESS);
}

int	find_wall_distance(
			t_game_info *p_game,
			t_vector *p_ray,
			t_hit *p_hit_side,
			t_wall_info *p_wall
		)
{
	t_wall_dist_info	wall_dist;

	if ((p_game == 0) || (p_ray == 0) || (p_hit_side == 0) || (p_wall == 0))
		return (FAIL);
	p_wall->pos.x = (int)(p_game->player.pos.x);
	p_wall->pos.y = (int)(p_game->player.pos.y);
	if (init_distance_info(p_game, p_ray, &wall_dist, p_wall) == FAIL)
		return (FAIL);
	if (init_step_info(p_ray, &wall_dist) == FAIL)
		return (FAIL);
	if (get_step_distance_and_side_to_nearest_wall(&(p_game->parse), \
		&wall_dist, p_wall, p_hit_side) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
