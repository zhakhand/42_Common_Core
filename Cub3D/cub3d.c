/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:21:57 by oshcheho          #+#    #+#             */
/*   Updated: 2025/06/18 11:21:57 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	ft_print_map(t_game *game)
{
	int	i;

	i = 0;
	printf("Map preview:\n");
	while (game->map->map[i])
	{
		printf("%s\n", game->map->map[i]);
		i++;
	}
	printf("Map width: %d\n", game->map->width);
	printf("Map height: %d\n", game->map->height);
	printf("n_texture: %s\n", game->map->n_texture);
	printf("s_texture: %s\n", game->map->s_texture);
	printf("w_texture: %s\n", game->map->w_texture);
	printf("e_texture: %s\n", game->map->e_texture);
	printf("f_color: %d %d %d\n", game->map->f_color.r, \
		game->map->f_color.g, game->map->f_color.b);
	printf("c_color: %d %d %d\n", game->map->c_color.r, \
		game->map->c_color.g, game->map->c_color.b);
	printf("player_x: %f\n", game->player->x);
	printf("player_y: %f\n", game->player->y);
	printf("player_dir_x: %c\n", game->player->dir);
}

void	free_map_field(char ***map)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while ((*map)[i])
		free((*map)[i++]);
	free(*map);
	*map = NULL;
	exit(1);
}

int	gameplay(t_game *game)
{
	move_player(game);
	cast_rays(game);
	return (0);
}

void	main_mlx_helper(t_game *game)
{
	init_player(game);
	init_game(game);
	ft_print_map(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, \
		&close_prog, game);
	mlx_loop_hook(game->mlx_ptr, gameplay, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game		*game;
	t_map		*map;
	t_player	*player;

	if (argc != 2)
		return (ft_putstr_fd(USAGE, 2), 1);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (2);
	if (!init_map1(map, argv[1]))
		return (ft_putstr_fd(FLM, 2), free_map(map), 1);
	if (!check_map(map))
		return (ft_putstr_fd(FLM, 2), free_map(map), 1);
	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		return (free_map(map), 2);
	if (put_player(map, player) != 1)
		return (free(player), err(map, PLERROR), 0);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (free_map(map), free(player), 2);
	game->player = player;
	game->map = map;
	main_mlx_helper(game);
	return (0);
}
