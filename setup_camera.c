/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 20:51:39 by itoth             #+#    #+#             */
/*   Updated: 2017/07/03 20:51:41 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			set_camera_location(t_camera *camera, double x, double y
										, int *found)
{
	if (*found)
	{
		ft_putstr("Prea multe pozitii de inceput");
		exit(1);
	}
	else
	{
		camera->location.x = x;
		camera->location.y = y;
		*found = 1;
	}
}

static void			set_to_zero(int *first, int *second)
{
	*first = 0;
	*second = 0;
}

static void			if_unset_put_in_middle(t_camera *camera, t_map *map
											, int *found)
{
	if (!*found)
	{
		if ((map->width % 2 == 1 && map->height % 2 == 1
				&& map->data[(map->height - 1) / 2][(map->width - 1) / 2])
			|| (map->width % 2 == 1
				&& map->data[(map->height - 1) / 2][(map->width - 1) / 2]
				&& map->data[(map->height - 1) / 2 + 1][(map->width - 1) / 2])
			|| (map->height % 2 == 1
				&& map->data[(map->height - 1) / 2][(map->width - 1) / 2]
				&& map->data[(map->height - 1) / 2][(map->width - 1) / 2 + 1]))
		{
			ft_putstr("Nu se poate crea camera din cauza unui perete buclucas");
			exit(1);
		}
		set_camera_location(camera, ((double)(map->width - 1)) / 2
							, ((double)(map->height - 1)) / 2, found);
	}
}

void				setup_camera(t_camera *camera, t_map *map)
{
	int				x;
	int				y;
	int				found;

	set_to_zero(&found, &y);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->data[y][x] == 2)
			{
				set_camera_location(camera, x, y, &found);
				map->data[y][x] = 0;
			}
			x++;
		}
		y++;
	}
	if_unset_put_in_middle(camera, map, &found);
	camera->direction = M_PI_2;
}
