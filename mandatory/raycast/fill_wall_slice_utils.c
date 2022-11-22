/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wall_slice_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:06:05 by yehan             #+#    #+#             */
/*   Updated: 2022/11/22 17:09:21 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/raycast.h"
#include <math.h>

int	set_pixel(t_img *pimg, int y, int x, t_color color);

static t_img	*get_texture(
								t_game_info *p_game,
								const t_wall_info *p_wall,
								const t_vector *p_ray
							)
{
	if (p_wall->hit_side == VERTICAL)
	{
		if (p_ray->x > 0)
			return (&(p_game->mlx.east_img));
		else
			return (&(p_game->mlx.west_img));
	}
	else
	{
		if (p_ray->y > 0)
			return (&(p_game->mlx.south_img));
		else
			return (&(p_game->mlx.north_img));
	}
}

static int	get_texture_offset_x(
							t_game_info *p_game,
							const t_slice_info *p_slice,
							const t_wall_info *p_wall,
							const t_vector *p_ray
						)
{
	double	map_offset_x;
	double	wall_offset_x;
	int		texture_offset_x;

	if (p_wall->hit_side == VERTICAL)
		map_offset_x = \
			p_game->player.pos.y + (p_wall->corrected_distance * p_ray->y);
	else
		map_offset_x = \
			p_game->player.pos.x + (p_wall->corrected_distance * p_ray->x);
	wall_offset_x = map_offset_x - floor(map_offset_x);
	texture_offset_x = \
		(int)(wall_offset_x * (double)(p_slice->p_texture_img->width));
	if ((p_wall->hit_side == VERTICAL && p_ray->x < 0) || \
		(p_wall->hit_side == HORIZON && p_ray->y > 0))
		texture_offset_x = p_slice->p_texture_img->width - texture_offset_x - 1;
	return (texture_offset_x);
}

static double	get_texture_offset_y(t_slice_info *p_slice)
{
	if (p_slice->draw_top < 0)
		return (-(p_slice->draw_top) * p_slice->texture_step_y);
	else
		return (0);
}

void	fill_slice_info(
				t_game_info *p_game,
				t_slice_info *p_slice,
				const t_wall_info *p_wall,
				const t_vector *p_ray
			)
{
	double	draw_height;

	draw_height = (double)SCREEN_HEIGHT / p_wall->corrected_distance;
	draw_height = \
		draw_height * ((double)SCREEN_WIDTH / (double)SCREEN_HEIGHT / 2);
	p_slice->p_texture_img = get_texture(p_game, p_wall, p_ray);
	p_slice->texture_offset_x = \
		get_texture_offset_x(p_game, p_slice, p_wall, p_ray);
	p_slice->texture_step_y = p_slice->p_texture_img->height / draw_height;
	p_slice->draw_top = ((double)(SCREEN_HEIGHT) / 2) - (draw_height / 2);
	p_slice->texture_offset_y = get_texture_offset_y(p_slice);
	if (p_slice->draw_top < 0)
		p_slice->draw_top = 0;
	p_slice->draw_bottom = (SCREEN_HEIGHT / 2) + (draw_height / 2);
	if (p_slice->draw_bottom > SCREEN_HEIGHT)
		p_slice->draw_bottom = SCREEN_HEIGHT;
}
