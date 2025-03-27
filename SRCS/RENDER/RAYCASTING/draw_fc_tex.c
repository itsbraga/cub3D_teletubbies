/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fc_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:07:23 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/27 19:43:02 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fc_precalculations(t_raycasting *r, float ray_rad)
{
	float	fixed_angle;

	fixed_angle = norm_rad_angle(r->player_rad - ray_rad);
	r->ray_cos = cos(ray_rad);
	r->ray_sin = sin(ray_rad);
	r->fixed_angle_cos = cos(fixed_angle);
}

static void	__draw_floor_core(t_raycasting *r, t_fc_core *fc, int *tex_buffer)
{
	t_point	floor;
	t_img	*img;

	img = &s_mlx()->img;
	fc->dy = fc->curr_y - (WIN_HEIGHT / 2.0f);
	if (fc->dy == 0)
		return ;
	fc->row_dist = ((float)TILE_SIZE * WIN_HEIGHT) / (2.0f * fc->dy);
	fc->row_dist /= r->fixed_angle_cos;
	floor.x = s_game()->player->pos.x + fc->row_dist * r->ray_cos;
	floor.y = s_game()->player->pos.y + fc->row_dist * r->ray_sin;
	r->shadow_factor = calculate_shadow_factor(fc->row_dist);
	fc->tex_x = ((int)floor.x) & (TILE_SIZE - 1);
	fc->tex_y = ((int)floor.y) & (TILE_SIZE - 1);
	fc->color = tex_buffer[fc->tex_y * TILE_SIZE + fc->tex_x];
	fc->color = apply_shadow_factor(fc->color, r->shadow_factor);
	my_pixel_put_to_img(img, fc->color, r->curr_ray, fc->curr_y);
}

void draw_floor_texture(t_raycasting *r)
{
	int			tex_buffer[TILE_SIZE * TILE_SIZE];
	t_fc_core	fc;

	handle_fc_tex_buffer(F, tex_buffer);
	ft_bzero(&fc, sizeof(t_fc_core));
	fc.curr_y = r->wall_end_y;
	while (fc.curr_y <= WIN_HEIGHT)
	{
		__draw_floor_core(r, &fc, tex_buffer);
		fc.curr_y++;
	}
}

static void	__draw_ceiling_core(t_raycasting *r, t_fc_core *fc, int *tex_buffer)
{
	t_point ceiling;
	t_img	*img;

	img = &s_mlx()->img;
	fc->dy = (WIN_HEIGHT / 2.0f) - fc->curr_y;
	if (fc->dy == 0)
		return ;
	fc->row_dist = ((float)TILE_SIZE * WIN_HEIGHT) / (2.0f * fc->dy);
	fc->row_dist /= r->fixed_angle_cos;
	ceiling.x = s_game()->player->pos.x + fc->row_dist * r->ray_cos;
	ceiling.y = s_game()->player->pos.y + fc->row_dist * r->ray_sin;
	r->shadow_factor = calculate_shadow_factor(fc->row_dist);
	fc->tex_x = ((int)ceiling.x) & (TILE_SIZE - 1);
	fc->tex_y = ((int)ceiling.y) & (TILE_SIZE - 1);
	fc->color = tex_buffer[fc->tex_y * TILE_SIZE + fc->tex_x];
	fc->color = apply_shadow_factor(fc->color, r->shadow_factor);
	my_pixel_put_to_img(img, fc->color, r->curr_ray, fc->curr_y);
}

void draw_ceiling_texture(t_raycasting *r)
{
	int			tex_buffer[TILE_SIZE * TILE_SIZE];
	t_fc_core	fc;

	handle_fc_tex_buffer(C, tex_buffer);
	ft_bzero(&fc, sizeof(t_fc_core));
	fc.curr_y = 0;
	while (fc.curr_y <= r->wall_start_y)
	{
		__draw_ceiling_core(r, &fc, tex_buffer);
		fc.curr_y++;
	}
}
