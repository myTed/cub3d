/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:10:13 by kyolee            #+#    #+#             */
/*   Updated: 2022/11/24 22:01:20 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

/*
 * UTILS
 */

typedef enum e_hit
{
	NO = 0,
	HORIZON,
	VERTICAL
}	t_hit;

typedef struct s_wall_pos
{
	int	x;
	int	y;
}	t_wall_pos;

/*
 * KEY STRUCTS 
 */

typedef struct s_wall_dist_info
{
	double	vertical;
	double	horizon;
	double	delta_vertical;
	double	delta_horizon;
	int		step_vertical;
	int		step_horizon;
}	t_wall_dist_info;

typedef struct s_wall_info
{
	double		corrected_distance;
	t_wall_pos	pos;
	t_hit		hit_side;
}	t_wall_info;

typedef struct s_slice_info
{
	t_img	*p_texture_img;
	int		draw_top;
	int		draw_bottom;
	double	texture_offset_x;
	double	texture_offset_y;
	double	texture_step_y;
}	t_slice_info;

#endif
