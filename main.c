#include "cube.h"


void   cube_assert(void *p)
{
    if ((char *)p == 0)
    {
        printf("null point Error!\n");
        exit(1);
    }
}

int init_dist_value(t_dda *p_dda, t_vector *p_vector)
{
    cube_assert(p_dda);
    cube_assert(p_vector);    
    
    p_dda->map.x = (int)p_vector->pos.x;
    p_dda->map.y = (int)p_vector->pos.y;
    p_dda->delta_dist_horizon = 1 / (p_vector->ray.y);
    p_dda->delta_dist_vertical = 1 / (p_vector->ray.x);
    p_dda->first_dist_horizon = 
        p_dda->delta_dist_horizon * (p_dda->map.x);
    p_dda->first_dist_vertical =
        p_dda->delta_dist_vertical * (p_dda->map.y);
    
    if (p_vector->ray.y < 0)
        p_dda->step_horizon = -1;
    else

    p_dda->step_vertical = 1;
    return (0);
}


int getWallDistanceFromPos(t_vector *p_vector)
{
    t_dda   dda;
    double  cur_dist_v;
    double  cur_dist_h;
    
    init_dist_value(&dda, p_vector);
    cur_dist_v = dda.first_dist_vertical;
    cur_dist_h = dda.first_dist_horizon;

    if (cur_dist_v < cur_dist_h)
    {
        cur_dist_h += dda.delta_dist_horizon;
        dda.map.x = 
    }
    else
    {

    }
}

int 

int main()
{



    return (0);
}