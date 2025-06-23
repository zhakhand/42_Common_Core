/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:29:32 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/18 15:27:15 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_int(char	**arr)
{
	size_t	i;
	long	number;
	int		num;

	i = 0;
	while (arr[i] != 0)
	{
		number = other_atoi(arr[i], &num);
		if (!number)
			return (0);
		i++;
	}
	return (1);
}

static int	is_num(char **arr)
{
	size_t	i;
	size_t	j;
	int		sign;

	i = 0;
	while (arr[i] != 0)
	{
		j = 0;
		sign = 0;
		while (arr[i][j] != 0)
		{
			if ((arr[i][j] == '-' || arr[i][j] == '+') && !sign)
			{
				j++;
				sign = 1;
			}
			if (!(arr[i][j] >= 48 && arr[i][j] <= 57))
				return (0);
			sign = 1;
			j++;
		}
		i++;
	}
	return (1);
}

int	has_duplicates(char **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (arr[i] != 0)
	{
		j = i + 1;
		while (arr[j] != 0)
		{
			if (ft_atoi(arr[j]) == ft_atoi(arr[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_arg(char **split_arg)
{
	if (has_duplicates(split_arg) == 1)
		return (0);
	if (!is_num(split_arg))
		return (0);
	if (!is_int(split_arg))
		return (0);
	return (1);
}
