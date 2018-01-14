/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_there_be_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 21:10:18 by itoth             #+#    #+#             */
/*   Updated: 2017/07/03 21:10:53 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			create_screen(t_environment *env, t_map *map)
{
	env->mlx = mlx_init();
	env->window_width = WINDOW_WIDTH;
	env->window_height = WINDOW_HEIGHT;
	env->window = mlx_new_window(env->mlx
								, env->window_width
								, env->window_height
								, "wolf3d");
	env->map = map;
}

static void			image_1(t_environment *env)
{
	t_image			*image;

	image = &env->image;
	image->mlx_image = mlx_new_image(env->mlx, env->window_width
										, env->window_height);
	image->bits_per_pixel = 0;
	image->line_size = 0;
	image->endian = 0;
	image->data = (int*)mlx_get_data_addr(image->mlx_image
											, &image->bits_per_pixel
											, &image->line_size
											, &image->endian);
}

void				rotation(t_environment *env, double angle)
{
	env->camera.direction += angle;
	normalize_angle(&env->camera.direction);
	draw(env);
}

void				let_the_fun_begin(t_map *map)
{
	t_environment	env;

	setup_camera(&env.camera, map);
	create_screen(&env, map);
	image_1(&env);
	mlx_expose_hook(env.window, expose_hook, &env);
	mlx_hook(env.window, 2, 3, key_hook, &env);
	mlx_loop(env.mlx);
}
