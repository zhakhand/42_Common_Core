/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:47:09 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/13 16:18:37 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

static void	till_5(t_structs **all)
{
	if ((*all)->a->sz == 2)
		sort_two(all);
	else if ((*all)->a->sz == 3)
		sort_three(all);
	else if ((*all)->a->sz == 4)
		sort_four(all);
	else if ((*all)->a->sz == 5)
		sort_five(all);
}

static	t_stack	*create_n_fill(int ac, char **av)
{
	int		*nums;
	int		arr_size;
	t_stack	*a;

	a = NULL;
	nums = NULL;
	if (ac == 2)
	{
		arr_size = word_count(av[1]);
		if (arr_size == 0)
			return (NULL);
		nums = split_n_fill(av[1], arr_size);
	}
	else if (ac > 2)
	{
		arr_size = ac - 1;
		nums = fill(av, arr_size);
	}
	if (!nums)
		return (NULL);
	a = init_stack(nums, arr_size);
	if (!a)
		return (free_all(&a), NULL);
	ft_free(&nums);
	return (a);
}

void	push_swap(t_structs **all)
{
	t_stack		*b;
	t_chunks	*info;

	if (is_sorted((*all)->a))
		return ;
	b = init_stack(NULL, (*all)->a->sz);
	(*all)->b = b;
	if (!b)
		return ;
	if ((*all)->a->sz <= 5)
		till_5(all);
	else
	{
		info = create_info(&(*all)->a);
		if (!info)
			return ;
		(*all)->info = info;
		sort_that_shi(all);
	}
	free_nums(&b);
	free_struct(&b);
}

int	main(int ac, char **av)
{
	t_structs	*all;	

	if (ac < 2)
		return (0);
	all = malloc(sizeof(t_structs));
	if (!all)
		return (error());
	all->a = create_n_fill(ac, av);
	all->cmds = NULL;
	all->info = NULL;
	if (!all->a)
		return (free(all), error());
	push_swap(&all);
	if (all->cmds && all->cmds->count > 12)
		optimize_cmd_list(&all->cmds);
	print_cmds(&all->cmds);
	free_nums(&all->a);
	free_struct(&all->a);
	if (all->info)
		free(all->info);
	free(all);
	return (0);
}
