/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:34:48 by oshcheho          #+#    #+#             */
/*   Updated: 2025/06/18 13:17:09 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	cleanup_and_error(t_map *map, char *line, int fd, char *msg)
{
	get_next_line (map->fd, 1);
	if (line)
		free(line);
	if (fd >= 0)
		close(fd);
	if (map->fd >= 0)
		close(map->fd);
	if (msg)
		ft_putstr_fd(msg, 2);
	return (0);
}

int	process_map_line(t_map *map, char *line, int i)
{
	if (!check_vars(map))
		return (cleanup_and_error(map, line, -1, "Wrong vars\n"), 0);
	if (!fill_line(map, line, i))
		return (cleanup_and_error(map, line, map->fd, NULL), 0);
	return (1);
}

int	process_line(t_map *map, char *line, int *i)
{
	if (check_if_var(line, map, map->fd) || check_if_empty_line(line))
	{
		free(line);
		return (1);
	}
	if (check_if_map_line(line))
	{
		if (!process_map_line(map, line, *i))
			return (0);
	}
	else
		return (cleanup_and_error(map, line, map->fd, WML), 0);
	free(line);
	(*i)++;
	return (1);
}

int	init_map1(t_map *map, char *map_path)
{
	char	*line;
	int		i;

	if (!first_checks(map, map_path))
		return (0);
	i = 0;
	line = get_next_line(map->fd, 0);
	if (!line)
		return (cleanup_and_error(map, NULL, map->fd, "Map file error\n"), 0);
	while (line)
	{
		if (!process_line(map, line, &i))
			return (0);
		line = get_next_line(map->fd, 0);
	}
	map->map[i] = NULL;
	close(map->fd);
	return (1);
}
