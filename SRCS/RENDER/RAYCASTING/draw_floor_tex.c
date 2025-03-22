/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:16:52 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/22 02:07:48 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	__compute_ray_dirs(float ray_left_rad, float ray_right_rad,
// t_point *left, t_point *right)
// {
// 	left->x = cosf(ray_left_rad);
// 	left->y = sinf(ray_left_rad);
// 	right->x = cosf(ray_right_rad);
// 	right->y = sinf(ray_right_rad);
// }

// static float	__get_row_distance(int y)
// {
// 	int	p;

// 	p = y - WIN_HEIGHT / 2;
// 	if (p == 0)
// 		return (0.0f);
// 	return (0.5f * WIN_HEIGHT) / p;
// }

// static t_point	__interpolate_floor_offset(int x, float row_dist,
// t_point dir_left, t_point dir_right)
// {
// 	t_point	offset;
// 	t_point step;
	
// 	step.x = row_dist * (dir_right.x - dir_left.x) / WIN_WIDTH;
// 	step.y = row_dist * (dir_right.y - dir_left.y) / WIN_WIDTH;
// 	offset.x = row_dist * dir_left.x + step.x * x;
// 	offset.y = row_dist * dir_left.y + step.y * x;
// 	return (offset);
// }

// static t_point	__get_tex_coords(float floor_x, float floor_y)
// {
// 	t_point	tex;
// 	int		cell_x;
// 	int		cell_y;

// 	cell_x = (int)floor_x;
// 	cell_y = (int)floor_y;
// 	tex.x = (int)(TILE_SIZE * (floor_x - cell_x)) & (TILE_SIZE - 1);
// 	tex.y = (int)(TILE_SIZE * (floor_y - cell_y)) & (TILE_SIZE - 1);
// 	return (tex);
// }

// void	draw_floor_texture(int *tex_buffer, t_raycasting *r, t_player *player)
// {
// 	t_img	*img;
// 	float	shadow_factor;
// 	int		curr_y;
// 	int		curr_x;
// 	float	row_distance;
// 	t_point	offset;
// 	t_point	floor;
// 	int 	color;
// 	t_point	world_dir;
// 	t_point	dir_left, dir_right;
// 	t_point tex;

// 	img = &s_mlx()->img;
// 	__compute_ray_dirs(ray_left_rad, ray_right_rad, &dir_left, &dir_right);
// 	curr_x = r->curr_ray;
// 	curr_y = r->wall_end_y;
// 	while (curr_y <= WIN_HEIGHT)
// 	{
// 		row_distance = get_row_distance(curr_y);
// 		if (row_distance == 0)
// 			continue;
// 		offset = __interpolate_floor_offset(curr_x, row_distance,
// 			dir_left, dir_right);

// 		floor.x = player->pos.x + offset.x;
// 		floor.y = player->pos.y + offset.y;

// 		shadow_factor = calculate_shadow_factor(row_distance);
// 		tex = __get_tex_coords(floor.x, floor.y);
// 		color = tex_buffer[(int)tex.y * TILE_SIZE + (int)tex.x];
// 		color = apply_shadow_factor(color, shadow_factor);
// 		my_pixel_put_to_img(img, color, curr_x, curr_y);
// 		curr_y++;
// 	}
// 	return ;
// }

// void draw_floor_texture(float wall_h, int *tex_buffer, int curr_x)
// {
// 	int		curr_y;
// 	int		start_y;
// 	int		tex_x;
// 	int		tex_y;
// 	int		color;
// 	float	shadow_factor;
// 	t_img	*img;

// 	curr_y = (WIN_HEIGHT + wall_h) / 2;
// 	start_y = curr_y;
// 	color = 0;
// 	img = &s_mlx()->img;
// 	while (curr_y <= WIN_HEIGHT)
// 	{
// 		shadow_factor = calculate_shadow_factor(dist);
// 		tex_x = curr_x & (TILE_SIZE - 1);
// 		tex_y = (curr_y - start_y) & (TILE_SIZE - 1);
// 		color = tex_buffer[tex_y * TILE_SIZE + tex_x];
// 		color = apply_shadow_factor(color, shadow_factor);
// 		my_pixel_put_to_img(img, color, curr_x, curr_y);
// 		curr_y++;
// 	}
// }
