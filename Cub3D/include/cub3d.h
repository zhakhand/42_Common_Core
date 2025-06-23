/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhakhan <dzhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:25:04 by dzhakhan          #+#    #+#             */
/*   Updated: 2025/06/13 17:25:04 by dzhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H
//# include "../utils/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <fcntl.h>
# include <stddef.h>
//# include "../minilibx-linux/mlx.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include <math.h>

/*   SCREEN WIDTH  */
# define WIDTH 1280
/*   SCREEN HEIGHT */
# define HEIGHT 720

/*   RAYCASTING UTILS   */
# define PI  3.141592653589
# define MINIMAP_SIZE 200
# define TILE_SIZE 10
# define FOV_RADIUS 10

# define WML "Wrong map line\n"
# define FLM "Failed to load map\n"
# define USAGE "Usage: ./cub3d <map.cub>\n"
# define PLERROR "Map or Player error\n"

typedef struct s_triangle
{
	int		x[3];
	int		y[3];
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		delta_x;
	int		delta_y;
	int		step_x;
	int		step_y;
	int		err_term;
	double	angles[3];
}				t_triangle;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct s_map
{
	int		fd;
	int		first_load;
	int		width;
	int		height;
	int		start_x;
	int		start_y;
	char	*n_texture;
	char	*s_texture;
	char	*e_texture;
	char	*w_texture;
	t_color	f_color;
	t_color	c_color;
	char	**map;
}				t_map;

typedef struct s_player
{
	double			x;
	double			y;
	double			move_x;
	double			move_y;
	bool			moving;
	char			dir;
	double			angle;
	double			speed;
	double			angle_speed;
	double			cos_angle;
	double			sin_angle;
	bool			fwd;
	bool			back;
	bool			left;
	bool			right;
	bool			turn_left;
	bool			turn_right;
}				t_player;

typedef struct s_ray
{
	int					start_y;
	int					end_y;
	int					map_x;
	int					map_y;
	int					screen_x;
	int					screen_y;
	int					center_x;
	int					center_y;
	double				screen_pos;
	double				eye_level;
	double				epsilon;
	double				x;
	double				prev_x;
	double				y;
	double				prev_y;
	double				angle;
	double				cos_angle;
	double				sin_angle;
	double				step;
	double				distance;
	double				hit_x;
	double				hit_y;
	bool				hit_vert;
	struct s_texture	*wall;
	int					wall_x;
	int					wall_y;
	double				wall_height;
	double				tex_pos;
	double				tex_scale;
	double				tex_offset;
}				t_ray;

typedef struct s_texture
{
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
}				t_texture;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}				t_mlx;

typedef struct s_game
{
	bool		frame_up;
	int			light;
	int			frame;
	int			map_err;
	double		dist_left;
	double		dist_right;
	double		dist_top;
	double		dist_bottom;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_map		*map;
	t_player	*player;
	t_texture	*n_texture;
	t_texture	*s_texture;
	t_texture	*e_texture;
	t_texture	*w_texture;
	t_texture	*hand;
}				t_game;

/*    INITIALIZERS         */
int		init_map(t_map *map, char *map_path);
int		init_mlx(t_game *game);
int		init_game(t_game *game);
void	init_player(t_game *game);
int		gameplay(t_game *game);

/*   PLAYER AND MOVEMENT      */
int		put_player(t_map *map, t_player *player);
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
int		move_player(t_game *game);
int		move_fwd(t_game *game);
int		move_back(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);

/*   DRAWING   */
void	draw_ceiling(t_ray *ray, t_game *game);
void	draw_floor(t_ray *ray, t_game *game);
void	draw_minimap(t_game *game, t_ray *ray);
void	draw_player_triangle(t_game *game, int center_x, \
							int center_y, double angle);
void	draw_hand(t_game *game);
void	ft_put_pixel(int x, int y, int color, t_game *game);
int		get_color(t_color *color, int y_pos);
int		get_texture_color(t_texture *tex, int tex_x, int tex_y);
int		apply_brightness(t_ray *ray, int color, t_game *game);

/*    RAYCASTING   */
int		cast_rays(t_game *game);
bool	touch(double ray_x, double ray_y, t_game *game);
void	calculate_hit(t_ray *ray, t_game *game);

/*    UTILS       */
void	ft_putstr_fd(char *s, int fd);
char	*ft_strcpy(char *src);
char	*get_next_line(int fd, int i);

/*     CLOSING     */
void	free_map(t_map *map);
void	err(t_map *map, char *msg);
int		close_prog(t_game *game);
void	end_prog(t_game *game, char *msg);

/*     MAP PROCESSING   */
int		check_map(t_map *map);
int		set_textures(t_map *map, char *line);
int		check_if_empty_line(char *line);
int		check_if_var(char *line, t_map *map, int fd);
int		init_map1(t_map *map, char *map_path);
int		sanitize_line(char *line);
int		first_checks(t_map *map, char *map_path);
int		check_if_map_line(char *line);
int		init_map_field(t_map *map);
int		fill_line(t_map *map, char *line, int i);
int		set_n_texture(t_map *map, char *line, char **split, char *line1);
int		set_s_texture(t_map *map, char *line, char **split, char *line1);
int		set_e_texture(t_map *map, char *line, char **split, char *line1);
int		set_w_texture(t_map *map, char *line, char **split, char *line1);
int		remove_empty_lines(t_map *map);
int		process_textures(t_map *map, char *line);
int		process_colors(t_map *map, char *line);
int		check_if_all_vars_set(char *line, t_map *map, int fd);
int		check_vars(t_map *map);
void	free_split(char **split);
void	set_width_and_height(t_map *map, char *line);
void	fill_with_ones(t_map *map);
void	close_and_free(int fd, char *line);
void	set_firstload(t_map *map);
char	**remove_line(char **map, int index);

#endif
