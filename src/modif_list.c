/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:47:58 by lbaudran          #+#    #+#             */
/*   Updated: 2016/09/06 13:58:47 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_list		*create_list(t_list *begin)
{
	begin = (t_list *)malloc(1 * sizeof(t_list));
	begin->prev = NULL;
	begin->next = NULL;
	begin->down = NULL;
	begin->up = NULL;
	begin->x = 0;
	begin->y = 0;
	return (begin);
}

t_list		*create_elem(t_list *begin)
{
	t_list	*elem;

	elem = begin;
	while (elem->next)
		elem = elem->next;
	elem->next = (t_list *)malloc(1 * sizeof(t_list));
	elem->next->x = 0;
	elem->next->y = 0;
	elem->next->prev = elem;
	elem->next->next = NULL;
	elem->next->down = NULL;
	elem->next->up = NULL;
	return (elem->next);
}

t_list		*add_point(t_list *begin)
{
	t_list	*elem;
	t_list	*tmp;

	elem = begin;
	while (elem)
	{
		tmp = elem;
		while (tmp && (tmp->y != (elem->y) + 1 && tmp->x != elem->x))
			tmp = tmp->next;
		elem->down = tmp;
		tmp->up = elem;
	}
	return (begin);
}
