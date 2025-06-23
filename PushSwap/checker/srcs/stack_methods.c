/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:52:27 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/12 12:56:12 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(int *nums, int len)
{
	t_stack	*new_stack;
	t_num	val;
	int		i;

	i = 0;
	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		exit(error());
	new_stack->vals = malloc(sizeof(t_num) * len);
	new_stack->sz = 0;
	if (!new_stack->vals)
		return (NULL);
	while (i < len && nums)
	{
		val.val = nums[i];
		val.o_ind = i;
		new_stack->vals[i] = val;
		new_stack->sz++;
		i++;
	}
	new_stack->max_sz = len;
	return (new_stack);
}

void	erase(t_stack **stack, int pos)
{
	int		i;
	t_num	*vals;

	i = 0;
	vals = (*stack)->vals;
	if (pos == 0)
	{
		while (i < (*stack)->sz - 1)
		{
			vals[i] = vals[i + 1];
			i++;
		}
	}
	else
	{
		while (i < pos)
		{
			vals[i] = (*stack)->vals[i];
			i++;
		}
	}
	--(*stack)->sz;
}

void	push_back(t_stack **stack, t_num num)
{
	(*stack)->vals[(*stack)->sz++] = num;
}

void	push_front(t_stack **stack, t_num num)
{
	t_num	*vals;
	int		i;

	vals = (*stack)->vals;
	i = (*stack)->sz;
	while (i > 0)
	{
		vals[i] = vals[i - 1];
		i--;
	}
	vals[0] = num;
	(*stack)->sz++;
}
