#include "../libft/libft.h"
#include "mlx.h"
#include "cub3d.h"
#include "raycast.h"
#include <stdio.h>

int		init_parse_and_player_info(t_game_info *p_game, char *file_name);
int		init_mlx_info(t_mlx_info *p_mlx, t_img *p_screen, t_parse_info *p_parse);
void	init_key_info(t_key_info *p_key);

int	init_game_info(t_game_info *p_game, char *file_name)
{
	ft_memset(p_game, 0, sizeof(t_game_info));	
	if (init_parse_and_player_info(p_game, file_name) == FAIL)
		return (FAIL);
	if (init_mlx_info(&(p_game->mlx), &(p_game->mlx.screen), &(p_game->parse)) == FAIL)
		return (FAIL);
	init_key_info(&(p_game->key));
	return (SUCCESS);
}

int	update_ray_vector(const t_player_info *p_player, int width_idx, t_vector *p_ray);
int	set_correct_wall_distance(t_game_info *p_game, t_wall_info *p_wall, t_vector *p_ray);
int	find_wall_distance(t_game_info *pgi, t_vector *pray, t_hit *phit, t_wall_info *p_wall);
void fill_wall_slice(t_game_info *p_game, const t_vector *p_ray, const t_wall_info *p_wall, const int width_idx);
int	draw_screen(t_game_info *p_game);

#include <unistd.h>
int	update_screen(t_game_info *p_game)
{
	t_vector		ray;
	t_wall_info		wall;
	int				width_idx;

	width_idx = 0;
	while (width_idx < SCREEN_WIDTH)
	{
		if (update_ray_vector(&(p_game->player), width_idx, &ray) < 0)
			return (-1);
		if (find_wall_distance(p_game, &ray, &wall.hit_side, &wall) < 0)
			return (-1);
		if (set_correct_wall_distance(p_game, &wall, &ray) == FAIL)
			return (FAIL);
		fill_wall_slice(p_game, &ray, &wall, width_idx);
		width_idx++;
	}
	if (draw_screen(p_game) < 0)
		return (-1);
	return (0);
}

int	update_player(t_game_info *p_game);

int	game_loop(void *param)
{
	t_game_info		*p_game;
	static int	is_updated = TRUE;

	p_game = param;
	if (is_updated == TRUE)
	{
		update_screen(p_game);
	}
	is_updated = update_player(p_game);
	return (0);
}

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_EXIT					17
int	key_press(int keycode, t_game_info *p_game);
int	key_release(int keycode, t_game_info *p_game);
int	key_exit(t_game_info *game);

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

	mlx_hook(game.mlx.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.mlx.win_ptr, X_EVENT_EXIT, 0, &key_exit, &game);//동작안함
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);	

	return (0);
}
