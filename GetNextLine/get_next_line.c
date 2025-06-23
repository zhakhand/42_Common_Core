/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:59:21 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/07/22 11:32:42 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	char	*d;
	int		i;

	i = 0;
	d = (char *)malloc(ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

static char	*do_other_stuff(char **r)
{
	char	*l;

	l = NULL;
	if (ft_strlen(*r) > 0)
		l = ft_strdup(*r);
	ft_free(r);
	*r = NULL;
	if (!l)
		return (NULL);
	return (l);
}

static char	*do_something_different(char *n_l_p, char **r)
{
	int		l_l;
	char	*n_r;
	char	*l;

	l_l = (n_l_p - *r) + 1;
	l = malloc(l_l + 1);
	if (!l)
		return (ft_free(r), NULL);
	l = ft_strncpy(l, *r, l_l);
	l[l_l] = '\0';
	n_r = ft_strdup(n_l_p + 1);
	ft_free(r);
	if (!n_r)
		return (ft_free(&l), NULL);
	*r = n_r;
	return (l);
}

static char	*do_something(int fd, int *b_r, char *r)
{
	char	*t;
	char	*b;

	b = malloc(BUFFER_SIZE + 1);
	if (!b)
		return (ft_free(&r), NULL);
	*b_r = read(fd, b, BUFFER_SIZE);
	if (*b_r < 0)
		return (ft_free(&r), ft_free(&b), NULL);
	b[*b_r] = '\0';
	if (r)
	{
		t = malloc(ft_strlen(r) + *b_r + 1);
		if (!t)
			return (ft_free(&r), ft_free(&b), NULL);
		t = ft_strncpy(t, r, ft_strlen(r) + 1);
		t = ft_strcat(t, b);
		ft_free(&b);
		ft_free(&r);
		r = t;
		return (r);
	}
	r = ft_strdup(b);
	ft_free(&b);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*r;
	char		*l;
	int			b_r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		r = do_something(fd, &b_r, r);
		if (!r)
			return (NULL);
		l = ft_strchr(r, '\n');
		if (l)
		{
			l = do_something_different(l, &r);
			if (!l)
				return (NULL);
			return (l);
		}
		if (b_r < BUFFER_SIZE)
		{
			l = do_other_stuff(&r);
			return (l);
		}
	}
}

// int main(void)
// {
// 	int fd = open("foo.txt", O_RDWR);
// 	//int fd = 42;
// 	//int fd = 0;
// 	char	*line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	printf("%s", line);
// 	close(fd);
// 	return 0;
// }
