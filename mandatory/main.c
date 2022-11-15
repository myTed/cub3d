#include "cub3d.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "../libft/libft.h"

/*
void   ft_assert(
		void *p,
		const char *file,
		unsigned int line,
		const char *func
){
    if (p == 0)
    {
        printf("%s : %s : %d\n", file, func, line);
        exit(1);
    }
}
*/

int world_map[10][10]=
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,3,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};


int	set_pixel(t_img *pimg, int y, int x, t_color color);
int	update_ray_vector(const t_player_info *p_player, int width_idx, t_vector *p_ray);
void set_correct_wall_distance(t_game_info *p_game, t_wall_info *p_wall, t_vector *p_ray);
int	init_mlx_lib(t_mlx *pmin, t_img *pimg);
int	find_wall_distance(
		t_game_info *pgi,
		t_vector *pray,
		t_hit *phit,
		t_wall_info *p_wall
);

int	fill_wall_slice_pixel(t_img *p_img, int width_idx, int height)
{
	int	y_idx;
	t_color	color;

	if (p_img == 0)
		return (-1);
	y_idx = 0;
	color.green = 255;
	while (y_idx < height)
	{
		set_pixel(p_img, y_idx, width_idx, color);
		y_idx++;
	}
	return (0);
}

int	draw_screen(t_game_info *p_game)
{
	if (p_game == 0)
		return (-1);
	mlx_put_image_to_window(p_game->mlx.mlx_ptr,
		p_game->mlx.win_ptr, p_game->mlx.img_ptr, 0, 0);
	return (0);
}

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
		fill_wall_slice_pixel(p_game->mlx.img_ptr, width_idx, wall.corrected_distance);
		width_idx++;
	}
	if (draw_screen(p_game) < 0)
		return (-1);
	return (0);
}


int	init_parse_info(t_parse_info *p_parse)
{
	t_color floor;
	t_color	ceiling;

	if (p_parse == 0)
		return (-1);
	ft_memset(p_parse, 0, sizeof(t_parse_info));
	ft_memset(&floor, 0, sizeof(t_color));
	ft_memset(&ceiling, 0, sizeof(t_color));
	floor.blue = 100;
	ceiling.green = 100;
	p_parse->floor = floor;
	p_parse->ceiling = ceiling;
	p_parse->map = (int **)world_map;
	return (0);
}

int	init_player_info(t_player_info *p_player)
{
	if (p_player == 0)
		return (-1);
	p_player->dir.x = 0;
	p_player->dir.y = -1;
	p_player->pos.x = 5;
	p_player->pos.y = 5;
	p_player->view.x = 0.66;
	p_player->view.y = 0;
	return (0);
}

int main()
{
	t_game_info	game;

	if (init_parse_info(&game.parse) < 0)
		return (1);
	if (init_player_info(&game.player) < 0)
		return (1);
	if (init_mlx_lib(&game.mlx, &game.img) < 0)
		return (1);
	mlx_loop_hook(game.mlx.mlx_ptr, game_loop, &game);
	mlx_loop(game.mlx.mlx_ptr);	
	return (0);
}
