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

int init_dist_value(t_dda *p_dda, t_vector *p_vector)
{
    ft_assert(p_dda != 0, __FILE__, __LINE__, __func__);
    ft_assert(p_vector != 0, __FILE__, __LINE__, __func__); 
    
    p_dda->map.x = (int)p_vector->pos.x;
    p_dda->map.y = (int)p_vector->pos.y;
    p_dda->delta_dist_horizon = fabs(1 / (p_vector->ray.y));
    p_dda->delta_dist_vertical = fabs(1 / (p_vector->ray.x));
    p_dda->first_dist_horizon = 
        p_dda->delta_dist_horizon * (p_dda->map.x);
    p_dda->first_dist_vertical =
        p_dda->delta_dist_vertical * (p_dda->map.y);
    if (p_vector->ray.y < 0)
        p_dda->step_horizon = -1;
    else
		p_dda->step_vertical = 1;
	if (p_vector->ray.x < 0)
		p_dda->step_vertical = -1;
	else
		p_dda->step_vertical = 1;
    return (0);
}


int	find_wall(t_vector *p_vector, t_map_info *pmi)
{
    t_dda   dda;
    double  cur_dist_v;
    double  cur_dist_h;
    int		hited;

	ft_assert(p_vector != 0, __FILE__, __LINE__, __func__);
	ft_assert(pmi !=0, __FILE__, __LINE__, __func__);

    init_dist_value(&dda, p_vector);
    cur_dist_v = dda.first_dist_vertical;
    cur_dist_h = dda.first_dist_horizon;
	hited = 0;
	while (hited == 0)
	{
    	if (cur_dist_h < cur_dist_v)
    	{
        	cur_dist_h += dda.delta_dist_horizon;
        	dda.map_pos.y += dda.step_horizon;
			hit_side = horizon;
    	}
    	else
    	{
			cur_dist_v += dda.delta_dist_vertical;
			dda.map_pos.x += dda.step_vertical;
			hit_side = vertical;
    	}
		if (pmi->map[dda.map_pos.y][dda.map_pos.x] == 1)
			hited = 1;
	}
	return (0);
}

double get_revised_wall_distance(t_dda *pd, t_vector *pv)
{
	cube_assert(pd);
	cube_assert(pv);
	if (pd->hit_side == HORIZON)
	{
		if (pv->ray.y < 0)
			return ((pv->map.y - pv->pos.y + 1) / pv->ray.y);
		else
			return ((pv->map.y -pv->pos.y) / pv->ray.y);
	}
	else if (pd->hit_side == VERTICAL)
	{
		if (pv->ray.x < 0)
			return ((pv->map.x - pv->pos.x + 1) / pv->ray.x);
		else
			return ((pv->map.x - pv->pos.x) / pv->ray.x);
	}
	printf("Not comming here!\n");
	exit(1);
}

double get_screen_height(double revised_wall_dist)
{
	return (SCREEN_HEIGHT/revised_wall_dist);
}


void init_map_info(void)
{
	printf("init_map_info\n");
}

void parse_map(void)
{
	printf(parse_map);
}

void	main_loop(void)
{
	
}


int main()
{
	init_map_info();
	parse_map();
	mlx_key_hook();
	mlx_hook(main_loop);
	mlx_loop();
    return (0);
}
