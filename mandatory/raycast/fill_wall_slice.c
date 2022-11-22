/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wall_slice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:06:07 by yehan             #+#    #+#             */
/*   Updated: 2022/11/22 19:01:29 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "raycast.h"

int			set_pixel(t_img *p_img, int y, int x, t_color color);
t_color	get_pixel(t_img *p_img, const int x, const int y);

void	fill_buffer_x(
				t_game_info *p_game,
				t_slice_info *p_slice,
				const int width_idx
			)
{
	int		height_idx;
	t_color	texture;

	height_idx = 0;
	while (height_idx < p_slice->draw_top)
	{
		set_pixel(&p_game->mlx.screen, height_idx, \
			width_idx, p_game->parse.ceiling);
		height_idx++;
	}
	while (height_idx < p_slice->draw_bottom)
	{
		texture = get_pixel(p_slice->p_texture_img, \
			(int)p_slice->texture_offset_x, (int)p_slice->texture_offset_y);
		set_pixel(&p_game->mlx.screen, height_idx, width_idx, texture);
		height_idx++;
		p_slice->texture_offset_y += p_slice->texture_step_y;
	}
	while (height_idx < SCREEN_HEIGHT)
	{
		set_pixel(&p_game->mlx.screen, height_idx, \
			width_idx, p_game->parse.floor);
		height_idx++;
	}
}

void	fill_slice_info(t_game_info *p_game, t_slice_info *p_slice, \
			const t_wall_info *p_wall, const t_vector *p_ray);

void	fill_wall_slice(
				t_game_info *p_game,
				const t_vector *p_ray,
				const t_wall_info *p_wall,
				const int width_idx
			)
{
	t_slice_info	slice;

	ft_memset(&slice, 0, sizeof(t_slice_info));
	fill_slice_info(p_game, &slice, p_wall, p_ray);
	fill_buffer_x(p_game, &slice, width_idx);
}
