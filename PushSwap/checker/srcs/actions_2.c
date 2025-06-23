/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:37:39 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/12 12:46:19 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rot(t_structs **all, int s)
{
	t_num	tail;
	t_stack	*stack;

	if (s == 1)
		stack = (*all)->a;
	else
		stack = (*all)->b;
	if (stack->sz > 1)
	{
		tail = stack->vals[stack->sz - 1];
		erase(&stack, stack->sz - 1);
		push_front(&stack, tail);
	}
	if (s == 1)
		add_cmd(&(*all)->cmds, "rra");
	if (s == 2)
		add_cmd(&(*all)->cmds, "rrb");
}

void	rrr(t_structs **all)
{
	reverse_rot(all, 1);
	reverse_rot(all, 2);
}
