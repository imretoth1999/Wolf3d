/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 20:47:11 by itoth             #+#    #+#             */
/*   Updated: 2017/07/03 20:49:58 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			validate_int(char *string, int number)
{
	if (!ft_is_valid_int(string)
		|| !(number == 0 || number == 1 || number == 2))
	{
		ft_putstr("Se gasesc caractere neadmise.\n");
		exit(1);
	}
}

static int			do_line(int fd, int **ints, int *width)
{
	char	*line;
	int		read_ret;
	char	**split;
	int		i;

	read_ret = get_next_line(fd, &line);
	if (read_ret == -1)
		ft_putendl_fd("Eroare in timpul citirii", 1);
	if (read_ret > 0)
	{
		split = ft_strsplit(line, ' ');
		*width = ft_arrlen(split);
		*ints = malloc(*width * sizeof(int));
		i = 0;
		while (i < *width)
		{
			(*ints)[i] = ft_atoi(split[i]);
			validate_int(split[i], (*ints)[i]);
			i++;
		}
		ft_strsplit_free(split);
	}
	free(line);
	return (read_ret);
}

static void			process_rest(int fd, t_list **int_list
								, int expect_width
								, int *height)
{
	int			*curr_ints;
	int			width;

	while (do_line(fd, &curr_ints, &width))
	{
		if (width != expect_width)
			ft_putendl_exit("Liniile nu au aceasi marime", 1);
		ft_list_push_back(int_list, curr_ints);
		(*height)++;
	}
}

static void			list_to_map(t_list **ints_list, t_map *map)
{
	int				i;
	t_list			*current_ints;

	map->data = malloc(map->height * sizeof(int*));
	current_ints = *ints_list;
	i = 0;
	while (current_ints)
	{
		map->data[i] = current_ints->content;
		i++;
		current_ints = current_ints->next;
	}
}

void				read_map(t_map *map, char *filename)
{
	int			fd;
	int			*curr_ints;
	t_list		*ints_list;

	fd = open(filename, O_RDONLY);
	do_line(fd, &curr_ints, &map->width);
	if (map->width <= 0)
		ft_putendl_exit("Marime nula", 1);
	ints_list = NULL;
	ft_list_push_back(&ints_list, curr_ints);
	map->height = 1;
	process_rest(fd, &ints_list, map->width, &map->height);
	if (map->width <= 1 || map->height <= 1)
		ft_putendl_exit("Harta prea mica", 1);
	list_to_map(&ints_list, map);
	close(fd);
}
