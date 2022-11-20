#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include "../libft/libft.h"

#define MOVE_SPEED 0.5
#define TURN_SPEED 0.5
#define TRUE 1
#define FALSE 0

//int	is_wall()

int	move_player(t_game_info *p_game)
{
	int	is_update;

	is_update = TRUE;
	if (p_game->key.move_forward == PRESS/* && is_wall() == FALSE)*/)
		p_game->player.pos.y += (p_game->player.dir.y * MOVE_SPEED);
	else if (p_game->key.move_backward == PRESS/* && is_wall() == FALSE)*/)
		p_game->player.pos.y -= (p_game->player.dir.y * MOVE_SPEED);
	else if (p_game->key.move_left == PRESS/* && is_wall() == FALSE)*/)
		p_game->player.pos.x -= (p_game->player.view.x * MOVE_SPEED);
	else if (p_game->key.move_right == PRESS/* && is_wall() == FALSE)*/)
		p_game->player.pos.x += (p_game->player.view.x * MOVE_SPEED);
	else
		is_update = FALSE;
	
	return (is_update);
}

//int	turn_player(t_game_info *p_game)
//{
//	int	is_update;

//	is_update = TRUE;
	//if (p_game->key.turn_right == PRESS)
	//{
	//		p_game->player.dir.x = \
	//			p_game->player.dir.x * cos(TURN_SPEED) - p_game->player.dir.y * sin(TURN_SPEED);
	//		p_game->player.dir.y = \
	//			p_game->player.dir.x * sin(TURN_SPEED) + p_game->player.dir.y * cos(TURN_SPEED);
	//		p_game->player.view.x = \
	//			p_game->player.view.x * cos(TURN_SPEED) - p_game->player.view.y * sin(TURN_SPEED);
	//		p_game->player.view.y = \
	//			p_game->player.view.x * sin(TURN_SPEED) + p_game->player.view.y * cos(TURN_SPEED);
	//}
	//if (p_game->key.turn_right == PRESS)
	//{
	//		p_game->player.dir.x = \
	//			p_game->player.dir.x * cos(TURN_SPEED) - p_game->player.dir.y * sin(TURN_SPEED);
	//		p_game->player.dir.y = \
	//			p_game->player.dir.x * sin(TURN_SPEED) + p_game->player.dir.y * cos(TURN_SPEED);
	//		p_game->player.view.x = \
	//			p_game->player.view.x * cos(TURN_SPEED) - p_game->player.view.y * sin(TURN_SPEED);
	//		p_game->player.view.y = \
	//			p_game->player.view.x * sin(TURN_SPEED) + p_game->player.view.y * cos(TURN_SPEED);
	//}
//	return (is_update);
//}

int	update_player(t_game_info *p_game)
{
	int	is_update;

	is_update = FALSE;
	is_update = move_player(p_game);
	//is_update = turn_player(p_game);
	return (is_update);
}
