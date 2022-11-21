#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include "../libft/libft.h"

#define MOVE_SPEED 0.25
#define TURN_SPEED 0.02
#define TRUE 1
#define FALSE 0

#define WALL 1

//int	is_wall(t_game_info *p_game, double delta_x, double delta_y)
//{
//	int	new_x;
//	int	new_y;

//	printf("%s\n", (char *)p_game->parse.map.data[0]);

//	new_x = (int)(p_game->player.pos.x + delta_x);
//	new_y = (int)(p_game->player.pos.y + delta_y);
//	if (p_game->parse.map.data[new_y][new_x] == WALL)
//		return (TRUE);
//	else
//		return (FALSE);
//}

int	is_wall(t_game_info *p_game, double new_pos_y, double new_pos_x)
{
	int	(*p_map)[MAP_SIZE_X];

	p_map = (int(*)[MAP_SIZE_X])(p_game->parse.map);
	return (p_map[(int)(new_pos_y)][(int)(new_pos_x)] != 0);
}

int	update_pos(t_game_info *p_game, t_vector *p_cur_pos, t_vector *p_new_pos)
{
	if (p_game->key.move_forward == PRESS)
	{
		p_new_pos->y = p_cur_pos->y + (p_game->player.dir.y * MOVE_SPEED);
		p_new_pos->x = p_cur_pos->x + (p_game->player.dir.x * MOVE_SPEED);
		p_game->key.move_forward = RELEASE;
	}
	else if (p_game->key.move_backward == PRESS)
	{
		p_new_pos->y = p_cur_pos->y - (p_game->player.dir.y * MOVE_SPEED);
		p_new_pos->x = p_cur_pos->x - (p_game->player.dir.x * MOVE_SPEED);
		p_game->key.move_backward = RELEASE;
	}
	else if (p_game->key.move_right == PRESS)
	{
		p_new_pos->y = p_cur_pos->y + (p_game->player.view.y * MOVE_SPEED);
		p_new_pos->x = p_cur_pos->x + (p_game->player.view.x * MOVE_SPEED);
		p_game->key.move_right = RELEASE;
	}
	else if (p_game->key.move_left == PRESS)
	{
		p_new_pos->y = p_cur_pos->y - (p_game->player.view.y * MOVE_SPEED);
		p_new_pos->x = p_cur_pos->x - (p_game->player.view.x * MOVE_SPEED);
		p_game->key.move_left = RELEASE;
	}
	else
		return (FALSE);
	return (TRUE);
}

int	corrected_pos(t_game_info *p_game, t_vector *p_new_pos)
{
	t_vector	cur_pos;

	cur_pos.x = p_game->player.pos.x;
	cur_pos.y = p_game->player.pos.y;
	if ((double)(p_new_pos->x) - (double)((int)(p_new_pos->x)) < 0.0001)
	{
		printf("==============================\n");
		printf("보정 전 거리 x: %lf\n", p_new_pos->x);
		if (p_new_pos->x - cur_pos.x > 0)
			p_new_pos->x += 0.1;
		else
			p_new_pos->x -= 0.1;
		printf("보정 거리 x: %lf\n", p_new_pos->x);
	}
	if ((double)(p_new_pos->y) - (double)((int)(p_new_pos->y)) < 0.0001)
	{
		printf("=====================================\n");
		printf("보정 전 거리 y: %lf\n", p_new_pos->y);
		if (p_new_pos->y - cur_pos.y > 0)
			p_new_pos->y += 0.1;
		else
			p_new_pos->y -= 0.1;
		printf("보정 거리 y: %lf\n", p_new_pos->y);
	}
	if (p_new_pos->x < 1.5)
		p_new_pos->x = 1.5;
	if (p_new_pos->x > MAP_SIZE_X - 1.5)
		p_new_pos->x = MAP_SIZE_X - 1.5;
	if (p_new_pos->y < 1.5)
		p_new_pos->y = 1.5;
	if (p_new_pos->y > MAP_SIZE_Y - 1.5)
		p_new_pos->y = MAP_SIZE_Y - 1.5;
	printf("player (y,x) (%lf, %lf)    dir(y,x) (%lf, %lf)\n", p_new_pos->y, p_new_pos->x, p_game->player.dir.y, p_game->player.dir.x);
	return (0);
}

