/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_calculate_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:53:25 by kyolee            #+#    #+#             */
/*   Updated: 2022/11/22 18:06:29 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_forward_new_pos(
		t_game_info *p_game,
		const t_vector *p_cur_pos,
		t_vector *p_new_pos
	)
{
	p_new_pos->y = p_cur_pos->y + (p_game->player.dir.y * MOVE_SPEED);
	p_new_pos->x = p_cur_pos->x + (p_game->player.dir.x * MOVE_SPEED);
}

static void	calculate_backward_new_pos(
		t_game_info *p_game,
		const t_vector *p_cur_pos,
		t_vector *p_new_pos
	)
{
	p_new_pos->y = p_cur_pos->y - (p_game->player.dir.y * MOVE_SPEED);
	p_new_pos->x = p_cur_pos->x - (p_game->player.dir.x * MOVE_SPEED);
}

static void	calculate_right_new_pos(
		t_game_info *p_game,
		const t_vector *p_cur_pos,
		t_vector *p_new_pos
	)
{
	p_new_pos->y = p_cur_pos->y + (p_game->player.view.y * MOVE_SPEED);
	p_new_pos->x = p_cur_pos->x + (p_game->player.view.x * MOVE_SPEED);
}

static void	calculate_left_new_pos(
		t_game_info *p_game,
		const t_vector *p_cur_pos,
		t_vector *p_new_pos
	)
{
	p_new_pos->y = p_cur_pos->y - (p_game->player.view.y * MOVE_SPEED);
	p_new_pos->x = p_cur_pos->x - (p_game->player.view.x * MOVE_SPEED);
}

int	calculate_new_pos(
		t_game_info *p_game,
		t_vector *p_cur_pos,
		t_vector *p_new_pos
	)
{
	if ((p_game == 0) || (p_cur_pos == 0) || (p_new_pos == 0))
		return (FALSE);
	if (p_game->key.move_forward == PRESS)
	{	
		calculate_forward_new_pos(p_game, p_cur_pos, p_new_pos);
		p_game->key.move_forward = RELEASE;
	}
	else if (p_game->key.move_backward == PRESS)
	{
		calculate_backward_new_pos(p_game, p_cur_pos, p_new_pos);
		p_game->key.move_backward = RELEASE;
	}
	else if (p_game->key.move_right == PRESS)
	{
		calculate_right_new_pos(p_game, p_cur_pos, p_new_pos);
		p_game->key.move_right = RELEASE;
	}
	else if (p_game->key.move_left == PRESS)
	{
		calculate_left_new_pos(p_game, p_cur_pos, p_new_pos);
		p_game->key.move_left = RELEASE;
	}
	else
		return (FALSE);
	return (TRUE);
}
