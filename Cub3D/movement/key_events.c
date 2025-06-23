/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:17:47 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/06/18 15:03:44 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key == XK_w || key == XK_W)
		game->player->fwd = true;
	if (key == XK_a || key == XK_A)
		game->player->left = true;
	if (key == XK_s || key == XK_S)
		game->player->back = true;
	if (key == XK_d || key == XK_D)
		game->player->right = true;
	if (key == XK_Left)
		game->player->turn_left = true;
	if (key == XK_Right)
		game->player->turn_right = true;
	if (key == XK_f || key == XK_F)
		game->light = (game->light + 1) % 2;
	if (key == XK_Escape)
		close_prog(game);
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == XK_w || key == XK_W)
		game->player->fwd = false;
	if (key == XK_a || key == XK_A)
		game->player->left = false;
	if (key == XK_s || key == XK_S)
		game->player->back = false;
	if (key == XK_d || key == XK_D)
		game->player->right = false;
	if (key == XK_Left)
		game->player->turn_left = false;
	if (key == XK_Right)
		game->player->turn_right = false;
	return (0);
}
