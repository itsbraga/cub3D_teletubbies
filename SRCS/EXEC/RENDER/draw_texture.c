/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:24:45 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/15 19:24:23 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	img = &mlx_s()->img;
	while (curr_y <= end_y)
	{
		tex_y = (int)accumulator_tex_y & (TILE_SIZE -1);
		accumulator_tex_y += r->step_tex_y;
		color = tex_buffer[tex_y * TILE_SIZE + r->tex_x];
		my_pixel_put_to_img(img, color, curr_x, curr_y);
		curr_y++;
	}
	return ; 
}
