/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:47:59 by oshcheho          #+#    #+#             */
/*   Updated: 2025/06/18 13:56:50 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	sanitize_line(char *line)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (line[i])
	{
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

void	validate_texture_split(char **split)
{
	size_t	len;

	len = ft_strlen(split[1]);
	if (split[1] == NULL || (split[2] && split[2][0] != '\n'))
	{
		free_split(split);
		err(NULL, "Invalid texture path2\n");
	}
	if (split[1][0] == '\n' || split[1][0] == '\r')
	{
		free_split(split);
		err(NULL, "Invalid texture path3\n");
	}
	if (len > 0 && (split[1][len - 1] == '\n' || \
		split[1][len - 1] == '\r'))
		split[1][len - 1] = '\0';
}

int	assign_texture_path(t_map *map, char **split, char *line)
{
	if (ft_strncmp(split[0], "NO", 3) == 0)
	{
		if (!set_n_texture(map, split[1], split, line))
			return (0);
	}
	else if (ft_strncmp(split[0], "SO", 3) == 0)
	{
		if (!set_s_texture(map, split[1], split, line))
			return (0);
	}
	else if (ft_strncmp(split[0], "WE", 3) == 0)
	{
		if (!set_w_texture(map, split[1], split, line))
			return (0);
	}
	else if (ft_strncmp(split[0], "EA", 3) == 0)
	{
		if (!set_e_texture(map, split[1], split, line))
			return (0);
	}
	return (1);
}

int	set_textures(t_map *map, char *line)
{
	char	**split;

	if (ft_strncmp(line, "NO ", 3) == 0 || \
		ft_strncmp(line, "SO ", 3) == 0 || \
		ft_strncmp(line, "WE ", 3) == 0 || \
		ft_strncmp(line, "EA ", 3) == 0)
	{
		if (!sanitize_line(line))
			return (1);
		split = ft_split(line, ' ');
		if (!split)
		{
			free(line);
			err(NULL, "Invalid split for texture\n");
		}
		validate_texture_split(split);
		if (!assign_texture_path(map, split, line))
		{
			return (1);
		}
		free_split(split);
		return (1);
	}
	return (0);
}
