/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:53:41 by kyolee            #+#    #+#             */
/*   Updated: 2022/11/24 21:58:23 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "parse_bonus.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include "libft.h"
#include "key_bonus.h"

int	update_player(
		t_game_info *p_game
		);
int	move_player(
		t_game_info *p_game
		);

static int	turn_right_player(
			t_game_info *p_game,
			t_vector old_dir,
			t_vector old_view
		)
{
	if (p_game == 0)
		return (FALSE);
	p_game->player.dir.x = \
			old_dir.x * cos(TURN_SPEED) - old_dir.y * sin(TURN_SPEED);
	p_game->player.dir.y = \
			old_dir.x * sin(TURN_SPEED) + old_dir.y * cos(TURN_SPEED);
	p_game->player.view.x = \
			old_view.x * cos(TURN_SPEED) - old_view.y * sin(TURN_SPEED);
	p_game->player.view.y = \
			old_view.x * sin(TURN_SPEED) + old_view.y * cos(TURN_SPEED);
	return (TRUE);
}

static int	turn_left_player(
			t_game_info *p_game,
			t_vector old_dir,
			t_vector old_view
		)
{
	if (p_game == 0)
		return (FALSE);
	p_game->player.dir.x = \
		old_dir.x * cos(-TURN_SPEED) - old_dir.y * sin(-TURN_SPEED);
	p_game->player.dir.y = \
		old_dir.x * sin(-TURN_SPEED) + old_dir.y * cos(-TURN_SPEED);
	p_game->player.view.x = \
		old_view.x * cos(-TURN_SPEED) - old_view.y * sin(-TURN_SPEED);
	p_game->player.view.y = \
		old_view.x * sin(-TURN_SPEED) + old_view.y * cos(-TURN_SPEED);
	return (TRUE);
}

static int	turn_player(
		t_game_info *p_game
	)
{
	int			is_update;
	t_vector	old_dir;
	t_vector	old_view;

	is_update = TRUE;
	ft_memcpy(&old_dir, &(p_game->player.dir), sizeof(t_vector));
	ft_memcpy(&old_view, &(p_game->player.view), sizeof(t_vector));
	if (p_game->key.turn_right == PRESS)
	{
		if (turn_right_player(p_game, old_dir, old_view) == FALSE)
			return (FALSE);
		p_game->key.turn_right = RELEASE;
	}
	else if (p_game->key.turn_left == PRESS)
	{
		if (turn_left_player(p_game, old_dir, old_view) == FALSE)
			return (FALSE);
		p_game->key.turn_left = RELEASE;
	}
	else
		is_update = FALSE;
	return (is_update);
}

int	update_player(
		t_game_info *p_game
	)
{
	int	is_update;

	is_update = FALSE;
	is_update = move_player(p_game);
	is_update |= turn_player(p_game);
	return (is_update);
}
