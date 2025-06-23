/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:50:03 by oshcheho          #+#    #+#             */
/*   Updated: 2025/06/16 18:50:03 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

char	*ft_strcpy(char *src)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_and_null1(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

void	close_and_free(int fd, char *line)
{
	get_next_line(fd, 1);
	if (fd >= 0)
		close(fd);
	if (line)
		free_and_null1(&line);
}

void	set_firstload(t_map *map)
{
	if (map->first_load == 1)
		map->first_load = 0;
}
