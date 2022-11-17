#include "cub3d.h"
#include <mlx.h>

int	init_mlx_lib(t_mlx *pmin, t_img *pimg)
{
	if (pmin == 0)
		return (-1);
	pmin->mlx_ptr = mlx_init();
	if (pmin->mlx_ptr == 0)
		return (-1);
	pmin->win_ptr = mlx_new_window(pmin->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, "cub3D");
	if (pmin->win_ptr == 0)
		return (-1);
	pmin->screen.img_ptr = mlx_new_image(pmin->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	if (pmin->screen.img_ptr == 0)
	{
		mlx_destroy_window(pmin->mlx_ptr, pmin->win_ptr);
		return (-1);
	}
	pimg->addr = (unsigned int *)mlx_get_data_addr(pmin->screen.img_ptr, &pimg->bpp,
			&pimg->size_line, &pimg->endian);
	if (pimg->addr == 0)
	{
		mlx_destroy_window(pmin->mlx_ptr, pmin->win_ptr);
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