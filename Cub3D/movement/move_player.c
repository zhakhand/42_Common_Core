/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:23:37 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/06/18 13:59:09 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	turn_player(t_game *game)
{
	game->player->cos_angle = cos(game->player->angle);
	game->player->sin_angle = sin(game->player->angle);
	if (game->player->turn_left)
		game->player->angle -= game->player->angle_speed;
	if (game->player->turn_right)
		game->player->angle += game->player->angle_speed;
	if (game->player->angle > 2 * PI)
		game->player->angle = 0;
	if (game->player->angle < 0)
		game->player->angle = 2 * PI;
}

bool	check_collision(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || map_x >= game->map->width \
		|| map_y >= game->map->height)
		return (true);
	if (game->map->map[map_y][map_x] == '1')
		return (true);
	if (x - map_x < 0.1 && map_x > 0 \
			&& game->map->map[map_y][map_x - 1] == '1')
		return (true);
	if ((map_x + 1) - x < 0.1 && map_x < game->map->width - 1 \
			&& game->map->map[map_y][map_x + 1] == '1')
		return (true);
	if (y - map_y < 0.1 && map_y > 0 \
			&& game->map->map[map_y - 1][map_x] == '1')
		return (true);
	if ((map_y + 1) - y < 0.1 && map_y < game->map->height - 1 \
			&& game->map->map[map_y + 1][map_x] == '1')
		return (true);
	return (false);
}

static void	handle_movement(t_game *game)
{
	double	length;
	double	new_x;
	double	new_y;

	length = sqrt(game->player->move_x * game->player->move_x \
		+ game->player->move_y * game->player->move_y);
	if (length > 0)
	{
		game->player->move_x /= length;
		game->player->move_y /= length;
	}
	new_x = game->player->x + game->player->move_x * game->player->speed;
	new_y = game->player->y + game->player->move_y * game->player->speed;
	if (!check_collision(game, new_x, game->player->y))
		game->player->x = new_x;
	if (!check_collision(game, game->player->x, new_y))
		game->player->y = new_y;
}

int	move_player(t_game *game)
{
	turn_player(game);
	game->player->moving = false;
	game->player->move_x = 0;
	game->player->move_y = 0;
	if (game->player->fwd)
		move_fwd(game);
	if (game->player->back)
		move_back(game);
	if (game->player->right)
		move_right(game);
	if (game->player->left)
		move_left(game);
	if (game->player->moving && (game->player->move_x != 0 \
			|| game->player->move_y != 0))
		handle_movement(game);
	return (0);
}
