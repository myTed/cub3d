#include "cube.h"
#include <math.h>

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

int	fill_img_pixel(t_img *p_img, t_color *(*buff)[SCREEN_HEIGHT])
{
	int	x_idx;
	int	y_idx;

	if ((pimg == 0) || (buff == 0))
		return (-1);
	x_idx = 0;
	y_idx = 0;
	while (y_idx < SCREEN_HEIGHT)
	{
		x_idx = 0;
		while (x_idx < SCREEN_WIDTH)
		{
			set_pixel(p_img, y_idx, x_idx, buff[y_idx][x_idx]);
			x_idx++;
		}
		y_idx++;
	}
	return (0);
}


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
}

int	draw_screen(t_game_info *p_game, void *buff)
{
	if ((p_game == 0) || (buff == 0))
		return (-1);
	if (fill_img_pixel(p_game->mlx.img, buff) < 0)
		return (-1);
	mlx_put_image(p_game->mlx.mlx_ptr,
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
		if (find_wall_distance(p_game, &ray, &wall.hit_side) < 0)
			return (-1);
		wall.corrected_distance = corrected_wall_distance(p_game, &wall, &ray);
		
		width_idx++;
	}
	if (draw_screen(p_game, buff) < 0)
		return (-1);
	return (0);
}


int main()
{
	t_game_info	game;
	/*
	init_map_info();
	parse_map();
	mlx_key_hook();
	*/
	if (init_mlx_lib(&game.mlx, &game.img) < 0)
		return (1);
	mlx_loop_hook(mlx.mlx_ptr, game_loop, &game);
	mlx_loop(mlx.mlx_ptr);	
	return (0);
}
