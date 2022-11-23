/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehan <yehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:11:34 by kyolee            #+#    #+#             */
/*   Updated: 2022/11/23 09:55:59 by yehan            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

/*
 * KEYCODE
 */
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_EXIT		17
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_ESC		53

/*
 * SPEED
 */
# define MOVE_SPEED	0.3
# define TURN_SPEED	0.05

typedef enum e_key_staus
{
	PRESS,
	RELEASE
}   t_key_status;

typedef struct s_key_info
{
	t_key_status	move_forward;
	t_key_status	move_backward;
	t_key_status	move_left;
	t_key_status	move_right;
	t_key_status	turn_left;
	t_key_status	turn_right;
}   t_key_info;

#endif