/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:50:11 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/13 16:12:54 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*split_n_fill(char *arg, int sz)
{
	char	**split_arg;
	int		*nums;
	int		i;

	i = 0;
	split_arg = ft_split(arg, ' ');
	if (!split_arg)
		return (NULL);
	if (!is_valid_arg(split_arg))
		return (free_arr(split_arg, sz), NULL);
	nums = malloc(sizeof(int) * (sz + 1));
	if (!nums)
		return (NULL);
	while (split_arg[i] != 0)
	{
		nums[i] = ft_atoi(split_arg[i]);
		i++;
	}
	free_arr(split_arg, i);
	return (nums);
}

int	*fill(char **arg, int len)
{
	int		*nums;
	int		num;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!is_valid_arg(arg + 1))
		return (NULL);
	nums = malloc(sizeof(int) * len);
	if (!nums)
		return (NULL);
	while (i < len)
	{
		num = ft_atoi(arg[j]);
		nums[i] = num;
		i++;
		j++;
	}
	return (nums);
}

int	word_count(char *av)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*(av + i))
	{
		if (*(av + i) != 32)
		{
			count++;
			while (*(av + i) && (*(av + i) != 32))
				i++;
		}
		else if (*(av + i) == 32)
			i++;
	}
	return (count);
}

int	find_max(t_stack *stack)
{
	int		max;
	int		i;
	t_num	*vals;

	if (!stack || stack->sz == 0)
		return (-1);
	max = 0;
	i = 0;
	vals = stack->vals;
	while (i < stack->sz)
	{
		if (vals[i].t_ind > max)
			max = vals[i].t_ind;
		i++;
	}
	return (max);
}
