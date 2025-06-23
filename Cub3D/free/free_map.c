/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:39:28 by oshcheho          #+#    #+#             */
/*   Updated: 2025/06/17 16:30:52 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_textures(t_map *map)
{
	if (!map)
		return ;
	if (map->n_texture)
	{
		free(map->n_texture);
		map->n_texture = NULL;
	}
	if (map->s_texture)
	{
		free(map->s_texture);
		map->s_texture = NULL;
	}
	if (map->w_texture)
	{
		free(map->w_texture);
		map->w_texture = NULL;
	}
	if (map->e_texture)
	{
		free(map->e_texture);
		map->e_texture = NULL;
	}
}

void	err(t_map *map, char *msg)
{
	if (map)
		free_map(map);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	get_next_line (map->fd, 1);
	if (map->fd >= 0)
		close(map->fd);
	free_textures(map);
	if (map->map)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
	free(map);
}
