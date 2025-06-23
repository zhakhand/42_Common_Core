/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:56:41 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/06/18 13:51:15 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	calculate_tex_x(t_ray *ray, t_player *player, \
							double ray_angle, t_game *game)
{
	if (ray->wall == game->e_texture || ray->wall == game->w_texture)
	{
		ray->wall_x = (int)(ray->hit_y * ray->wall->width);
		if (ray->cos_angle < 0)
			ray->wall_x = ray->wall->width - ray->wall_x - 1;
	}
	else
	{
		ray->wall_x = (int)(ray->hit_x * ray->wall->width);
		if (ray->sin_angle > 0)
			ray->wall_x = ray->wall->width - ray->wall_x - 1;
	}
	if (ray->wall_x < 0)
		ray->wall_x = 0;
	if (ray->wall_x >= ray->wall->width)
		ray->wall_x = ray->wall->width - 1;
	ray->distance = sqrt(pow(player->x - ray->x, 2) \
					+ pow(player->y - ray->y, 2));
	ray->distance = ray->distance * cos(ray_angle - player->angle);
	if (ray->distance < 0.1)
		ray->distance = 0.1;
	ray->wall_height = HEIGHT / ray->distance;
	if (ray->wall_height <= 0)
		ray->wall_height = 1;
}

static void	scale_tex(t_ray *ray)
{
	ray->eye_level = HEIGHT / 2;
	ray->start_y = ray->eye_level - (ray->wall_height / 2);
	ray->end_y = ray->eye_level + (ray->wall_height / 2);
	ray->tex_scale = 1.0;
	ray->tex_offset = 0.0;
	if (ray->wall_height > HEIGHT)
	{
		ray->tex_scale = HEIGHT / ray->wall_height;
		ray->tex_offset = 0.5 - (ray->tex_scale / 2);
		ray->start_y = 0;
		ray->end_y = HEIGHT - 1;
	}
	else
	{
		if (ray->start_y < 0)
			ray->start_y = 0;
		if (ray->end_y >= HEIGHT)
			ray->end_y = HEIGHT - 1;
	}
}

static void	draw_tex(t_ray *ray, t_game *game)
{
	int	y;
	int	color;

	y = ray->start_y;
	while (y <= ray->end_y)
	{
		ray->screen_pos = (double)(y - ray->start_y) \
						/ (ray->end_y - ray->start_y);
		if (ray->wall_height > HEIGHT)
			ray->tex_pos = ray->tex_offset + (ray->screen_pos * ray->tex_scale);
		else
			ray->tex_pos = ray->screen_pos;
		ray->wall_y = (int)(ray->tex_pos * ray->wall->height);
		if (ray->wall_y < 0)
			ray->wall_y = 0;
		if (ray->wall_y >= ray->wall->height)
			ray->wall_y = ray->wall->height - 1;
		color = get_texture_color(ray->wall, ray->wall_x, ray->wall_y);
		color = apply_brightness(ray, color, game);
		if (color == 0)
			color = 0x000000;
		ft_put_pixel(ray->screen_x, y, color, game);
		y++;
	}
}

void	draw_line(t_player *player, t_game *game, double ray_angle, t_ray *ray)
{
	ray->cos_angle = cos(ray_angle);
	ray->sin_angle = sin(ray_angle);
	ray->angle = ray_angle;
	ray->x = player->x;
	ray->y = player->y;
	ray->step = 0.0025;
	ray->hit_vert = false;
	while (!touch(ray->x, ray->y, game))
	{
		ray->prev_x = (int)ray->x;
		ray->x += ray->cos_angle * ray->step;
		ray->prev_y = (int)ray->y;
		ray->y += ray->sin_angle * ray->step;
	}
	calculate_hit(ray, game);
	calculate_tex_x(ray, player, ray_angle, game);
	scale_tex(ray);
	draw_ceiling(ray, game);
	draw_tex(ray, game);
	draw_floor(ray, game);
}

int	cast_rays(t_game *game)
{
	int		i;
	double	frac;
	double	ray_angle;
	t_ray	*ray;

	frac = PI / 3.2 / WIDTH;
	ray_angle = game->player->angle - PI / 6.4;
	i = 0;
	ray = ft_calloc(1, sizeof(t_ray));
	if (!ray)
		end_prog(game, "error: malloc");
	while (i < WIDTH)
	{
		ray->screen_x = i;
		draw_line(game->player, game, ray_angle, ray);
		ray_angle += frac;
		ft_bzero(ray, sizeof(t_ray));
		i++;
	}
	draw_minimap(game, ray);
	draw_hand(game);
	free(ray);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
	return (0);
}
