/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:20:31 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/18 13:20:32 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	set_em(t_num *nums, int sz)
{
	int	i;

	i = 0;
	while (i < sz)
	{
		nums[i].t_ind = i;
		i++;
	}
}

void	set_t_indices(t_structs **all)
{
	t_stack	*stack;
	t_num	*vals;

	stack = (*all)->a;
	vals = stack->vals;
	quick_sort(vals, 0, stack->sz - 1);
	set_em(vals, stack->sz);
	put_em_back(vals, stack->sz);
}

t_chunks	*create_info(t_stack **stack)
{
	t_chunks	*info;

	info = malloc(sizeof(t_chunks));
	if (!info)
		return (NULL);
	if ((*stack)->sz <= 10)
		info->chunks = 5;
	else if ((*stack)->sz <= 150)
		info->chunks = 8;
	else
		info->chunks = 18;
	info->ch_size = (*stack)->sz / info->chunks;
	info->mid = (*stack)->sz / 2;
	info->up = info->mid + info->ch_size;
	info->low = info->mid - info->ch_size;
	return (info);
}
