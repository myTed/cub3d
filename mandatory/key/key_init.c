#include "../../include/cub3d.h"

void	init_key_info(t_key_info *p_key)
{
	p_key->move_forward = RELEASE;
	p_key->move_backward = RELEASE;
	p_key->move_left = RELEASE;
	p_key->move_right = RELEASE;
	p_key->turn_left = RELEASE;
	p_key->turn_right = RELEASE;
}
