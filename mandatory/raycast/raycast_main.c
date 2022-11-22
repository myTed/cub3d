/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:06:11 by yehan             #+#    #+#             */
/*   Updated: 2022/11/22 19:00:46 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycast.h"

int		update_ray_vector(const t_player_info *p_player, \
	int width_idx, t_vector *p_ray);
int		find_wall_distance(t_game_info *pgi, t_vector *pray, \
	t_hit *phit, t_wall_info *p_wall);
int		set_correct_wall_distance(t_game_info *p_game, \
	t_wall_info *p_wall, t_vector *p_ray);
void	fill_wall_slice(t_game_info *p_game, const t_vector *p_ray, \
	const t_wall_info *p_wall, const int width_idx);
int		draw_screen(t_game_info *p_game);

int	update_screen(t_game_info *p_game)
{
	t_vector		ray;
	t_wall_info		wall;
	int				width_idx;

	width_idx = 0;
	while (width_idx < SCREEN_WIDTH)
	{
		if (update_ray_vector(&(p_game->player), width_idx, &ray) == FAIL)
			return (FAIL);
		if (find_wall_distance(p_game, &ray, &wall.hit_side, &wall) == FAIL)
			return (FAIL);
		if (set_correct_wall_distance(p_game, &wall, &ray) == FAIL)
			return (FAIL);
		fill_wall_slice(p_game, &ray, &wall, width_idx);
		width_idx++;
	}
	if (draw_screen(p_game) == FAIL)
		return (FAIL);
	return (0);
}
