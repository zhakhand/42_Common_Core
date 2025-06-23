/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:19:39 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/09/18 13:19:39 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_swap(t_comms **cmds)
{
	t_comms	*curr;
	t_comms	*to_free;

	curr = NULL;
	to_free = NULL;
	if (!cmds || !(*cmds))
		return (0);
	curr = *cmds;
	if (curr->next_cmd && ft_strncmp("sa", curr->command, 2) == 0 \
	&& ft_strncmp("sb", curr->next_cmd->command, 2) == 0)
	{
		to_free = curr->next_cmd;
		curr->next_cmd = to_free->next_cmd;
		free(to_free);
		return (1);
	}
	else if (curr->next_cmd && ft_strncmp("sb", curr->command, 2) == 0 \
		&& ft_strncmp("sa", curr->next_cmd->command, 2) == 0)
	{
		to_free = curr->next_cmd;
		curr->next_cmd = to_free->next_cmd;
		free(to_free);
		return (1);
	}
	return (0);
}

static int	check_r_rotate(t_comms **cmds)
{
	t_comms	*curr;
	t_comms	*to_free;

	curr = NULL;
	to_free = NULL;
	if (!cmds || !(*cmds))
		return (0);
	curr = *cmds;
	if (curr->next_cmd && ft_strncmp("rra", curr->command, 3) == 0 \
		&& ft_strncmp("rrb", curr->next_cmd->command, 3) == 0)
	{
		to_free = curr->next_cmd;
		curr->next_cmd = to_free->next_cmd;
		free(to_free);
		return (1);
	}
	else if (curr->next_cmd && ft_strncmp("rrb", curr->command, 3) == 0 \
		&& ft_strncmp("rra", curr->next_cmd->command, 3) == 0)
	{
		to_free = curr->next_cmd;
		curr->next_cmd = to_free->next_cmd;
		free(to_free);
		return (1);
	}
	return (0);
}

static int	check_rotate(t_comms **cmds)
{
	t_comms	*curr;
	t_comms	*to_free;

	curr = NULL;
	to_free = NULL;
	if (!cmds || !(*cmds))
		return (0);
	curr = *cmds;
	if (curr->next_cmd && ft_strncmp("ra", curr->command, 2) == 0 \
		&& ft_strncmp("rb", curr->next_cmd->command, 2) == 0)
	{
		to_free = curr->next_cmd;
		curr->next_cmd = to_free->next_cmd;
		free(to_free);
		return (1);
	}
	else if (curr->next_cmd && ft_strncmp("rb", curr->command, 2) == 0 \
		&& ft_strncmp("ra", curr->next_cmd->command, 2) == 0)
	{
		to_free = curr->next_cmd;
		curr->next_cmd = to_free->next_cmd;
		free(to_free);
		return (1);
	}
	return (0);
}

void	optimize_cmd_list(t_comms **cmds)
{
	t_comms	*curr;
	char	*rr;
	char	*ss;
	char	*rrr;

	curr = NULL;
	rr = "rr";
	ss = "ss";
	rrr = "rrr";
	if (!cmds || !(*cmds))
		return ;
	curr = *cmds;
	while (curr)
	{
		if (check_rotate(&curr))
			curr->command = rr;
		else if (check_r_rotate(&curr))
			curr->command = rrr;
		else if (check_swap(&curr))
			curr->command = ss;
		curr = curr->next_cmd;
	}
}

void	print_cmds(t_comms **cmds)
{
	t_comms	*curr;
	t_comms	*to_free;

	curr = NULL;
	to_free = NULL;
	if (!cmds || !(*cmds))
		return ;
	curr = *cmds;
	while (curr)
	{
		ft_printf("%s\n", curr->command);
		to_free = curr;
		curr = curr->next_cmd;
		free(to_free);
	}
}
