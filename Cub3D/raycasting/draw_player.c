/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:15:45 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/06/13 16:31:30 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calc_steps(t_triangle *tr, bool x, bool y)
{
	if (x)
		tr->step_x = 1;
	else
		tr->step_x = -1;
	if (y)
		tr->step_y = 1;
	else
		tr->step_y = -1;
}

void	calc_terms(t_triangle *tr, int flag)
{
	if (flag == 0)
	{
		tr->delta_x = abs(tr->x[1] - tr->x[0]);
		tr->delta_y = -abs(tr->y[1] - tr->y[0]);
		calc_steps(tr, tr->x[0] < tr->x[1], tr->y[0] < tr->y[1]);
	}
	else if (flag == 1)
	{
		tr->delta_x = abs(tr->x[2] - tr->x[1]);
		tr->delta_y = -abs(tr->y[2] - tr->y[1]);
		calc_steps(tr, tr->x[1] < tr->x[2], tr->y[1] < tr->y[2]);
	}
	else
	{
		tr->delta_x = abs(tr->x[0] - tr->x[2]);
		tr->delta_y = -abs(tr->y[0] - tr->y[2]);
		calc_steps(tr, tr->x[2] < tr->x[0], tr->y[2] < tr->y[0]);
	}
	tr->err_term = tr->delta_x + tr->delta_y;
}

void	put_vars(t_triangle *tr, int flag)
{
	if (flag == 0)
	{
		tr->x0 = tr->x[0];
		tr->x1 = tr->x[1];
		tr->y0 = tr->y[0];
		tr->y1 = tr->y[1];
	}
	else if (flag == 1)
	{
		tr->x0 = tr->x[1];
		tr->x1 = tr->x[2];
		tr->y0 = tr->y[1];
		tr->y1 = tr->y[2];
	}
	else
	{
		tr->x0 = tr->x[2];
		tr->x1 = tr->x[0];
		tr->y0 = tr->y[2];
		tr->y1 = tr->y[0];
	}
}

void	draw_tr_line(t_triangle *tr, t_game *game, int flag)
{
	int	temp;

	calc_terms(tr, flag);
	put_vars(tr, flag);
	while (1)
	{
		ft_put_pixel(tr->x0, tr->y0, 0xFF0000, game);
		if (tr->x0 == tr->x1 && tr->y0 == tr->y1)
			break ;
		temp = 2 * tr->err_term;
		if (temp >= tr->delta_y)
		{
			tr->err_term += tr->delta_y;
			tr->x0 += tr->step_x;
		}
		if (temp <= tr->delta_x)
		{
			tr->err_term += tr->delta_x;
			tr->y0 += tr->step_y;
		}
	}
}

void	draw_player_triangle(t_game *game, int center_x, \
							int center_y, double angle)
{
	int			i;
	double		size;
	t_triangle	*triangle;

	i = 0;
	size = 8.0;
	triangle = ft_calloc(1, sizeof(t_triangle));
	if (!triangle)
		end_prog(game, "error: malloc\n");
	triangle->angles[0] = 0;
	triangle->angles[1] = 140 * (PI / 180);
	triangle->angles[2] = -140 * (PI / 180);
	while (i < 3)
	{
		triangle->x[i] = center_x + cos(angle + triangle->angles[i]) * size;
		triangle->y[i] = center_y + sin(angle + triangle->angles[i]) * size;
		i++;
	}
	draw_tr_line(triangle, game, 0);
	draw_tr_line(triangle, game, 1);
	draw_tr_line(triangle, game, 2);
	free(triangle);
}
