/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:08:40 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/16 00:40:01 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/**********************\
 *	LIBRARIES
\**********************/

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>

# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../MLX/mlx.h"

# include "../LIBFT/INCLUDES/libft.h"
# include "../LIBFT/INCLUDES/ft_printf.h"
# include "structs.h"
# include "defines.h"
# include "colors.h"

/**********************\
 *	PARSING
\**********************/

// utils.c
bool			is_empty_line(char *line);
size_t			get_longest_line(char **map2d, size_t height);
unsigned int	convert_rgb_into_uint(char *red, char *green, char *blue);

// CHECKS/check_arg.c
int				check_cub_file(char *arg);

// CHECKS/check_xpm.c
short			check_textures_paths(t_textures *tex);

// CHECKS/check_map.c
bool			is_map_line(char *line);
bool			map_fully_enclosed(char **map, size_t height, size_t width,
	t_point *pos);

// CHECKS/player_dir.c
void			get_player_direction(t_map *map, t_player *player);

// PROCESS_FILE/textures.c
short			check_textures_paths(t_textures *tex);
void			process_texture_lines(char *line, t_textures *tex);

// PROCESS_FILE/rgb.c
void			process_color_lines(char *line, t_data *data);

// PROCESS_FILE/map.c
char			**normalize_map2d(char **map, size_t height, size_t width);
void			fill_map2d_array(t_map *map, char *line);

// PROCESS_FILE/get_file_data.c
void			get_file_data(int fd, t_data *data);

// parsing.c
short			parsing(char *arg, t_data *data, t_game *game);

/**********************\
 *	TOOLS
\**********************/

// err_msg.c
void		err_msg(char *context, char *reason);
void		err_msg_quoted(char *context, char *reason);

// secure.c
void		secure_malloc(void *to_secure, bool full_clean);
void		my_free(void **to_free);

// draw_tools.c
void		swap_point(t_point *p0, t_point *p1);
bool		valid_point(t_point point, size_t win_x, size_t win_y);

// formulas.c
float		degree_to_radian(int degree);
float		square(float to_square); // pas utilise
float		norm_rad_angle(float angle);
int			norm_h_angle(int angle);

// CLEANUP/free.c
void		free_map(t_map *map);
void		free_array(char **array);
void		free_int_array(int **array);
void		free_title_screen(t_title_screen *screen);

// CLEANUP/delete_img.c
void		del_img(t_mlx *mlx, void *img_ptr);

// CLEANUP/cleanup.c
int			exit_game(t_mlx *mlx, int exit_code);
void		free_mlx(t_mlx *mlx);
void		clean_exit(int exit_code);

/**********************\
 *	GARBAGE
\**********************/
 
// lst_utils.c
int			remove_gc_node(t_gc_lst**yama, void *ptr);
void		add_gc_node(t_gc_lst **yama, t_gc_lst *node);
void		*new_gc_node(void *ptr, bool is_array);
 
// utils.c
void		*search_ptr(t_gc_lst **yama, void *ptr);
int			handle_remove(t_gc_lst **yama, void *ptr);
int			free_gc_array(t_gc_lst **y, char **array);
 
// garbage_collector.c
void		*yama(int flag, void *ptr, size_t size);

/**********************\
 *	INIT
\**********************/

// TITLE_SCREEN/layers.c
void		background(t_title_screen *s);
void		start_button(t_title_screen *s);
void		controls_menu(t_title_screen *s);

// TITLE_SCREEN/init.c
void		init_title_screen(t_title_screen *screen);
void		draw_title_screen(t_game *game, t_mlx *mlx);

// singletons.c
t_mlx		*mlx_s(void);
t_game		*game_s(void);
t_data		*data_s(void);

// init_mlx.c
void		init_mlx(t_mlx *mlx, t_game *game);

// init_textures.c
void		init_textures(t_textures *tex, t_data *data);
void		fill_textures_paths(char *line, t_textures *tex);

// init_minimap.c
int			init_minimap_img(t_mlx *mlx, t_minimap *mini);

// init_structs.c
void		init_map2(t_map *map, char *path_to_file, int fd, t_data *data);
void		init_structs(t_data *data, t_game *game, t_mlx *mlx);

/**********************\
 *	MLX_HOOKS
\**********************/

// movements.c
void		move_forward(t_game *game);
void		move_backward(t_game *game);
void		straf_leftward(t_game *game);
void		straf_rightward(t_game *game);

// camera.c
void		rotate_leftward(t_game *game);
void		rotate_rightward(t_game *game);

// move_array.c
void		move_player(t_game *game, t_keys *key);
void		reset_move(t_player *player);

// mouse.c
void		set_mouse_hooks(t_mlx *mlx, t_game *game);

// setter.c
void		set_hooks(t_mlx *mlx, t_game *game);

/**********************\
 *	EXEC
\**********************/

// map_info.c
void		get_map_info(t_map *m);

// collisions.c
int			handle_collisions(t_data *data, t_player *player, t_point *new_player_pos);

// pixels.c
void		my_pixel_put_to_img(t_img *img, int color, int x, int y);
void		clear_img(t_img *img, size_t size_x, size_t size_y, int color);

// RENDER/xpm_to_mlx_img.c
t_img		xpm_to_mlx_img(char *relative_path);

// RENDER/draw_line.c
void		draw_line(t_img *img, t_point p0, t_point p1, int color);

// RENDER/draw_texture.c
void	draw_vline_texture(int start_y, int end_y, int *tex_buffer, t_raycasting *r);

// RENDER/raycasting.c
void		raycasting(t_data *d, t_player *player, t_raycasting *r);

// RENDER/render.c
int			render(t_game *game);

// MINIMAP/draw_player.c
void		draw_player(t_game *game, t_minimap *minimap, t_player *player);

// MINIMAP/init_minimap.c
int			init_minimap_img(t_mlx *mlx, t_minimap *minimap);

// MINIMAP/minimap.c
void		render_minimap(t_game *game, t_minimap *minimap);

// MINIMAP/NEW/viewport.c
t_viewport	compute_viewport(t_game *game, t_map *map, int view_half,
	size_t tile_size);
void		draw_viewport_walls(t_minimap *minimap, t_map *map);
void		draw_player_in_viewport(t_game *game, t_minimap *minimap);

// MINIMAP/NEW/init_minimap_v2.c
int			init_minimap_img_v2(t_mlx *mlx, t_minimap *minimap);

// MINIMAP/NEW/minimap_v2.c
void		draw_minimap_tile(t_minimap *minimap, t_point tile);
void		draw_miniplayer(t_minimap *minimap, t_point *relative);
void		render_minimap_v2(t_game *game, t_minimap *minimap);

#endif