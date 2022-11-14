#include "cube.h"

typedef struct s_slice
{
	int draw_top;
	int draw_bottom;
	double texture_offset_x;
	double texture_offset_y;
	double texture_step_y;//movement per screen pixel y
} t_slice;

int get_texture_offset_x(t_vector pos, t_vector ray, t_hit hitted_side, double corrected_distance)
{
	double map_offset_x;
	double wall_offset_x;

	//1. map 상에서 어디인지
	if (hitted_side == WALL_VERTICAL)
		map_offset_x = pos.y + (corrected_distance - ray.y);
	else /* (hitted_side == WALL_HORIZON) */
		map_offset_x = pos.x + (corrected_distance - ray.x);

	//2. wall 상에서 어디인지
	if (hitted_side < WALL_VERTICAL && ray.x > 0 || \
		hitted_side < WALL_HORIZON && ray.y < 0)
			wall_offset_x = map_offset_x - floor(map_offset_x);
	else /* 보정 */
			wall_offset_x = 1 - (map_offset_x - floor(map_offset_x));

	//3. texture 상에서 어디인지
return ((int)(wall_offset_x * (double)TEXTURE_WIDTH));
}

static int get_texture_offset_y(int *draw_top, double texture_step_y)
{
	double texture_offset_y;

	if (*draw_top < 0)
	{
		texture_offset_y = -(*draw_top) * texture_step_y;
		*draw_top = 0;
	}
	else
		texture_offset_y = 0;
	return (texture_offset_y);
}

static void fill_slice_info(t_slice *p_slice, double corrected_distance)
{
	double draw_height;

	draw_height = SCREEN_HEIGHT / corrected_distance;
	//1. screen slice
	p_slice->draw_top = (SCREEN_HEIGHT / 2) - (draw_height / 2);
	p_slice->draw_bottom = (SCREEN_HEIGHT / 2) + (draw_height / 2);
	
	//2. texture slice
	p_slice->texture_offset_x = get_texture_offset_x(pos, ray, hitted_side, corrected_distance);
	
	p_slice->texture_step_y = TEXTURE_HEIGHT / draw_height;
	
	p_slice->texture_offset_y = get_texture_offset_y();
	if (p_slice->draw_top < 0)
	{
		p_slice->texture_offset_y = -(p_slice->draw_top) * p_slice->texture_step_y;
		p_slice->draw_top = 0;
	}
	else
		p_slice->texture_offset_y = 0;
}

static void fill_buffer_slice(screen_buffer, &slice_info);


void fill_wall_slice(int **screen_buffer, double corrected_distance, const t_game *p_game_info)
{
	t_slice slice_info;

	fill_slice_info(&slice_info);
	fill_buffer_slice(screen_buffer, &slice_info);
}