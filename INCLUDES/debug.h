/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 03:48:47 by marvin            #+#    #+#             */
/*   Updated: 2025/03/21 03:48:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "cub3D.h"

/**********************\
 *	DEBUG
\**********************/

// raycasting.c
void		inter_hline(t_data *d, t_player *player, t_raycasting *r,
	float ray_rad);
void		inter_vline(t_data *d, t_player *player, t_raycasting *r,
	float ray_rad);
void		find_closest_inter(t_player *player, t_raycasting *r,
	t_point *closest_inter);

// draw_grid.c
void		draw_grid(t_mlx *mlx, float scale, t_map *map);

// triangle_utils.c
void		draw_hline_2d(t_mlx *mlx, t_triangle *tr, int start_y, int end_y,
int color);

// draw_triangle.c
void		fill_triangle_2d(t_mlx *mlx, t_point a, t_point b, t_point c,
	int color);
void		init_triangle_2d(t_triangle *tr, t_point a, t_point b, t_point c);

// draw_player_2d.c
void		draw_player_2d(t_mlx *mlx, t_player *player);

// raycasting_2d.c
float		compute_scale_factor(t_map *map);
t_point		scale_point(t_point p, float scale);
void		raycasting_2d(t_data *d, t_player *player, t_raycasting *r,
	float scale);

// render_2d.c
int		render_2d(t_game *game);

#endif
