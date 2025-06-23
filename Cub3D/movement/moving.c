/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:51:41 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/06/11 10:08:55 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	move_fwd(t_game *game)
{
	t_player	*player;

	player = game->player;
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
	player->move_x += player->cos_angle;
	player->move_y += player->sin_angle;
	player->moving = true;
	return (0);
}

int	move_back(t_game *game)
{
	t_player	*player;

	player = game->player;
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
	player->move_x -= player->cos_angle;
	player->move_y -= player->sin_angle;
	player->moving = true;
	return (0);
}

int	move_left(t_game *game)
{
	t_player	*player;

	player = game->player;
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
	player->move_x += player->sin_angle;
	player->move_y -= player->cos_angle;
	player->moving = true;
	return (0);
}

int	move_right(t_game *game)
{
	t_player	*player;

	player = game->player;
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
	player->move_x -= player->sin_angle;
	player->move_y += player->cos_angle;
	player->moving = true;
	return (0);
}
