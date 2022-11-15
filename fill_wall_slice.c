#include "cube.h"

static int get_texture_offset_x(const t_wall_info *p_wall, const t_vector *p_ray)
{
	double map_offset_x;
	double wall_offset_x;

	//1. map 상에서 어디인지
	if (p_wall->hit_side == WALL_VERTICAL)
		map_offset_x = p_wall->pos.y + (p_wall->corrected_distance - p_ray->y);
	else /* (hit_side == WALL_HORIZON) */
		map_offset_x = p_wall->pos.x + (p_wall->corrected_distance - p_ray->x);

	//2. wall 상에서 어디인지
	if (p_wall->hit_side < WALL_VERTICAL && p_ray->x > 0 || \
		p_wall->hit_side < WALL_HORIZON && p_ray->y < 0)
			wall_offset_x = map_offset_x - floor(map_offset_x);
	else /* 보정 */
			wall_offset_x = 1 - (map_offset_x - floor(map_offset_x));

	//3. texture 상에서 어디인지
	return ((int)(wall_offset_x * (double)TEXTURE_WIDTH));
}		

static double get_texture_offset_y(t_slice_info *p_slice)
{
	if (p_slice->draw_top < 0)
		return (-(p_slice->draw_top) * p_slice->texture_step_y);
	else
		return (0);
}

static t_hit get_texture_kind(t_wall_info *p_wall, t_vector *p_ray)
{
	if (p_wall->hit_side == WALL_VERTICAL)
	{
		if (p_ray->x > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (p_ray->y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

void fill_slice_info(t_slice_info *p_slice, const t_wall_info *p_wall, const t_vector *p_ray)
{
	double draw_height;

	draw_height = SCREEN_HEIGHT / p_wall->corrected_distance;
	
	//texture_offset_x
	p_slice->texture_offset_x = get_texture_offset_x(p_wall, p_ray);
	
	//texture_step_y
	p_slice->texture_step_y = TEXTURE_HEIGHT / draw_height;
	
	//draw_top
	p_slice->draw_top = (SCREEN_HEIGHT / 2) - (draw_height / 2);
	
	//texture_offset_y
	p_slice->texture_offset_y = get_texture_offset_y(p_slice);
	if (p_slice->draw_top < 0)
		p_slice->draw_top = 0;

	//draw_bottom
	p_slice->draw_bottom = (SCREEN_HEIGHT / 2) + (draw_height / 2);

	//동서남북
	p_slice->texture_kind = get_texture_kind(p_wall, p_ray);
}

//--------------------------------------------------//

void fill_buffer_x(t_img *p_img, const t_slice_info *p_slice, const t_parse_info *p_parse, const int width_idx)
{
	int hieght_idx;
	int draw_top;
	int draw_bottom;
	double texture_offset_x;
	double texture_offset_y;

	draw_top = p_slice->draw_top;
	draw_bottom = p_slice->draw_bottom;
	texture_offset_x = p_slice->texture_offset_x;
	texture_offset_y = p_slice->texture_offset_y;

	hieght_idx = 0;
	while (hieght_idx < draw_top - 1)
	{
		set_pixel(p_img, hieght_idx, width_idx, p_parse->ceiling);
		hieght_idx++;
	}
	while (hieght_idx < draw_bottom)
	{
		set_pixel(p_img, hieght_idx, width_idx, 0xFF0000);
		/*get_pixel((int)texture_offset_x, (int)texture_offset_y)*/
		hieght_idx++;
		texture_offset_y + p_slice->texture_step_y;
	}
	while (hieght_idx > SCREEN_HEIGHT)
	{
		set_pixel(p_img, hieght_idx, width_idx, p_parse->floor);
		hieght_idx++;
	}
}

void fill_wall_slice(t_img *p_img, const t_vector *p_ray, const t_wall_info *p_wall, const t_parse_info *p_parse, const int width_idx)
{
	t_slice_info slice;

	fill_slice_info(&slice, p_wall, p_ray);
	fill_buffer_x(p_img, &slice, p_parse, width_idx);
}