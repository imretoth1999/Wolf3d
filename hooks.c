/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 20:37:25 by itoth             #+#    #+#             */
/*   Updated: 2017/07/03 20:46:30 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			key_pressed(int keycode, t_environment *env)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_UP_ARROW)
		move_camera(env->camera.direction, env);
	else if (keycode == KEY_A || keycode == KEY_LEFT_ARROW)
		move_camera(env->camera.direction + M_PI_2, env);
	else if (keycode == KEY_S || keycode == KEY_DOWN_ARROW)
		move_camera(env->camera.direction + M_PI, env);
	else if (keycode == KEY_D || keycode == KEY_RIGHT_ARROW)
		move_camera(env->camera.direction - M_PI_2, env);
	else if (keycode == KEY_PERIOD || keycode == KEY_E)
		rotation(env, -ANGULAR_VELOCITY);
	else if (keycode == KEY_COMMA || keycode == KEY_Q)
		rotation(env, ANGULAR_VELOCITY);
}

int					key_hook(int keycode, t_environment *env)
{
	(void)env;
	key_pressed(keycode, env);
	return (0);
}

int					expose_hook(t_environment *env)
{
	draw(env);
	return (0);
}
