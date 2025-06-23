/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:19:54 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/18 13:19:55 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_max_up(t_structs **all)
{
	int	max;

	max = find_max((*all)->b);
	while (!((*all)->b->vals[0].t_ind == max))
		call_rotation(all, find_closer((*all)->b, max, max), 2);
}

static int	find_offset(t_stack *stack, int low, int high)
{
	int		offset;
	t_num	*vals;

	offset = 0;
	vals = stack->vals;
	while (offset < stack->sz)
	{
		if (vals[offset].t_ind >= low && vals[offset].t_ind <= high)
			return (offset);
		offset++;
	}
	return (-1);
}

static int	find_r_offset(t_stack *stack, int low, int high)
{
	int		offset;
	int		price;
	t_num	*vals;

	offset = stack->sz - 1;
	vals = stack->vals;
	price = 0;
	while (offset >= 0)
	{
		if (vals[offset].t_ind >= low && vals[offset].t_ind <= high)
			return (price);
		offset--;
		price++;
	}
	return (-1);
}

int	find_closer(t_stack *stack, int low, int high)
{
	int	offset;
	int	r_offset;

	if (!stack || stack->sz == 0)
		return (-1);
	offset = find_offset(stack, low, high);
	r_offset = find_r_offset(stack, low, high);
	if (r_offset < 0 || offset < 0)
		return (-1);
	if (offset < r_offset)
		return (0);
	return (1);
}

void	call_rotation(t_structs **all, int dir, int stack)
{
	if (dir < 0)
		return ;
	if (dir == 0)
		rotate(all, stack);
	else if (dir == 1)
		reverse_rot(all, stack);
}
