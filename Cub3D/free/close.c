/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:12:55 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/06/18 12:28:18 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	destroy_tex(t_game *game)
{
	if (game->n_texture && game->n_texture->img)
	{
		mlx_destroy_image(game->mlx_ptr, game->n_texture->img);
		free(game->n_texture);
	}
	if (game->e_texture && game->e_texture->img)
	{
		mlx_destroy_image(game->mlx_ptr, game->e_texture->img);
		free(game->e_texture);
	}
	if (game->w_texture && game->w_texture->img)
	{
		mlx_destroy_image(game->mlx_ptr, game->w_texture->img);
		free(game->w_texture);
	}
	if (game->s_texture && game->s_texture->img)
	{
		mlx_destroy_image(game->mlx_ptr, game->s_texture->img);
		free(game->s_texture);
	}
	if (game->hand && game->hand->img)
	{
		mlx_destroy_image(game->mlx_ptr, game->hand->img);
		free(game->hand);
	}
}

int	close_prog(t_game *game)
{
	if (!game)
		exit(0);
	if (game->player)
		free(game->player);
	if (game->mlx_ptr)
	{
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->img)
			mlx_destroy_image(game->mlx_ptr, game->img);
		destroy_tex(game);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->map)
		free_map(game->map);
	free(game);
	exit(0);
}

void	end_prog(t_game *game, char *msg)
{
	perror(msg);
	close_prog(game);
}
