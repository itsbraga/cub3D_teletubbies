/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:07:23 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/22 02:07:52 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	draw_ceiling_texture(float wall_h, int *tex_buffer, int curr_x)
// {
// 	int 	curr_y;
// 	int		end_y;
// 	int		tex_x;
// 	int 	tex_y;
// 	int 	color;
// 	float	shadow_factor;
// 	t_img	*img;

// 	curr_y = 0;
// 	end_y = (WIN_HEIGHT - wall_h) / 2;
// 	color = 0;
// 	img = &s_mlx()->img;
// 	while (curr_y <= end_y)
// 	{
// 		shadow_factor = calculate_shadow_factor(dist);
// 		tex_x = curr_x & (TILE_SIZE - 1);	
// 		tex_y = curr_y & (TILE_SIZE - 1);
// 		color = tex_buffer[tex_y * TILE_SIZE + tex_x];
// 		color = apply_shadow_factor(color, shadow_factor);
// 		my_pixel_put_to_img(img, color, curr_x, curr_y);
// 		curr_y++;
// 	}
// 	return ; 
// }
