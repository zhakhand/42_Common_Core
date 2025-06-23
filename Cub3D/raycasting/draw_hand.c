/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:02:20 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/06/18 15:08:30 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	calc_brightness(t_ray *ray)
{
	double	max_radius;
	double	dist_from_center;
	double	brightness;

	dist_from_center = abs(ray->screen_x - WIDTH / 2);
	max_radius = 200;
	brightness = 1.0 - (dist_from_center / max_radius);
	if (brightness < 0.2)
		brightness = 0.2;
	return (brightness);
}

int	apply_brightness(t_ray *ray, int color, t_game *game)
{
	double			brightness;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = 0;
	g = 0;
	b = 0;
	brightness = 0.2;
	if (game->light && game->frame % 10 != 0)
		brightness = calc_brightness(ray);
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (unsigned char)(r * brightness);
	g = (unsigned char)(g * brightness);
	b = (unsigned char)(b * brightness);
	return ((r << 16) | (g << 8) | b);
}

void	change_frame(t_game *game)
{
	if (game->frame_up)
	{
		game->frame++;
		if (game->frame == 30)
			game->frame_up = false;
	}
	else
	{
		game->frame--;
		if (game->frame == 0)
			game->frame_up = true;
	}
}

void	draw_hand(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	(void)game;
	change_frame(game);
	while (y < game->hand->height)
	{
		x = 0;
		while (x < game->hand->width)
		{
			color = get_texture_color(game->hand, x, y);
			if (color > 0)
			{
				ft_put_pixel(x + WIDTH - 400, \
					y + (HEIGHT / 2) + (HEIGHT / 10) \
					+ game->frame, color, game);
			}
			x++;
		}
		y++;
	}
}
