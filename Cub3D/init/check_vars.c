/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:27:48 by oshcheho          #+#    #+#             */
/*   Updated: 2025/06/09 17:27:48 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_texture_access(t_map *map)
{
	if (access(map->n_texture, F_OK) == -1)
		return (0);
	if (access(map->s_texture, F_OK) == -1)
		return (0);
	if (access(map->w_texture, F_OK) == -1)
		return (0);
	if (access(map->e_texture, F_OK) == -1)
		return (0);
	return (1);
}

int	check_color_values(t_map *map)
{
	if (map->f_color.r < 0 || map->f_color.r > 255
		|| map->f_color.g < 0 || map->f_color.g > 255
		|| map->f_color.b < 0 || map->f_color.b > 255)
	{
		return (0);
	}
	if (map->c_color.r < 0 || map->c_color.r > 255
		|| map->c_color.g < 0 || map->c_color.g > 255
		|| map->c_color.b < 0 || map->c_color.b > 255)
	{
		return (0);
	}
	return (1);
}

int	check_if_all_vars_set(char *line, t_map *map, int fd)
{
	if (map->n_texture == NULL || map->s_texture == NULL || \
		map->w_texture == NULL || map->e_texture == NULL || \
		map->f_color.r == -1 || map->f_color.g == -1 || \
		map->f_color.b == -1 || map->c_color.r == -1 || \
		map->c_color.g == -1 || map->c_color.b == -1)
	{
		if (line)
			free(line);
		get_next_line(fd, 1);
		close(fd);
		err(map, "Wrong map variables!\n");
		return (0);
	}
	return (1);
}

int	check_tex_file_ext(t_map *map)
{
	if (ft_strncmp(map->n_texture + \
		ft_strlen(map->n_texture) - 4, ".xpm", 4) != 0)
		return (0);
	if (ft_strncmp(map->s_texture + \
		ft_strlen(map->s_texture) - 4, ".xpm", 4) != 0)
		return (0);
	if (ft_strncmp(map->w_texture + \
		ft_strlen(map->w_texture) - 4, ".xpm", 4) != 0)
		return (0);
	if (ft_strncmp(map->e_texture + \
		ft_strlen(map->e_texture) - 4, ".xpm", 4) != 0)
		return (0);
	return (1);
}

int	check_vars(t_map *map)
{
	if (map->n_texture[ft_strlen(map->n_texture) - 1] == '\r')
		map->n_texture[ft_strlen(map->n_texture) - 1] = '\0';
	if (map->s_texture[ft_strlen(map->s_texture) - 1] == '\r')
		map->s_texture[ft_strlen(map->s_texture) - 1] = '\0';
	if (map->w_texture[ft_strlen(map->w_texture) - 1] == '\r')
		map->w_texture[ft_strlen(map->w_texture) - 1] = '\0';
	if (map->e_texture[ft_strlen(map->e_texture) - 1] == '\r')
		map->e_texture[ft_strlen(map->e_texture) - 1] = '\0';
	if (!check_texture_access(map))
	{
		ft_putstr_fd("Texture access check failed\n", 2);
		return (0);
	}
	if (!check_color_values(map))
		return (0);
	if (!check_tex_file_ext(map))
		return (0);
	return (1);
}
