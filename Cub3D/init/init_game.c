/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:25:05 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/06/18 13:58:47 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_texture	*set_texture(t_game *game, char *dir)
{
	int			width;
	int			height;
	t_texture	*tex;

	tex = ft_calloc(1, sizeof(t_texture));
	if (!tex)
		end_prog(game, "error: malloc");
	tex->img = mlx_xpm_file_to_image(game->mlx_ptr, \
		dir, &width, &height);
	if (!tex->img)
		return (free(tex), NULL);
	tex->data = mlx_get_data_addr(tex->img, &tex->bpp, \
		&tex->size_line, &tex->endian);
	if (!tex->data)
		return (mlx_destroy_image(game->mlx_ptr, tex->img), free(tex), NULL);
	tex->width = width;
	tex->height = height;
	return (tex);
}

static void	load_textures(t_game *game)
{
	game->n_texture = set_texture(game, game->map->n_texture);
	if (!game->n_texture)
		end_prog(game, "error: Failed to load texture!");
	game->e_texture = set_texture(game, game->map->e_texture);
	if (!game->e_texture)
		end_prog(game, "error: Failed to load texture!");
	game->s_texture = set_texture(game, game->map->s_texture);
	if (!game->s_texture)
		end_prog(game, "error: Failed to load texture!");
	game->w_texture = set_texture(game, game->map->w_texture);
	if (!game->w_texture)
		end_prog(game, "error: Failed to load texture!");
	if (access("hand.xpm", F_OK))
		end_prog(game, "error: Could not access file!");
	game->hand = set_texture(game, "hand.xpm");
	if (!game->hand)
		end_prog(game, "error: Failed to load texture!");
}

int	init_game(t_game *game)
{
	game->frame_up = true;
	init_mlx(game);
	load_textures(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img, 0, 0);
	return (0);
}
