/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:53:37 by kyolee            #+#    #+#             */
/*   Updated: 2022/11/22 17:57:41 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include <stdio.h>
#include "key.h"

int	key_press(
		int keycode,
		t_game_info *p_game
		);

int	exit_game(
		t_game_info *p_game,
		int status
	)
{
	(void)p_game;
	exit(status);
	return (status);
}

int	key_exit(
		t_game_info *game
	)
{
	return (exit_game(game, EXIT_SUCCESS));
}

int	key_press(
		int keycode,
		t_game_info *p_game
	)
{
	if (keycode == KEY_W)
		p_game->key.move_forward = PRESS;
	else if (keycode == KEY_S)
		p_game->key.move_backward = PRESS;
	else if (keycode == KEY_A)
		p_game->key.move_left = PRESS;
	else if (keycode == KEY_D)
		p_game->key.move_right = PRESS;
	else if (keycode == KEY_LEFT)
		p_game->key.turn_left = PRESS;
	else if (keycode == KEY_RIGHT)
		p_game->key.turn_right = PRESS;
	else if (keycode == KEY_ESC)
		return (exit_game(p_game, EXIT_SUCCESS));
	return (0);
}
