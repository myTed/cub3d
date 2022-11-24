/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:33:43 by yehan             #+#    #+#             */
/*   Updated: 2022/11/24 19:30:59 by kyolee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "parse_bonus.h"
#include "mlx.h"

int	set_pixel(
		t_img *p_img,
		int y,
		int x,
		t_color color
	)
{
	if (p_img == 0)
		return (FAIL);
	*(p_img->p_data + (y * (p_img->size_line / (p_img->bpp / 8))) + x)
		= *(unsigned int *)&color;
	return (SUCCESS);
}

t_color	get_pixel(
			t_img *p_img,
			const int x,
			const int y
		)
{
	int	rgb;

	rgb = *(p_img->p_data + (y * (p_img->size_line / (p_img->bpp / 8))) + x);
	return (*(t_color *)&rgb);
}

int	draw_screen(
		t_game_info *p_game
	)
{
	if (p_game == 0)
		return (FAIL);
	mlx_put_image_to_window(p_game->mlx.mlx_ptr,
		p_game->mlx.win_ptr, p_game->mlx.screen.img_ptr, 0, 0);
	return (SUCCESS);
}

void	destory_mlx_info(
			t_mlx_info *p_mlx
		)
{
	if (p_mlx->mlx_ptr != 0 && p_mlx->win_ptr != 0)
	{
		if (p_mlx->north_img.img_ptr != 0)
			mlx_destroy_image(p_mlx->mlx_ptr, p_mlx->north_img.img_ptr);
		if (p_mlx->south_img.img_ptr != 0)
			mlx_destroy_image(p_mlx->mlx_ptr, p_mlx->south_img.img_ptr);
		if (p_mlx->west_img.img_ptr != 0)
			mlx_destroy_image(p_mlx->mlx_ptr, p_mlx->west_img.img_ptr);
		if (p_mlx->east_img.img_ptr != 0)
			mlx_destroy_image(p_mlx->mlx_ptr, p_mlx->east_img.img_ptr);
		if (p_mlx->screen.img_ptr != 0)
			mlx_destroy_image(p_mlx->mlx_ptr, p_mlx->screen.img_ptr);
		mlx_destroy_window(p_mlx->mlx_ptr, p_mlx->win_ptr);
	}
}
