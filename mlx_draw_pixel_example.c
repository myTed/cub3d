#include "mlx.h"
#include <stdlib.h>
#include <string.h>

#define	SCREEN_HEIGHTS	1000
#define SCREEN_WIDTHS	1000

typedef struct s_color
{
	unsigned int	blue:8;
	unsigned int	green:8;
	unsigned int	red:8;
	unsigned int	padd:8;
}	t_color;

typedef struct s_img
{
	unsigned int	*addr;
	int				bpp;
	int				size_line;
	int				endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}	t_mlx;

int	init_mlx_lib(t_mlx *pmin, t_img *pimg)
{
	if (pmin == 0)
		return (-1);
	pmin->mlx_ptr = mlx_init();
	if (pmin->mlx_ptr == 0)
		return (-1);
	pmin->win_ptr = mlx_new_window(pmin->mlx_ptr, SCREEN_WIDTHS,
			SCREEN_HEIGHTS, "FDF");
	if (pmin->win_ptr == 0)
		return (-1);
	pmin->img_ptr = mlx_new_image(pmin->mlx_ptr, SCREEN_WIDTHS,
			SCREEN_HEIGHTS);
	if (pmin->img_ptr == 0)
	{
		mlx_destroy_window(pmin->mlx_ptr, pmin->win_ptr);
		return (-1);
	}
	pimg->addr = (unsigned int *)mlx_get_data_addr(pmin->img_ptr, &pimg->bpp,
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

int	draw_square(t_img *p_img, int start_x, int start_y, int width, int height, t_color color)
{
	int	x_idx;
	int	y_idx;

	x_idx = 0;
	y_idx = 0;
	while (y_idx < height)
	{
		x_idx = 0;
		while (x_idx < width)
		{
			set_pixel(p_img, start_y + y_idx, start_x + x_idx, color);
			x_idx++;
		}
		y_idx++;
	}
	return (0);
}

int	main(void)
{
	t_mlx		mlx;
	t_img		img;
	t_color		color;


	if (init_mlx_lib(&mlx, &img) < 0)
		exit(1);
	memset(&color, 0, sizeof(t_color));
	color.green = 255;
	color.red = 255;

	draw_square(&img, 100, 100, 200, 200, color);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
