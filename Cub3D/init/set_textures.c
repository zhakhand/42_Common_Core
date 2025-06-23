/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:56:56 by oshcheho          #+#    #+#             */
/*   Updated: 2025/06/18 11:50:29 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	set_n_texture(t_map *map, char *line, char **split, char *line1)
{
	if (map->n_texture)
	{
		if (map->first_load == 1)
		{
			if (split)
				free_split(split);
			free(line1);
			err(map, "Invalid texture path\n");
		}
	}
	free(map->n_texture);
	map->n_texture = ft_strdup(line);
	return (1);
}

int	set_s_texture(t_map *map, char *line, char **split, char *line1)
{
	if (map->s_texture)
	{
		if (map->first_load == 1)
		{
			if (split)
				free_split(split);
			free(line1);
			err(map, "Invalid texture path\n");
		}
	}
	free(map->s_texture);
	map->s_texture = ft_strdup(line);
	return (1);
}

int	set_w_texture(t_map *map, char *line, char **split, char *line1)
{
	if (map->w_texture)
	{
		if (map->first_load == 1)
		{
			if (split)
				free_split(split);
			free(line1);
			err(map, "Invalid texture path\n");
		}
	}
	free(map->w_texture);
	map->w_texture = ft_strdup(line);
	return (1);
}

int	set_e_texture(t_map *map, char *line, char **split, char *line1)
{
	if (map->e_texture)
	{
		if (map->first_load == 1)
		{
			if (split)
				free_split(split);
			free(line1);
			err(map, "Invalid texture path\n");
		}
	}
	free(map->e_texture);
	map->e_texture = ft_strdup(line);
	return (1);
}