int	move_player(t_game_info *p_game)
{
	t_vector	new_pos;
	t_vector	cur_pos;
	int			is_update;

	cur_pos.x = p_game->player.pos.x;
	cur_pos.y = p_game->player.pos.y;
	is_update = FALSE;
	if (update_pos(p_game, &cur_pos, &new_pos) == FALSE)
		return (is_update);
	corrected_pos(p_game, &new_pos);
	is_update = TRUE;
	
	if (!is_wall(p_game, new_pos.y, new_pos.x))
	{	
		p_game->player.pos.x = new_pos.x;
		p_game->player.pos.y = new_pos.y;
	}
	else if (!is_wall(p_game, new_pos.y, cur_pos.x))
	{
		p_game->player.pos.x = cur_pos.x;
		p_game->player.pos.y = new_pos.y;
	}
	else
	{	
		p_game->player.pos.x = new_pos.x;
		p_game->player.pos.y = cur_pos.y;
	}
	return (is_update);
}


/*
int	move_player(t_game_info *p_game)
{
	int	is_update;

	is_update = TRUE;
	
	if (p_game->key.move_forward == PRESS
		is_wall(p_game, 0, p_game->player.dir.y * MOVE_SPEED) == FALSE)
	{
			p_game->player.pos.y += (p_game->player.dir.y * MOVE_SPEED);
			p_game->key.move_forward = RELEASE;
	}
	else if (p_game->key.move_backward == PRESS && is_wall() == FALSE)
	{
		p_game->player.pos.y -= (p_game->player.dir.y * MOVE_SPEED);
			p_game->key.move_backward = RELEASE;
	}
	else if (p_game->key.move_left == PRESS && is_wall() == FALSE)
	{
		p_game->player.pos.x -= (p_game->player.view.x * MOVE_SPEED);
			p_game->key.move_left = RELEASE;

	}
	else if (p_game->key.move_right == PRESS && is_wall() == FALSE/)
	{
		p_game->player.pos.x += (p_game->player.view.x * MOVE_SPEED);
			p_game->key.move_right = RELEASE;
	}
	else
		is_update = FALSE;
	
	return (is_update);
}
*/
int	turn_player(t_game_info *p_game)
{
	int			is_update;
	t_vector	old_dir;
	t_vector	old_view;

	is_update = TRUE;
	ft_memcpy(&old_dir, &(p_game->player.dir), sizeof(t_vector));
	ft_memcpy(&old_view, &(p_game->player.view), sizeof(t_vector));
	if (p_game->key.turn_right == PRESS)
	{
		p_game->player.dir.x = \
			old_dir.x * cos(TURN_SPEED) - old_dir.y * sin(TURN_SPEED);
		p_game->player.dir.y = \
			old_dir.x * sin(TURN_SPEED) + old_dir.y * cos(TURN_SPEED);
		p_game->player.view.x = \
			old_view.x * cos(TURN_SPEED) - old_view.y * sin(TURN_SPEED);
		p_game->player.view.y = \
			old_view.x * sin(TURN_SPEED) + old_view.y * cos(TURN_SPEED);
		p_game->key.turn_right = RELEASE;
	}
	else if (p_game->key.turn_left == PRESS)
	{
		p_game->player.dir.x = \
			old_dir.x * cos(-TURN_SPEED) - old_dir.y * sin(-TURN_SPEED);
		p_game->player.dir.y = \
			old_dir.x * sin(-TURN_SPEED) + old_dir.y * cos(-TURN_SPEED);
		p_game->player.view.x = \
			old_view.x * cos(-TURN_SPEED) - old_view.y * sin(-TURN_SPEED);
		p_game->player.view.y = \
			old_view.x * sin(-TURN_SPEED) + old_view.y * cos(-TURN_SPEED);
		p_game->key.turn_left = RELEASE;
	}
	else
		is_update = FALSE;
	return (is_update);
}

int	update_player(t_game_info *p_game)
{
	int	is_update;

	is_update = FALSE;
	is_update = move_player(p_game);
	is_update |= turn_player(p_game);
	return (is_update);
}
