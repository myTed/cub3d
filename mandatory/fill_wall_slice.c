#include "cub3d.h"
#include <math.h>

int	set_pixel(t_img *pimg, int y, int x, t_color color);

static t_img *get_texture(t_game_info *p_game, const t_wall_info *p_wall, const t_vector *p_ray)
{
	if (p_wall->hit_side == VERTICAL)
	{
		if (p_ray->x > 0)
			return (&(p_game->parse.east_img));
		else
			return (&(p_game->parse.west_img));
	}
	else
	{
		if (p_ray->y > 0)
			return (&(p_game->parse.south_img));
		else
			return (&(p_game->parse.north_img));
	}
}

static int get_texture_offset_x(const t_slice_info *p_slice, const t_wall_info *p_wall, const t_vector *p_ray)
{
	double map_offset_x;
	double wall_offset_x;

	//1. map 상에서 어디인지
	if (p_wall->hit_side == VERTICAL)
		map_offset_x = p_wall->pos.y + (p_wall->corrected_distance * p_ray->y);
	else /* (hit_side == WALL_HORIZON) */
		map_offset_x = p_wall->pos.x + (p_wall->corrected_distance * p_ray->x);

	//2. wall 상에서 어디인지
	if ((p_wall->hit_side == VERTICAL && p_ray->x > 0) || \
		(p_wall->hit_side == HORIZON && p_ray->y < 0))
			wall_offset_x = map_offset_x - floor(map_offset_x);
	else /* 보정 */
			wall_offset_x = 1 - (map_offset_x - floor(map_offset_x));

	//3. texture 상에서 어디인지
	return ((int)(wall_offset_x * (double)(p_slice->p_texture_img->width)));
}

static double get_texture_offset_y(t_slice_info *p_slice)
{
	if (p_slice->draw_top < 0)
		return (-(p_slice->draw_top) * p_slice->texture_step_y);
	else
		return (0);
}

void fill_slice_info(t_game_info *p_game, t_slice_info *p_slice, const t_wall_info *p_wall, const t_vector *p_ray)
{
	double draw_height;

	draw_height = SCREEN_HEIGHT / p_wall->corrected_distance;
	
	//동서남북
	p_slice->p_texture_img = get_texture(p_game, p_wall, p_ray);
	
	//texture_offset_x
	p_slice->texture_offset_x = get_texture_offset_x(p_slice, p_wall, p_ray);
	
	//texture_step_y
	p_slice->texture_step_y = p_slice->p_texture_img->height / draw_height;
	
	//draw_top
	p_slice->draw_top = (SCREEN_HEIGHT / 2) - (draw_height / 2);
	
	//texture_offset_y
	p_slice->texture_offset_y = get_texture_offset_y(p_slice);
	if (p_slice->draw_top < 0)
		p_slice->draw_top = 0;

	//draw_bottom
	p_slice->draw_bottom = (SCREEN_HEIGHT / 2) + (draw_height / 2);

}

//--------------------------------------------------//

t_color get_pixel(t_img *p_img, const int x, const int y)
{
	int rgb;

	rgb = *(p_img->p_data + (y * (p_img->size_line / (p_img->bpp / 8))) + x);
	return (*(t_color *)&rgb);

}

void fill_buffer_x(t_game_info *p_game, t_slice_info *p_slice, const int width_idx)
{
	int hieght_idx;
	t_color texture;

	hieght_idx = 0;
	while (hieght_idx < p_slice->draw_top - 1)
	{
		set_pixel(&p_game->mlx.screen, hieght_idx, width_idx, p_game->parse.ceiling);
		hieght_idx++;
	}
	
	while (hieght_idx < p_slice->draw_bottom)
	{
		texture = get_pixel(p_slice->p_texture_img, (int)p_slice->texture_offset_x, (int)p_slice->texture_offset_y);
		set_pixel(&p_game->mlx.screen, hieght_idx, width_idx, texture);
		hieght_idx++;
		p_slice->texture_offset_y = p_slice->texture_offset_y + p_slice->texture_step_y;
	}
	
	while (hieght_idx < SCREEN_HEIGHT)
	{
		set_pixel(&p_game->mlx.screen, hieght_idx, width_idx, p_game->parse.floor);
		hieght_idx++;
	}
}
//#include <stdio.h>
void fill_wall_slice(t_game_info *p_game, const t_vector *p_ray, const t_wall_info *p_wall, const int width_idx)
{
	t_slice_info slice;

	fill_slice_info(p_game, &slice, p_wall, p_ray);
	//printf("width idx: %d, texture offset x: %d\n", width_idx, (int)slice.texture_offset_x);
	fill_buffer_x(p_game, &slice, width_idx);
}
