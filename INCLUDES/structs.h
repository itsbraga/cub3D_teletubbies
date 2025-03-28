/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:31:53 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/28 00:43:40 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/******************************************************************************\
 * YAMA: Garbage Collector
\******************************************************************************/

typedef struct s_gc_lst
{
	void			*ptr;
	bool			is_array;
	struct s_gc_lst	*next;
}				t_gc_lst;

/******************************************************************************\
 * GRAPHIC LIBRARY
\******************************************************************************/

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel; 
	int		size_line; // bits per line
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;

/******************************************************************************\
 * CUB3D
\******************************************************************************/

typedef enum e_game_state
{
	TITLE_SCREEN = 1,
	GAME = 2
}			t_game_state;

typedef struct s_point
{
	float	x;
	float	y;
}				t_point;

typedef struct s_layer
{
	t_point		pos;
	t_img		img;
	size_t		width;
	size_t		height;
}				t_layer;

typedef struct s_title_screen
{
	t_img		first_layer;
	t_layer		second_layer;
}				t_title_screen;

typedef struct s_map
{
	char		*path_to_file;
	int			fd;
	char		**map2d;
	size_t		height;
	size_t		width;
}				t_map;

typedef struct s_weapon
{
	int			id;
	int			xpm_nb;
	t_img		*sprites;
	int			state;
	int			frame_counter;
	t_point		pos;
}				t_weapon;

typedef	struct s_ennemy
{
	int 	id;
	t_img	*sprites;
	float	hp;
	// behaviour struct
}				t_ennemy;

typedef struct s_player
{
	int			dir;
	t_point		pos;
	t_point		move;
}				t_player;

typedef struct s_raycasting
{
	t_point		h_ray_inter;
	t_point		v_ray_inter;
	t_point		h_offset;
	t_point		v_offset;
	float		dist_wall;
	int			wall_start_y;
	int			wall_end_y;
	float		wall_h;
	int			tex_x;
	float		step_tex_y;
	float		offset_tex_y;
	float		shadow_factor;
	bool		vertical_hit;
	bool		is_door;
	float		player_rad;
	uint32_t	fov;
	uint32_t	curr_ray;
	float		ray_cos;
	float		ray_sin;
	float		fixed_angle_cos;
}				t_raycasting;

typedef	struct s_keys_event
{
	bool	key_array[6];
}				t_keys;

typedef struct s_fc_core
{
	int		curr_y;
	float	dy;
	float	row_dist;
	int		tex_x;
	int		tex_y;
	int		color;
}				t_fc_core;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	char	*door;
	t_img	*imgs;
}				t_textures;

typedef struct s_data
{
	t_map		*map;
	t_textures	*textures;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	uint32_t	feature_filled;
	t_weapon	*weapon;
	t_ennemy	*ennemy;
}				t_data;

typedef struct s_viewport
{
	float	scale_x;			// zoom factor
	float	scale_y;
	int		pixel_width;		// window width
	int		pixel_height;
	int		offset_x;			// offset to center the map
	int		offset_y;
	int		player_tile_x;		// player coordinates on minimap
	int		player_tile_y;
	int		perimeter;			// visible area on minimap
	int		start_x;			// starting coordinates of visible area
	int		start_y;
	int		end_x;				// ending coordinates of visible area
	int		end_y;
	int		zone_width;			// width of visible area
	int		zone_height;
	float	rotation_angle;		// minimap rotation angle
	float	zoom_factor;		// minimap zoom factor
}				t_viewport;

typedef struct s_trigo
{
	float	cos_theta;
	float	sin_theta;
	float	cos_theta_plus_pi2;
	float	sin_theta_plus_pi2;
	float	cos_theta_minus_pi2;
	float	sin_theta_minus_pi2;
}				t_trigo;

typedef struct s_triangle
{
	t_point		a;
	t_point		b;
	t_point		c;
	float		theta;			// line angle
	double		slope1;			// line slope (= pente)
	double		slope2;
	double		slope3;
	double		curr_x1;		// coordinates of point 1
	double		curr_x2;		// coordinates of point 2
	double		curr_slope1;
	double		curr_slope2;
	t_trigo		trig;
}				t_triangle;

typedef struct s_minimap
{
	t_viewport	vp;
	t_img		img;			// shown on screen
	t_img		cache;			// cached image
	t_point		pos;
	float		ratio;
	int			width;
	int			height;
	size_t		tile_size;
	int			color;
}				t_minimap;

typedef struct s_game
{
	t_game_state	state;
	t_title_screen	title_screen;
	t_player		*player;
	t_raycasting	*ray;
	t_keys			*keys;
	t_minimap		*mmap;
	t_mlx			*mlx;
	t_data			*data;
}				t_game;

#endif