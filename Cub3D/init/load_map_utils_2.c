/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:37:46 by oshcheho          #+#    #+#             */
/*   Updated: 2025/06/18 11:01:25 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_width_and_height(t_map *map, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > map->width)
		map->width = len;
	map->height++;
}

int	init_map_field(t_map *map)
{
	char	**new_map;
	int		i;

	new_map = ft_calloc(sizeof(char *), map->height + 1);
	if (!new_map)
	{
		perror("Error allocating memory for map\n");
		return (0);
	}
	i = 0;
	while (i < map->height)
	{
		new_map[i] = ft_calloc(sizeof(char), map->width + 1);
		if (!new_map[i])
		{
			while (i-- > 0)
				free(new_map[i]);
			free(new_map);
			return (ft_putstr_fd("memory err\n", 2), 0);
		}
		i++;
	}
	new_map[i] = NULL;
	map->map = new_map;
	return (1);
}

int	check_for_null_near(t_map *map, int i, int j)
{
	if (i > 0 && (map->map[i - 1][j] == '0'
		|| map->map[i - 1][j] == 'N' || map->map[i - 1][j] == 'S'
		|| map->map[i - 1][j] == 'E' || map->map[i - 1][j] == 'W'))
		return (1);
	if (i < map->height - 1 && (map->map[i + 1][j] == '0'
		|| map->map[i + 1][j] == 'N' || map->map[i + 1][j] == 'S'
		|| map->map[i + 1][j] == 'E' || map->map[i + 1][j] == 'W'))
		return (1);
	if (j > 0 && (map->map[i][j - 1] == '0'
		|| map->map[i][j - 1] == 'N' || map->map[i][j - 1] == 'S'
		|| map->map[i][j - 1] == 'E' || map->map[i][j - 1] == 'W'))
		return (1);
	if (j < map->width - 1 && (map->map[i][j + 1] == '0'
		|| map->map[i][j + 1] == 'N' || map->map[i][j + 1] == 'S'
		|| map->map[i][j + 1] == 'E' || map->map[i][j + 1] == 'W'))
		return (1);
	return (0);
}

void	fill_with_ones(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->map[i][j] = ' ';
			j++;
		}
		map->map[i][j] = '\0';
		i++;
	}
	map->map[i] = NULL;
}

int	fill_line(t_map *map, char *line, int i)
{
	int	j;

	j = 0;
	while (j < map->width)
	{
		if (line[j] == '\n' || line[j] == '\0')
			break ;
		map->map[i][j] = line[j];
		j++;
	}
	return (1);
}
