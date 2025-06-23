/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:19:57 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/18 13:19:57 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	another_rotation(t_structs **all, int bottom)
{
	t_stack	*a;

	a = (*all)->a;
	while (a->vals[0].t_ind == a->vals[a->sz - 1].t_ind + 1)
	{
		reverse_rot(all, 1);
		bottom--;
	}
	return (bottom);
}

void	shi_sorted(t_structs **all)
{
	int	bottom;

	bottom = 0;
	rotate_max_up(all);
	while (find_max((*all)->b) >= 0)
	{
		if (!(*all)->a->sz || \
			(*all)->b->vals[0].t_ind == (*all)->a->vals[0].t_ind - 1)
		{
			push(all, 1);
			if (bottom)
				bottom = another_rotation(all, bottom);
		}
		else if ((*all)->b->vals[0].t_ind > \
			(*all)->a->vals[(*all)->a->sz - 1].t_ind || bottom <= 0)
		{
			push(all, 1);
			rotate(all, 1);
			bottom++;
		}
		else
			call_rotation(all, find_closer((*all)->b, \
				(*all)->a->vals[(*all)->a->sz - 1].t_ind + 1, \
					(*all)->a->vals[0].t_ind - 1), 2);
	}
}

void	clear_stack_a(t_structs **all)
{
	t_stack		*a;
	t_chunks	*info;
	t_num		*vals;

	a = (*all)->a;
	info = (*all)->info;
	vals = a->vals;
	while (a->sz > 0 || find_closer(a, info->low, info->up) > -1)
	{
		while (find_closer(a, info->low, info->up) > -1)
		{
			if (a->sz > 0 && vals[0].t_ind >= info->low \
			&& vals[0].t_ind <= info->up)
				break ;
			call_rotation(all, find_closer(a, info->low, info->up), 1);
		}
		push(all, 2);
		if ((*all)->b->vals[0].t_ind < info->mid)
			rotate(all, 2);
		if (find_closer(a, info->low, info->mid) < 0)
			info->low -= info->ch_size;
		if (find_closer(a, info->mid, info->up) < 0)
			info->up += info->ch_size;
	}
}

void	sort_that_shi(t_structs **all)
{
	set_t_indices(all);
	clear_stack_a(all);
	shi_sorted(all);
}
