/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:24:45 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/14 21:32:02 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_vline_texture(int start_y, int end_y, int *tex_buffer, t_raycasting *r)
{
	float	step;
	int		curr_x;
	int 	curr_y;
	int 	tex_y;
	float	tex_y_accumulator;
	int 	color;
	t_img	*img;

	color = 0;
	tex_y_accumulator = 0.0f;
	step = (float)TILE_SIZE / (float)(end_y - start_y);
	curr_x = r->curr_ray;
	curr_y = start_y;
	img = &mlx_s()->img;
	while (curr_y <= end_y)
	{
		tex_y = (int)tex_y_accumulator & (TILE_SIZE -1);
		tex_y_accumulator += step;
		color = tex_buffer[tex_y * TILE_SIZE + r->tex_x];
		my_pixel_put_to_img(img, color, curr_x, curr_y);
		curr_y++;
	}
	return ; 
}
