/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:59:30 by dzhakhan          #+#    #+#             */
/*   Updated: 2024/07/22 11:46:21 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strncpy(char *d, char *s, int l);
char	*ft_strcat(char *d, char *s);
char	*ft_strchr(char	*s, char c);
int		ft_strlen(char *s);
void	ft_free(char **a);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21
# endif

#endif