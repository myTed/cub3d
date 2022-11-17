#include <mlx.h>
#include "../include/cub3d.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int	init_mlx_lib(t_mlx *p_mlx, t_img *p_img)
{
	if (p_mlx == 0)
		return (-1);
	p_mlx->mlx_ptr = mlx_init();
	if (p_mlx->mlx_ptr == 0)
		return (-1);
	p_mlx->win_ptr = mlx_new_window(p_mlx->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, "cub3D");
	if (p_mlx->win_ptr == 0)
		return (-1);
	p_mlx->screen.img_ptr = mlx_new_image(p_mlx->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	if (p_mlx->screen.img_ptr == 0)
	{
		mlx_destroy_window(p_mlx->mlx_ptr, p_mlx->win_ptr);
		return (-1);
	}
	p_img->addr = (unsigned int *)mlx_get_data_addr(p_mlx->screen.img_ptr, &pimg->bpp,
			&pimg->size_line, &pimg->endian);
	if (pimg->addr == 0)
	{
		mlx_destroy_window(p_mlx->mlx_ptr, p_mlx->win_ptr);
		return (-1);
	}
	return (0);
}

int	set_pixel(t_img *pimg, int y, int x, t_color color)
{
	if (pimg == 0)
		return (-1);
	*(pimg->addr + (y * (pimg->size_line / (pimg->bpp / 8))) + x)
		= *(unsigned int *)&color;
	return (0);
}
