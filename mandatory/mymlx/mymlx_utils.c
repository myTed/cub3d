#include "../include/cub3d.h"
#include "../include/parse.h"
#include "mlx.h"

int	set_pixel(t_img *p_img, int y, int x, t_color color)
{
	if (p_img == 0)
		return (FAIL);
	*(p_img->p_data + (y * (p_img->size_line / (p_img->bpp / 8))) + x)
		= *(unsigned int *)&color;
	return (0);
}

int	draw_screen(t_game_info *p_game)
{
	if (p_game == 0)
		return (-1);
	mlx_put_image_to_window(p_game->mlx.mlx_ptr,
		p_game->mlx.win_ptr, p_game->mlx.screen.img_ptr, 0, 0);
	return (0);
}
