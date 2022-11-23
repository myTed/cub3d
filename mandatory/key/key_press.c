/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:53:37 by kyolee            #+#    #+#             */
/*   Updated: 2022/11/23 11:20:31 by yehan            ###   ########seoul.kr  */
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
void	destory_mlx_info(
			t_mlx_info *p_mlx
		);
int	exit_game(
		t_game_info *p_game,
		int status
	)
{
	(void)p_game;
	free_parse_info(&(p_game->parse));
	destory_mlx_info(&(p_game->mlx));
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
	return (SUCCESS);
}
