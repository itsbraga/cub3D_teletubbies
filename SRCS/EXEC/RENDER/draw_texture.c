/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:24:45 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/11 19:08:06 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_vline_texture(int x, int start_y, int end_y, int *tex_buffer)
{
	int curr_y;
	int	tex_x;
	int tex_y;
	int color;
	t_img	*img;

	curr_y = start_y;
	color = 0;
	img = &mlx_s()->img;
	tex_x = x % TILE_SIZE;
	while (curr_y <= end_y)
	{
		tex_y = ((curr_y - start_y) * TILE_SIZE) / (end_y - start_y + 1);
		color = tex_buffer[tex_y * TILE_SIZE + tex_x];
		my_pixel_put_to_img(img, color, x, curr_y);
		curr_y++;
	}
	return ; 
}
