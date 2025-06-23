/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:14:55 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/13 14:29:08 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_structs **all)
{
	if ((*all)->a->vals[0].val > (*all)->a->vals[1].val)
	{
		swap(all, 1);
	}
}

void	sort_three(t_structs **all)
{
	int	min;

	min = find_min((*all)->a);
	if (min == 0 && (*all)->a->vals[1].val > (*all)->a->vals[2].val)
	{
		reverse_rot(all, 1);
		swap(all, 1);
	}
	if (min == 1)
	{
		if ((*all)->a->vals[0].val > (*all)->a->vals[2].val)
			rotate(all, 1);
		else if ((*all)->a->vals[2].val > (*all)->a->vals[0].val)
			swap(all, 1);
	}
	if (min == 2)
	{
		if ((*all)->a->vals[0].val > (*all)->a->vals[1].val)
		{
			swap(all, 1);
			reverse_rot(all, 1);
		}
		else
			reverse_rot(all, 1);
	}
}

void	sort_four(t_structs **all)
{
	int	min;

	min = find_min((*all)->a);
	if (min == 1)
		swap(all, 1);
	if (min == 2)
	{
		rotate(all, 1);
		swap(all, 1);
	}
	if (min == 3)
		reverse_rot(all, 1);
	push(all, 2);
	sort_three(all);
	push(all, 1);
}

void	sort_five(t_structs **all)
{
	int	min;

	min = find_min((*all)->a);
	if (min == 1)
		rotate(all, 1);
	else if (min == 2)
	{
		rotate(all, 1);
		rotate(all, 1);
	}
	else if (min == 3)
	{
		reverse_rot(all, 1);
		reverse_rot(all, 1);
	}
	else if (min == 4)
		reverse_rot(all, 1);
	push(all, 2);
	sort_four(all);
	push(all, 1);
}
