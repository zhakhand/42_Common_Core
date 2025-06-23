/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:20:22 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/18 13:20:23 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	q_swap(t_num *a, t_num *b)
{
	t_num	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(t_num *nums, int low, int high)
{
	int		pivot;
	int		i;
	int		j;

	i = low - 1;
	j = low;
	pivot = nums[high].val;
	while (j < high)
	{
		if (nums[j].val <= pivot)
		{
			i++;
			q_swap(&nums[i], &nums[j]);
		}
		j++;
	}
	q_swap(&nums[i + 1], &nums[high]);
	return (i + 1);
}

void	quick_sort(t_num *nums, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(nums, low, high);
		quick_sort(nums, low, pivot - 1);
		quick_sort(nums, pivot + 1, high);
	}
}

void	put_em_back(t_num *nums, int sz)
{
	int	i;
	int	j;

	i = 0;
	while (i < sz)
	{
		j = 0;
		while (j < sz)
		{
			if (nums[j].o_ind != j)
				q_swap(&nums[j], &nums[nums[j].o_ind]);
			j++;
		}
		i++;
	}
}
