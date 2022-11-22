/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:53:33 by kyolee            #+#    #+#             */
/*   Updated: 2022/11/22 17:57:18 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"

int	move_player(
		t_game_info *p_game
		);

int	calculate_new_pos(
		t_game_info *p_game,
		t_vector *p_cur_pos,
		t_vector *p_new_pos
		);

static int	is_ground(
		t_game_info *p_game,
		double new_pos_y,
		double new_pos_x
	)
{
	char	**p_map;

	p_map = p_game->parse.map.data;
	return (p_map[(int)(new_pos_y)][(int)(new_pos_x)] == GROUND);
}

static int	corrected_new_pos(
		t_game_info *p_game,
		t_vector *p_new_pos
	)
{
	t_vector	cur_pos;

	if (p_game == 0 || p_new_pos == 0)
		return (FALSE);
	cur_pos.x = p_game->player.pos.x;
	cur_pos.y = p_game->player.pos.y;
	if ((double)(p_new_pos->x) - (double)((int)(p_new_pos->x)) < 0.0001)
	{
		if (p_new_pos->x - cur_pos.x > 0)
			p_new_pos->x += 0.01;
		else
			p_new_pos->x -= 0.01;
	}
	if ((double)(p_new_pos->y) - (double)((int)(p_new_pos->y)) < 0.0001)
	{
		if (p_new_pos->y - cur_pos.y > 0)
			p_new_pos->y += 0.01;
		else
			p_new_pos->y -= 0.01;
	}
	return (TRUE);
}

static int	update_player_pos(
		t_game_info *p_game,
		t_vector new_pos,
		t_vector cur_pos
	)
{
	if (p_game == 0)
		return (FALSE);
	if (is_ground(p_game, new_pos.y, new_pos.x) == TRUE)
	{	
		p_game->player.pos.x = new_pos.x;
		p_game->player.pos.y = new_pos.y;
	}
	else if (is_ground(p_game, new_pos.y, cur_pos.x) == TRUE)
	{
		p_game->player.pos.x = cur_pos.x;
		p_game->player.pos.y = new_pos.y;
	}
	else if (is_ground(p_game, cur_pos.y, new_pos.x) == TRUE)
	{	
		p_game->player.pos.x = new_pos.x;
		p_game->player.pos.y = cur_pos.y;
	}
	return (TRUE);
}

int	move_player(
		t_game_info *p_game
	)
{
	t_vector	new_pos;
	t_vector	cur_pos;
	int			is_update;

	if (p_game == 0)
		return (FALSE);
	cur_pos.x = p_game->player.pos.x;
	cur_pos.y = p_game->player.pos.y;
	is_update = FALSE;
	if (calculate_new_pos(p_game, &cur_pos, &new_pos) == FALSE)
		return (is_update);
	is_update = TRUE;
	if (corrected_new_pos(p_game, &new_pos) == FALSE)
		return (FALSE);
	if (update_player_pos(p_game, new_pos, cur_pos) == FALSE)
		return (FALSE);
	return (is_update);
}
