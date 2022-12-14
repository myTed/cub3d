/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyolee <kyolee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:25:28 by yehan             #+#    #+#             */
/*   Updated: 2022/11/23 17:06:52 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse.h"
#include <stdio.h>

int	is_valid_char(char c);
int	is_map_ground(char c);
int	is_map_ground_meet_outside(t_map_info *p_map, int x, int y);
int	is_player(char c);

static void	init_player_dir(
				t_game_info *p_game,
				t_map_info *p_map,
				int x,
				int y
			)
{
	if (p_map->data[y][x] == PLAYER_NORTH)
	{
		p_game->player.dir.x = 0;
		p_game->player.dir.y = -1;
	}
	else if (p_map->data[y][x] == PLAYER_SOUTH)
	{
		p_game->player.dir.x = 0;
		p_game->player.dir.y = 1;
	}
	else if (p_map->data[y][x] == PLAYER_WEST)
	{
		p_game->player.dir.x = -1;
		p_game->player.dir.y = 0;
	}
	else
	{
		p_game->player.dir.x = 1;
		p_game->player.dir.y = 0;
	}
}

static void	init_player_view(
				t_game_info *p_game,
				t_map_info *p_map,
				int x,
				int y
			)
{
	if (p_map->data[y][x] == PLAYER_NORTH)
	{
		p_game->player.view.x = VIEW;
		p_game->player.view.y = 0;
	}
	else if (p_map->data[y][x] == PLAYER_SOUTH)
	{
		p_game->player.view.x = -VIEW;
		p_game->player.view.y = 0;
	}
	else if (p_map->data[y][x] == PLAYER_WEST)
	{
		p_game->player.view.x = 0;
		p_game->player.view.y = -VIEW;
	}
	else
	{
		p_game->player.view.x = 0;
		p_game->player.view.y = VIEW;
	}
}

static int	init_player_info(
				t_game_info *p_game,
				t_map_info *p_map,
				int x,
				int y
			)
{
	static int	is_done = FALSE;

	if (is_done == 1)
		return (FAIL);
	p_game->player.pos.x = x + 0.5;
	p_game->player.pos.y = y + 0.5;
	init_player_dir(p_game, p_map, x, y);
	init_player_view(p_game, p_map, x, y);
	p_map->data[y][x] = GROUND;
	is_done = TRUE;
	return (SUCCESS);
}

static int	is_error(
				t_game_info *p_game,
				t_map_info *p_map,
				int x,
				int y
			)
{
	if (is_valid_char(p_map->data[y][x]) == FALSE)
	{
		printf("Error\n: invalid character!!\n");
		return (TRUE);
	}
	if (is_map_ground(p_map->data[y][x]) == TRUE && \
		is_map_ground_meet_outside(p_map, x, y) == TRUE)
	{
		printf("%d. %d\n", x, y);
		printf("Error\n: ground is not closed by the wall!!\n");
		return (TRUE);
	}
	if (is_player(p_map->data[y][x]) == TRUE && \
		init_player_info(p_game, p_map, x, y) == FAIL)
	{
		printf("Error\n: more than 1 player!!\n");
		return (TRUE);
	}
	return (FALSE);
}

int	is_map_error(
		t_map_info *p_map,
		t_game_info *p_game
	)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_map->height)
	{
		x = 0;
		while (x < p_map->width)
		{
			if (is_error(p_game, p_map, x, y) == TRUE)
				return (FAIL);
			x++;
		}
		y++;
	}
	if (init_player_info(p_game, p_map, 0, 0) == SUCCESS)
	{
		printf("Error\n: no player!!\n");
		return (FAIL);
	}
	return (SUCCESS);
}
