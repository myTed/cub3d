/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:53:08 by kyolee            #+#    #+#             */
/*   Updated: 2022/11/24 21:49:01 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_key_info(t_key_info *p_key)
{
	p_key->move_forward = RELEASE;
	p_key->move_backward = RELEASE;
	p_key->move_left = RELEASE;
	p_key->move_right = RELEASE;
	p_key->turn_left = RELEASE;
	p_key->turn_right = RELEASE;
}
