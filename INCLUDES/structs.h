/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:31:53 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/15 17:52:56 by annabrag         ###   ########.fr       */
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
	int				tex_x;
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
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	unsigned int	feature_filled;
}				t_data;

typedef struct s_viewport
{
	int		start_tile_x;
	int		start_tile_y;
	int		end_tile_x;
	int		end_tile_y;
	int		width_tiles;
	int		height_tiles;
	int		pixel_width;
	int		pixel_height;
}				t_viewport;

typedef struct s_minimap
{
	t_viewport	vp;
	t_img		img;
	t_point		pos;
	size_t		tile_size;
}				t_minimap;

typedef struct s_game
{
	t_game_state	state;
	t_title_screen	title_screen;
	t_player		*player;
	t_raycasting	*ray;
	t_keys			*keys;
	t_minimap		*minimap;
	t_mlx			*mlx;
}				t_game;

#endif