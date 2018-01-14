/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:42:16 by itoth             #+#    #+#             */
/*   Updated: 2017/07/03 19:23:29 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_create_elem(void *data)
{
	t_list *thing;

	thing = malloc(sizeof(t_list));
	thing->content = data;
	thing->next = NULL;
	return (thing);
}
