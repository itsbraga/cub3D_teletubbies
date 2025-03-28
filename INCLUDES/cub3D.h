/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:08:40 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/28 00:59:07 by art3mis          ###   ########.fr       */
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
# include "debug.h"

/**********************\
 *	INIT
\**********************/

// singletons.c
t_data		*s_data(void);
t_game		*s_game(void);
t_mlx		*s_mlx(void);

// init_mlx.c
void		init_mlx(t_mlx *mlx, t_game *game);

// init_textures.c
void		init_textures(t_textures *tex, t_data *data);
void		fill_textures_paths(char *line, t_textures *tex);
void		fill_bonus_textures_paths(char *line, t_textures *tex);

// init_structs.c
void		init_map(t_map *map, char *path_to_file, int fd, t_data *data);
void		init_structs(t_data *data, t_game *game, t_mlx *mlx);

/**********************\
 *	PARSING
\**********************/

// utils.c
bool		is_empty_line(char *line);
size_t		get_longest_line(char **map2d, size_t height);
uint32_t	convert_rgb_into_uint(char *red, char *green, char *blue);

// CHECKS/check_arg.c
int			check_cub_file(char *arg);

// CHECKS/check_xpm.c
int			check_xpm_file(char *arg);

// CHECKS/check_tex_path.c
int			check_textures_paths(t_textures *tex);
int			check_bonus_textures_paths(t_textures *tex);

// CHECKS/check_map.c
bool		flood_fill(char **map, int y, int x, size_t height, size_t width);
char		**normalize_map_for_flood(char **map, size_t height, size_t width);

// CHECKS/check_player.c
void		get_player_direction(t_map *map, t_player *player);

// PROCESS_FILE/utils.c
char		*skip_spaces(char *line);
bool		is_wall_texture_line(char *trimmed);
bool		is_map_line(char *line);
bool		is_bonus_map_line(char *line);

// PROCESS_FILE/textures.c
void		process_texture_lines(char *line, t_textures *tex);
void		process_bonus_texture_lines(char *line, t_textures *tex);

// PROCESS_FILE/rgb.c
void		process_color_lines(char *line, t_data *data);

// PROCESS_FILE/map.c
char		**normalize_final_map(char **map, size_t height, size_t width);
void		fill_map2d_array(t_map *map, char *line);

// PROCESS_FILE/get_file_data.c
void		get_file_data(int fd, t_data *data);

// parsing.c
int			parsing(char *arg, t_data *data, t_game *game);

/**********************\
 *	UTILS
\**********************/

// err_msg.c
void		err_msg(char *context, char *reason);
void		err_msg_quoted(char *context, char *reason);

// secure.c
void		secure_malloc(void *to_secure, bool full_clean);
void		my_free(void **to_free);

// draw_utils.c
void		swap_point(t_point *p0, t_point *p1);
bool		is_valid_point(t_point point, size_t win_width, size_t win_height);
bool		is_within_map_bounds(int x, int y, t_map *map);
bool		is_door(t_data *data, t_point *p);

// minimap.c
int			set_mmap_tile_color(char c);
void		draw_minimap_frame(t_minimap *mmap);

// draw_line.c
void		draw_line(t_img *img, t_point p0, t_point p1, int color);

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
 *	TITLE_SCREEN
\**********************/

// title_screen_hooks.c
int			set_title_screen_keys(int keycode, t_game *game);
int			title_screen_mouse(int button, int x, int y, t_game *game);

// layers.c
void		background(t_title_screen *s);
void		start_button(t_title_screen *s);
void		controls_menu(t_title_screen *s);

// init.c
void		init_title_screen(t_title_screen *screen);
void		draw_title_screen(t_game *game, t_mlx *mlx);

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

// setter.c
void		set_hooks(t_mlx *mlx, t_game *game);

/**********************\
 *	RENDER
\**********************/

// xpm_to_mlx_img.c
t_img		xpm_to_mlx_img(char *relative_path);

// pixels.c
void		my_pixel_put_to_img(t_img *img, int color, int x, int y);
void		clear_img(t_img *img, size_t size_x, size_t size_y, int color);

// RAYCASTING/shadow.c
float		calculate_shadow_factor(float distance);
int			apply_shadow_factor(int color, float shadow_factor);

// RAYCASTING/tex_buffer.c
void		load_tex_buffer(int orientation, int *tex_buffer);
void		handle_tex_buffer(int *tex_buffer, t_raycasting *r, float ray_rad);
void		handle_fc_tex_buffer(int orientation, int *tex_buffer);

// draw_wall_tex.c
void		draw_wall(t_raycasting *r, float ray_rad);

// RAYCASTING/draw_fc_colors.c
void		draw_floor_color(t_raycasting *r, t_data *d);
void		draw_ceiling_color(t_raycasting *r, t_data *d);

// RAYCASTING/draw_fc_tex.c
void		fc_precalculations(t_raycasting *r, float ray_rad);
void 		draw_floor_texture(t_raycasting *r);
void		draw_ceiling_texture(t_raycasting *r);

// RAYCASTING/raycasting.c
void		raycasting(t_data *d, t_player *player, t_raycasting *r);

// render_frame.c
int			render_frame(t_game *game);

/*************************************************************\
 *	BONUS
\*************************************************************/

/**********************\
 *	COLLISIONS
\**********************/

// collisions.c
int			handle_collisions(t_data *data, t_player *player,
	t_point *new_ppos);

/**********************\
 *	MINIMAP
\**********************/

// init.c
void		init_minimap(t_minimap *mmap, t_game *game);

// triangle_utils.c
void		init_triangle(t_triangle *tr, t_point a, t_point b, t_point c);
void		draw_hline(t_minimap *mmap, t_triangle *tr, int start_y, int end_y,
	int color);

// draw_triangle.c
void		fill_triangle(t_minimap *mmap, t_point a, t_point b, t_point c,
int color);

// draw_player.c
void		draw_player(t_minimap *mmap, t_player *player);

// viewport.c
t_viewport	compute_viewport(t_minimap *mmap);
void		draw_player_in_viewport(t_game *game, t_minimap *mmap);

// render_minimap.c
void		render_minimap(t_game *game, t_minimap *mmap);

// zoom_handler.c
int			set_minimap_zoom_factor_keys(int keycode, t_game *game);

/**********************\
 *	MOUSE
\**********************/

// mouse_bonus.c
void		toggle_mouse_visibility(t_mlx *mlx, t_game_state state);
int			mouse_motion(int x, int y, t_game *game);

#endif