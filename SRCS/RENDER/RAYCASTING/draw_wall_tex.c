/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:24:45 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/27 19:42:16 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__draw_wall_texture(int start_y, int end_y, int *tex_buffer,
t_raycasting *r)
{
	int 	curr_y;
	int 	tex_y;
	float	accumulator_tex_y;
	int 	color;
	t_img	*img;

	curr_y = start_y;
	accumulator_tex_y = r->offset_tex_y * r->step_tex_y;
	img = &s_mlx()->img;
	while (curr_y <= end_y)
	{
		r->shadow_factor = calculate_shadow_factor(r->dist_wall);
		tex_y = (int)accumulator_tex_y & (TILE_SIZE - 1);
		accumulator_tex_y += r->step_tex_y;
		color = tex_buffer[tex_y * TILE_SIZE + r->tex_x];
		color = apply_shadow_factor(color, r->shadow_factor);
		my_pixel_put_to_img(img, color, r->curr_ray, curr_y);
		curr_y++;
	}
	return ; 
}

void	draw_wall(t_raycasting *r, float ray_rad)
{
	int		tex_buffer[TILE_SIZE * TILE_SIZE];
	float	fixed_angle;

	fixed_angle = norm_rad_angle(r->player_rad - ray_rad);
	r->dist_wall *= cos(fixed_angle);
	r->wall_h = (TILE_SIZE * WIN_HEIGHT) / r->dist_wall;
	r->offset_tex_y = 0;
	r->step_tex_y = TILE_SIZE / r->wall_h;
	if (r->wall_h > WIN_HEIGHT)
	{
		r->offset_tex_y = (r->wall_h - WIN_HEIGHT) / 2.0f;
		r->wall_h = WIN_HEIGHT;
	}
	r->wall_start_y = (WIN_HEIGHT / 2) - (r->wall_h / 2);
	r->wall_end_y = r->wall_start_y + r->wall_h;
	handle_tex_buffer(tex_buffer, r, ray_rad);
	__draw_wall_texture(r->wall_start_y, r->wall_end_y, tex_buffer, r);
	return ;
}
