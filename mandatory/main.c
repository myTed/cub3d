#include "cub3d.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include "../libft/libft.h"

int	parsing_file(t_game_info *p_game, char *file_name);
int	init_mlx_info(t_mlx *p_mlx, t_img *p_screen, t_parse_info *p_parse);

int	init_game_info(t_game_info *p_game, char *file_name)
{
	ft_memset(p_game, 0, sizeof(t_game_info));	
	if (parsing_file(p_game, file_name) == FAIL)
		return (FAIL);
	//if (init_mlx_info(&(p_game->mlx), &(p_game->mlx.screen), &(p_game->parse)) < FAIL)
	//	return (FAIL);
	return (SUCCESS);
}

int	update_ray_vector(const t_player_info *p_player, int width_idx, t_vector *p_ray);
void set_correct_wall_distance(t_game_info *p_game, t_wall_info *p_wall, t_vector *p_ray);
int	find_wall_distance(t_game_info *pgi, t_vector *pray, t_hit *phit, t_wall_info *p_wall);
void fill_wall_slice(t_game_info *p_game, const t_vector *p_ray, const t_wall_info *p_wall, const int width_idx);
int	draw_screen(t_game_info *p_game);

int	game_loop(void *param)
{
	t_game_info 	*p_game;
	t_vector		ray;
	t_wall_info		wall;
	int				width_idx;

	p_game = param;
	width_idx = 0;
	while (width_idx < SCREEN_WIDTH)
	{
		if (update_ray_vector(&(p_game->player), width_idx, &ray) < 0)
			return (-1);
		if (find_wall_distance(p_game, &ray, &wall.hit_side, &wall) < 0)
			return (-1);
		set_correct_wall_distance(p_game, &wall, &ray);
		fill_wall_slice(p_game, &ray, &wall, width_idx);
		width_idx++;
	}
	if (draw_screen(p_game) < 0)
		return (-1);
	return (0);
}

int main(int argc, char *argv[])
{
	t_game_info	game;

	if (argc != 2)
	{
		printf("Error\n: ./cub3D *.cub");
		return (FAIL);
	}

	if (init_game_info(&game, argv[1]) == FAIL)
		return (FAIL);

	//key_hook
	//mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	//game_loop(&game);
	//mlx_loop(game.mlx.mlx_ptr);	
	return (0);
}
