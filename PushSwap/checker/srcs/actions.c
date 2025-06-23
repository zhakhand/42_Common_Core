/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:35:47 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/12 11:50:47 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_structs **all, int s)
{
	t_num	temp;
	t_stack	*stack;

	if (s == 1)
		stack = (*all)->a;
	else
		stack = (*all)->b;
	if (stack->sz >= 2)
	{
		temp = stack->vals[0];
		stack->vals[0] = stack->vals[1];
		stack->vals[1] = temp;
	}
	if (s == 1)
		add_cmd(&(*all)->cmds, "sa");
	if (s == 2)
		add_cmd(&(*all)->cmds, "sb");
}

void	ss(t_structs **all)
{
	swap(all, 1);
	swap(all, 2);
}

void	push(t_structs **all, int s)
{
	t_num	head;
	t_stack	*from;
	t_stack	*to;

	if (s == 1)
	{
		from = (*all)->b;
		to = (*all)->a;
	}
	else
	{
		from = (*all)->a;
		to = (*all)->b;
	}
	if (from->sz > 0)
	{
		head = from->vals[0];
		erase(&from, 0);
		push_front(&to, head);
	}
	if (s == 1)
		add_cmd(&(*all)->cmds, "pa");
	if (s == 2)
		add_cmd(&(*all)->cmds, "pb");
}

void	rotate(t_structs **all, int s)
{
	t_num	head;
	t_stack	*stack;

	if (s == 1)
		stack = (*all)->a;
	else
		stack = (*all)->b;
	if (stack->sz >= 2)
	{
		head = stack->vals[0];
		erase(&stack, 0);
		push_back(&stack, head);
	}
	if (s == 1)
		add_cmd(&(*all)->cmds, "ra");
	if (s == 2)
		add_cmd(&(*all)->cmds, "rb");
}

void	rr(t_structs **all)
{
	rotate(all, 1);
	rotate(all, 2);
}
