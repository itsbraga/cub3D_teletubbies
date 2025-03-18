/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:24:45 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/17 23:41:35 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	apply_shadow_factor(int color, float shadow_factor)
{
	int color_shadowed;
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (int)(r * shadow_factor);
	g = (int)(g * shadow_factor);
	b = (int)(b * shadow_factor);
	color_shadowed = ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
	return (color_shadowed);
}

void	draw_vline_texture(int start_y, int end_y, int *tex_buffer, t_raycasting *r)
{
	int		curr_x;
	int 	curr_y;
	int 	tex_y;
	float	accumulator_tex_y;
	int 	color;
	t_img	*img;

	color = 0;
	curr_x = r->curr_ray;
	curr_y = start_y;
	accumulator_tex_y = r->off_tex_y * r->step_tex_y;
	img = &s_mlx()->img;
	while (curr_y <= end_y)
	{
		tex_y = (int)accumulator_tex_y & (TILE_SIZE -1);
		accumulator_tex_y += r->step_tex_y;
		color = tex_buffer[tex_y * TILE_SIZE + r->tex_x];
		color = apply_shadow_factor(color, r->shadow_factor);
		my_pixel_put_to_img(img, color, curr_x, curr_y);
		curr_y++;
	}
	return ; 
}
