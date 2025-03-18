/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:31:53 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/18 01:30:34 by pmateo           ###   ########.fr       */
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
	float		x;
	float		y;
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

typedef struct s_triangle
{
	t_point		a;
	t_point		b;
	t_point		c;
	float		theta;
}				t_triangle;

typedef struct	s_weapon
{
	int			id;
	int			xpm_nb;
	t_img		*sprites;
	int			state;
	int			frame_counter;
	t_point		pos;
}				t_weapon;

typedef	struct	s_ennemy
{
	int 	id;
	t_img 	*sprites;
	float 	hp;
	// behaviour struct
}				t_ennemy;


typedef struct s_player
{
	int			dir;
	t_point		pos;
	t_point		move;
	// int			pitch; // garder si mouse_y OK
}				t_player;

typedef struct s_raycasting
{
	t_point			h_ray_inter;
	t_point			v_ray_inter;
	t_point			h_offset;
	t_point			v_offset;
	unsigned int	curr_ray;
	float			dist_wall;
	int				wall_h;
	int				tex_x;
	float			step_tex_y;
	float			off_tex_y;
	float			shadow_factor;
	bool			vertical_hit;
	unsigned int	fov;
	float			player_rad;
}				t_raycasting;

typedef	struct s_keys_event
{
	bool	key_array[6];
}				t_keys;

typedef struct s_textures
{
	char	*north; // remplacer par char *path
	char	*south;
	char	*west;
	char	*east;
	t_img	*imgs;
}				t_textures;

typedef struct s_data
{
	t_map			*map;
	t_textures		*textures;
	t_weapon		*weapon;
	t_ennemy		*ennemy;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	unsigned int	feature_filled;
}				t_data;

typedef struct s_viewport
{
	float	scale_x;
	float	scale_y;
	int		pixel_width;
	int		pixel_height;
	int		offset_x; // decalage pour centrer la carte
	int		offset_y;
}				t_viewport;

typedef struct s_minimap
{
	t_viewport	vp;
	t_img		img;
	t_point		pos;
	float		ratio;
	int			width;
	int			height;
	size_t		tile_size;
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
	// t_data			*data;
}				t_game;

#endif