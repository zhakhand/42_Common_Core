/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:27:38 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/13 16:18:02 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	i = 1;
	if (!a || !a->vals)
		exit(error());
	while (i < a->sz && a->vals)
	{
		if (a->vals[i - 1].val > a->vals[i].val)
			return (0);
		i++;
	}
	return (1);
}

int	find_min(t_stack *a)
{
	int		min;
	int		i;
	int		offset;

	min = a->vals[0].val;
	i = 1;
	offset = 0;
	while (i < a->sz)
	{
		if (min > a->vals[i].val)
			min = a->vals[i].val;
		i++;
	}
	while (offset < a->sz)
	{
		if (a->vals[offset].val == min)
			break ;
		offset++;
	}
	return (offset);
}

int	error(void)
{
	ft_printf("Error\n");
	return (1);
}

void	add_cmd(t_comms **cmds, char *cmd)
{
	t_comms	*com;
	t_comms	*curr;

	com = malloc(sizeof(t_comms));
	if (!com)
		return ;
	com->command = cmd;
	com->next_cmd = NULL;
	com->count = 0;
	if (!com->command)
		return ;
	if (!cmds || !(*cmds))
	{
		com->count++;
		*cmds = com;
	}
	else
	{
		curr = *cmds;
		while (curr && curr->next_cmd)
			curr = curr->next_cmd;
		curr->next_cmd = com;
		(*cmds)->count++;
	}
}

int	other_atoi(const char *str, int *ptr)
{
	long		n;
	int			sign;

	n = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		if (n > (long)INT_MAX + (long)(sign == -1))
			return (0);
		str++;
	}
	*ptr = (n * sign);
	return (1);
}
