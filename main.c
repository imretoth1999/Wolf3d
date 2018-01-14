/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 20:57:47 by itoth             #+#    #+#             */
/*   Updated: 2017/07/03 21:32:07 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int					main(int argc, char **argv)
{
	t_map			map;

	if (argc != 2)
	{
		ft_putstr("USAGE: ./wolf3d map.wolf\nArrows or WADS to");
		ft_putstr(" move\nQ and E to rotate\n");
		exit(1);
	}
	ft_bzero(&map, sizeof(t_map));
	read_map(&map, argv[1]);
	let_the_fun_begin(&map);
	return (0);
}
