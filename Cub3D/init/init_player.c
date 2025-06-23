/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:10:23 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/06/18 11:01:54 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	set_angle(t_player *player)
{
	if (player->dir == 'S')
		return (PI / 2);
	else if (player->dir == 'W')
		return (PI);
	else if (player->dir == 'N')
		return (3 * PI / 2);
	else
		return (0);
}

void	init_player(t_game *game)
{
	game->player->x += 0.5;
	game->player->y += 0.5;
	game->player->angle = set_angle(game->player);
	game->player->angle_speed = 0.05;
	game->player->speed = 0.1;
	game->player->fwd = false;
	game->player->back = false;
	game->player->left = false;
	game->player->right = false;
	game->player->turn_left = false;
	game->player->turn_right = false;
}

int	put_player(t_map *map, t_player *player)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' \
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				player->x = j;
				player->y = i;
				player->dir = map->map[i][j];
				found++;
			}
			j++;
		}
		i++;
	}
	return (found);
}
