/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:26:23 by itoth             #+#    #+#             */
/*   Updated: 2017/07/03 19:13:54 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new_one;

	new_one = ft_list_create_elem(data);
	if (*begin_list == NULL)
		*begin_list = new_one;
	else
		ft_list_find_end(*begin_list)->next = new_one;
}
