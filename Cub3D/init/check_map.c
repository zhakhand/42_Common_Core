/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:20:05 by oshcheho          #+#    #+#             */
/*   Updated: 2025/06/09 17:20:05 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	change_nul_to_space(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == '\n')
				map->map[i][j] = ' ';
			if (map->map[i][j] == '\r')
				map->map[i][j] = ' ';
			if (map->map[i][j] == '\0')
				map->map[i][j] = ' ';
			j++;
		}
		i++;
	}
	return (1);
}

int	make_borders(t_map *map)
{
	int	i;
	int	j;

	change_nul_to_space(map);
	i = 0;
	j = 0;
	while (map->map[i])
	{
		j = 0;
		while (j < map->width)
		{
			if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
			{
				if (map->map[i][j] == ' ')
					map->map[i][j] = ' ';
				else if (map->map[i][j] == '0' || map->map[i][j] == 'N' \
				|| map->map[i][j] == 'S' || map->map[i][j] == 'E'
				|| map->map[i][j] == 'W')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_for_null_and_put_one(t_map *map, int i, int j)
{
	if (i > 0 && (map->map[i - 1][j] == '0'
		|| map->map[i - 1][j] == 'N'
		|| map->map[i - 1][j] == 'S' || map->map[i - 1][j] == 'E'
		|| map->map[i - 1][j] == 'W'))
		return (1);
	if (i < map->height - 1 && (map->map[i + 1][j] == '0'
		|| map->map[i + 1][j] == 'N' || map->map[i + 1][j] == 'S'
		|| map->map[i + 1][j] == 'E'
		|| map->map[i + 1][j] == 'W'))
		return (1);
	if (j > 0 && (map->map[i][j - 1] == '0'
		|| map->map[i][j - 1] == 'N' || map->map[i][j - 1] == 'S'
		|| map->map[i][j - 1] == 'E'
		|| map->map[i][j - 1] == 'W'))
		return (1);
	if (j < map->width - 1 && (map->map[i][j + 1] == '0'
		|| map->map[i][j + 1] == 'N' || map->map[i][j + 1] == 'S'
		|| map->map[i][j + 1] == 'E'
		|| map->map[i][j + 1] == 'W'))
		return (1);
	return (0);
}

int	make_ones(t_map *map)
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
			if (map->map[i][j] == ' ')
			{
				if (!check_for_null_and_put_one(map, i, j))
					map->map[i][j] = '1';
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_map *map)
{
	if (!make_borders(map))
	{
		err(map, "Invalid map borders\n");
		return (0);
	}
	if (!make_ones(map))
	{
		err(map, "Invalid map!\n");
		return (0);
	}
	return (1);
}
