/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:29:21 by oshcheho          #+#    #+#             */
/*   Updated: 2025/06/18 13:57:21 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_map_color(t_map *map, char **split)
{
	if (ft_strncmp(split[0], "F", 1) == 0
		&& ft_strlen(split[0]) == 1)
	{
		map->f_color.r = ft_atoi(split[1]);
		map->f_color.g = ft_atoi(split[2]);
		map->f_color.b = ft_atoi(split[3]);
	}
	else if (ft_strncmp(split[0], "C", 1) == 0
		&& ft_strlen(split[0]) == 1)
	{
		map->c_color.r = ft_atoi(split[1]);
		map->c_color.g = ft_atoi(split[2]);
		map->c_color.b = ft_atoi(split[3]);
	}
}

int	sanitize_color(char *line)
{
	int	i;
	int	check;

	i = 1;
	check = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && \
			line[i] != '\n' && line[i] != '\r' && line[i] != ',' && \
			line[i] != '\t')
			return (0);
		if (line[i] == ',')
			check++;
		i++;
	}
	if (check != 2 && check != 0)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == ',' || line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	return (1);
}

int	set_color(t_map *map, char *line, int fd)
{
	char	**split;

	if (!sanitize_color(line))
	{
		close_and_free(fd, line);
		err(map, "Invalid color values\n");
	}
	split = ft_split(line, ' ');
	if (split == NULL)
	{
		free(line);
		return (0);
	}
	if (split[1] == NULL || split[2] == NULL \
		|| split[3] == NULL || split[4] != NULL \
		|| split[3][0] == '\n' )
	{
		free_split(split);
		close_and_free(fd, line);
		err(map, "Invalid color values\n");
	}
	set_map_color(map, split);
	free_split(split);
	return (1);
}

int	check_if_var(char *line, t_map *map, int fd)
{
	if (ft_strncmp(line, "NO", 2) == 0
		|| ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0
		|| ft_strncmp(line, "F", 1) == 0
		|| ft_strncmp(line, "C", 1) == 0)
	{
		if (set_textures(map, line) || set_color(map, line, fd))
			return (1);
		return (1);
	}
	return (0);
}

int	check_if_empty_line(char *line)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (line[i] && res == 1)
	{
		if (line[i] != ' ' && line[i] != '\n'
			&& line[i] != '\r' && line[i] != '\t')
			res = 0;
		i++;
	}
	return (res);
}
