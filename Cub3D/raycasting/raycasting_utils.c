/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:19:58 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/06/13 16:21:12 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_texture_color(t_texture *tex, int tex_x, int tex_y)
{
	return (*(unsigned int *)(tex->data + \
		(tex_y * tex->size_line + tex_x * (tex->bpp / 8))));
}

void	ft_put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

int	get_color(t_color *color, int y_pos)
{
	int		center;
	int		distance_from_center;
	double	shade_factor;

	center = HEIGHT / 2;
	distance_from_center = abs(y_pos - center);
	shade_factor = (double)distance_from_center / (HEIGHT / 2);
	if (shade_factor < 0.0)
		shade_factor = 0.2;
	if (shade_factor > 1.0)
		shade_factor = 1.0;
	return ((((int)(color->r * shade_factor) & 0xFF) << 16) \
			| (((int)(color->g * shade_factor) & 0xFF) << 8) \
			| ((int)(color->b * shade_factor) & 0xFF));
}

bool	touch(double ray_x, double ray_y, t_game *game)
{
	int	x;
	int	y;

	x = (int)ray_x;
	y = (int)ray_y;
	if (game->map->map[y][x] == '1')
		return (true);
	if (x > 0 && y > 0 && x < game->map->width \
		&& y < game->map->height)
		return (false);
	return (false);
}

void	calculate_hit(t_ray *ray, t_game *game)
{
	ray->map_x = (int)ray->x;
	ray->map_y = (int)ray->y;
	ray->hit_x = ray->x - ray->map_x;
	ray->hit_y = ray->y - ray->map_y;
	if ((int)ray->x < ray->prev_x)
		ray->wall = game->e_texture;
	else if ((int)ray->x > ray->prev_x)
		ray->wall = game->w_texture;
	else if ((int)ray->y > ray->prev_y)
		ray->wall = game->n_texture;
	else if ((int)ray->y < ray->prev_y)
		ray->wall = game->s_texture;
}
