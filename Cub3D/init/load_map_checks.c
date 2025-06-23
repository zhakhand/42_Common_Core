/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:10:55 by oshcheho          #+#    #+#             */
/*   Updated: 2025/06/18 11:47:27 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_game_vars(t_map *map)
{
	map->n_texture = NULL;
	map->s_texture = NULL;
	map->w_texture = NULL;
	map->e_texture = NULL;
	map->f_color.r = -1;
	map->f_color.g = -1;
	map->f_color.b = -1;
	map->c_color.r = -1;
	map->c_color.g = -1;
	map->c_color.b = -1;
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->fd = -1;
	map->first_load = 1;
}

int	check_if_map_line(char *line)
{
	int	i;

	i = 0;
	if (check_if_empty_line(line))
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1'
			&& line[i] != '0' && line[i] != '\n'
			&& line[i] != '\r' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}

int	first_load_map(t_map *map, char *map_path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Invalid map file\n", 2), 0);
	map->fd = fd;
	i = 0;
	line = get_next_line(fd, 0);
	while (line)
	{
		check_if_var(line, map, fd);
		check_if_empty_line(line);
		if (check_if_map_line(line))
		{
			if (!check_if_all_vars_set(line, map, fd))
				err(map, "Missing map variables3\n");
			set_width_and_height(map, line);
		}
		free(line);
		i++;
		line = get_next_line(fd, 0);
	}
	return (set_firstload(map), close(fd), free(line), 1);
}

int	check_map_file(char *map_path)
{
	int	fd;

	if (!map_path || map_path[0] == '\0')
		return (ft_putstr_fd("Invalid map path\n", 2), 0);
	if (ft_strncmp(map_path + ft_strlen(map_path) - 4, ".cub", 4) != 0)
		return (ft_putstr_fd("Invalid map file extension\n", 2), 0);
	if (ft_strlen(map_path) < 5)
		return (ft_putstr_fd("Map path too short\n", 2), 0);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error opening map file\n", 2), 0);
	close(fd);
	return (1);
}

int	first_checks(t_map *map, char *map_path)
{
	int	fd;

	if (!check_map_file(map_path))
		return (ft_putstr_fd("Invalid map file\n", 2), 0);
	init_game_vars(map);
	if (!first_load_map(map, map_path))
		return (0);
	if (!init_map_field(map))
		return (ft_putstr_fd("Error initializing map field\n", 2), 0);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error opening map file\n", 2), 0);
	map->fd = fd;
	fill_with_ones(map);
	return (1);
}
