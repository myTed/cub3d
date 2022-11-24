/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_wall_distance.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:06:02 by yehan             #+#    #+#             */
/*   Updated: 2022/11/24 19:32:59 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "raycast_bonus.h"

int	set_correct_wall_distance(t_game_info *p_game, \
	t_wall_info *p_wall, t_vector *p_ray)
{
	if (p_wall->hit_side == VERTICAL)
	{
		if (p_ray->x > 0)
			p_wall->corrected_distance = \
				(p_wall->pos.x - p_game->player.pos.x) / p_ray->x;
		else
			p_wall->corrected_distance = \
				((p_wall->pos.x + 1) - p_game->player.pos.x) / p_ray->x;
		return (SUCCESS);
	}
	else if (p_wall->hit_side == HORIZON)
	{
		if (p_ray->y > 0)
			p_wall->corrected_distance = \
				(p_wall->pos.y - p_game->player.pos.y) / p_ray->y;
		else
			p_wall->corrected_distance = \
				((p_wall->pos.y + 1) - p_game->player.pos.y) / p_ray->y;
		return (SUCCESS);
	}
	else
		return (FAIL);
}
