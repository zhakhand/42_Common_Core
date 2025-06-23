/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:58:14 by oshcheho          #+#    #+#             */
/*   Updated: 2025/06/17 17:35:40 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_and_null(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	res = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!res)
		return (free_and_null(&s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	return (free_and_null(&s1), res);
}

char	*get_left(char **buf)
{
	char	*left;
	char	*temp;
	size_t	i;

	i = 0;
	while ((*buf)[i] && (*buf)[i] != '\n')
		i++;
	if ((*buf)[i])
		i++;
	if (i == 0)
		return (NULL);
	left = ft_substr(*buf, 0, i);
	if (!left)
		return (free_and_null(buf), NULL);
	if (i == ft_strlen(*buf))
		return (free_and_null(buf), left);
	temp = *buf;
	*buf = ft_substr(*buf, i, ft_strlen(*buf) - i);
	free (temp);
	return (left);
}

char	*read_line(int fd, char *buf)
{
	int		chars_read;
	char	*tmp;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (free_and_null(&buf), NULL);
	chars_read = 1;
	while (!ft_strchr(buf, '\n') && chars_read != 0)
	{
		chars_read = read(fd, tmp, BUFFER_SIZE);
		if (chars_read < 0)
			return (free_and_null(&buf), free_and_null(&tmp), NULL);
		if (chars_read == 0)
			break ;
		tmp[chars_read] = '\0';
		buf = ft_strjoin(buf, tmp);
		if (!buf)
			return (free_and_null(&tmp), NULL);
	}
	return (free_and_null(&tmp), buf);
}

char	*get_next_line(int fd, int i)
{
	static char		*static_buf;

	if (i == 1)
	{
		free_and_null(&static_buf);
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buf = read_line(fd, static_buf);
	if (!static_buf)
		return (NULL);
	return (get_left(&static_buf));
}
