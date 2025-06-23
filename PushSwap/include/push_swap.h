/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:04:19 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/08/13 16:18:19 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_num
{
	int		val;
	int		o_ind;
	int		t_ind;
}				t_num;

typedef struct s_stack
{
	t_num	*vals;
	int		sz;
	int		max_sz;
}				t_stack;

typedef struct s_chunks
{
	int	sz;
	int	chunks;
	int	ch_size;
	int	up;
	int	mid;
	int	low;
}				t_chunks;

typedef struct s_comms
{
	char			*command;
	struct s_comms	*next_cmd;
	int				count;
}				t_comms;

typedef struct s_structs
{
	t_stack		*a;
	t_stack		*b;
	t_chunks	*info;
	t_comms		*cmds;
}				t_structs;

/*STACK*/
t_stack		*init_stack(int *nums, int len);
void		erase(t_stack **stack, int pos);
void		push_back(t_stack **stack, t_num num);
void		push_front(t_stack **stack, t_num num);
/*ACTIONS*/
void		swap(t_structs **all, int s);
void		ss(t_structs **all);
void		push(t_structs **all, int s);
void		rotate(t_structs **all, int s);
void		rr(t_structs **all);
void		reverse_rot(t_structs **all, int s);
void		rrr(t_structs **all);
void		push_swap(t_structs **all);
void		call_rotation(t_structs **all, int dir, int stack);
/*HARDCODE*/
void		sort_two(t_structs **all);
void		sort_three(t_structs **all);
void		sort_four(t_structs **all);
void		sort_five(t_structs **all);
/*SORTING*/
void		sort_that_shi(t_structs **all);
void		quick_sort(t_num *nums, int low, int high);
void		clear_stack_a(t_structs **all);
/*HELPERS*/
int			is_sorted(t_stack *a);
int			find_min(t_stack *a);
int			is_valid_arg(char **split_arg);
int			error(void);
int			word_count(char *av);
int			has_duplicates(char **arr);
int			other_atoi(const char *str, int *ptr);
void		rotate_max_up(t_structs **all);
int			find_max(t_stack *stack);
int			find_closer(t_stack *stack, int low, int high);
/*INITIATING*/
int			*split_n_fill(char	*arg, int sz);
int			*fill(char **arg, int len);
t_chunks	*create_info(t_stack **stack);
void		set_t_indices(t_structs **all);
void		put_em_back(t_num *nums, int sz);
/*FREES*/
void		free_nums(t_stack **stack);
void		free_struct(t_stack **stack);
void		free_all(t_stack **stack);
void		free_arr(char **arr, int i);
void		free_cmds(t_comms *comms);
/*COMMANDS*/
void		add_cmd(t_comms **cmds, char *cmd);
void		optimize_cmd_list(t_comms **cmds);
void		print_cmds(t_comms **cmds);

#endif