/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:42:52 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/06/18 14:59:51 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_block(t_game *game, t_ray *ray)
{
	int	i;
	int	j;

	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			ft_put_pixel(ray->screen_x + j, ray->screen_y + i, 0xAFAFAF, game);
			j++;
		}
		i++;
	}
}

void	draw_rays(t_game *game, t_ray *ray)
{
	ray->distance = 0;
	while (ray->distance < FOV_RADIUS)
	{
		ray->map_x = (int)ray->x;
		ray->map_y = (int)ray->y;
		if (ray->map_y < 0 || ray->map_x < 0 \
			|| !game->map->map[ray->map_y] \
			|| !game->map->map[ray->map_y][ray->map_x])
			break ;
		if (game->map->map[ray->map_y][ray->map_x] == '1')
			break ;
		ray->screen_x = ray->center_x + (ray->x - game->player->x) * TILE_SIZE;
		ray->screen_y = ray->center_y + (ray->y - game->player->y) * TILE_SIZE;
		draw_block(game, ray);
		ray->x += ray->cos_angle * 0.1;
		ray->y += ray->sin_angle * 0.1;
		ray->distance += 0.1;
	}
}

void	draw_minimap(t_game *game, t_ray *ray)
{
	int	angle;

	angle = 0;
	ray->center_x = WIDTH - MINIMAP_SIZE / 2;
	ray->center_y = MINIMAP_SIZE / 2;
	while (angle < 360)
	{
		ray->x = game->player->x;
		ray->y = game->player->y;
		ray->angle = angle * (PI / 180.0);
		ray->cos_angle = cos(ray->angle);
		ray->sin_angle = sin(ray->angle);
		draw_rays(game, ray);
		angle++;
	}
	draw_player_triangle(game, ray->center_x, \
		ray->center_y, game->player->angle);
}

void	draw_ceiling(t_ray *ray, t_game *game)
{
	int	y;

	y = 0;
	while (y < ray->start_y)
	{
		ft_put_pixel(ray->screen_x, y, get_color(&game->map->c_color, y), game);
		y++;
	}
}

void	draw_floor(t_ray *ray, t_game *game)
{
	int	y;

	y = ray->end_y + 1;
	while (y < HEIGHT)
	{
		ft_put_pixel(ray->screen_x, y, get_color(&game->map->f_color, y), game);
		y++;
	}
}
