/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:20:10 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/18 15:35:41 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"
#include "./gnl/get_next_line.h"

static void	perform(char *inst, t_structs **all)
{
	if (!ft_strncmp(inst, "sa\n", 3) && (*all)->a->sz)
		swap(all, 1);
	else if (!ft_strncmp(inst, "sb\n", 3) && (*all)->b->sz)
		swap(all, 2);
	else if (!ft_strncmp(inst, "ss\n", 3) && (*all)->b->sz && (*all)->a->sz)
		ss(all);
	else if (!ft_strncmp(inst, "pa\n", 3) && (*all)->b->sz)
		push(all, 1);
	else if (!ft_strncmp(inst, "pb\n", 3) && (*all)->a->sz)
		push(all, 2);
	else if (!ft_strncmp(inst, "ra\n", 3) && (*all)->a->sz)
		rotate(all, 1);
	else if (!ft_strncmp(inst, "rb\n", 3) && (*all)->b->sz)
		rotate(all, 2);
	else if (!ft_strncmp(inst, "rr\n", 3) && (*all)->a->sz && (*all)->b->sz)
		rr(all);
	else if (!ft_strncmp(inst, "rra\n", 4) && (*all)->a->sz)
		reverse_rot(all, 1);
	else if (!ft_strncmp(inst, "rrb\n", 4) && (*all)->b->sz)
		reverse_rot(all, 2);
	else if (!ft_strncmp(inst, "rrr\n", 4) && (*all)->a->sz && (*all)->b->sz)
		rrr(all);
}

static int	invalid_inst(char *inst)
{
	if (!ft_strncmp(inst, "sa\n", 3) || !ft_strncmp(inst, "sb\n", 3)
		|| !ft_strncmp(inst, "ss\n", 3) || !ft_strncmp(inst, "pa\n", 3)
		|| !ft_strncmp(inst, "pb\n", 3) || !ft_strncmp(inst, "ra\n", 3)
		|| !ft_strncmp(inst, "rb\n", 3) || !ft_strncmp(inst, "rr\n", 3)
		|| !ft_strncmp(inst, "rra\n", 4) || !ft_strncmp(inst, "rrb\n", 4)
		|| !ft_strncmp(inst, "rrr\n", 4))
		return (0);
	return (1);
}

int	read_input(t_structs **all)
{
	char	*inst;
	t_stack	*b;

	b = init_stack(NULL, (*all)->a->sz);
	(*all)->b = b;
	if (!b)
		return (0);
	inst = get_next_line(0);
	while (inst)
	{
		if (invalid_inst(inst))
		{
			gnl_free(&inst);
			inst = get_next_line(42);
			return (gnl_free(&inst), ft_printf("Error\n"), 0);
		}
		perform(inst, all);
		gnl_free(&inst);
		inst = get_next_line(0);
	}
	if (is_sorted((*all)->a) && b->sz == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
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
	read_input(&all);
	free_nums(&all->a);
	free_struct(&all->a);
	free_nums(&all->b);
	free_struct(&all->b);
	free_cmds(all->cmds);
	if (all->info)
		free(all->info);
	free(all);
	return (0);
}
