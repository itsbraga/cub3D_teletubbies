/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:16:54 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/27 23:44:07 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	load_tex_buffer(int orientation, int *tex_buffer)
{
	int		x;
	int		y;
	t_img	*tex_img;
	char	*pixel_addr;

	x = 0;
	y = 0;
	tex_img = &s_data()->textures->imgs[orientation];
	pixel_addr = NULL;
	while (y < TILE_SIZE)
	{
		while (x < TILE_SIZE)
		{
			pixel_addr = tex_img->addr  + ((y * tex_img->size_line) + (x * 4));
			tex_buffer[y * TILE_SIZE + x] = *(int *)pixel_addr;
			x++;
		}
		x = 0;
		y++;
	}
}

void	handle_tex_buffer(int *tex_buffer, t_raycasting *r, float ray_rad)
{
	ft_bzero(tex_buffer, TILE_SIZE * TILE_SIZE);
	if (r->is_door == true)
	{
		load_tex_buffer(D, tex_buffer);
		return ;
	}
	if (r->vertical_hit == false)
	{
		if (ray_rad > 0 && ray_rad < PI)
			load_tex_buffer(SO, tex_buffer);
		else if (ray_rad > PI2 && ray_rad < (2 * PI))
			load_tex_buffer(NO, tex_buffer);
	}
	else
	{
		if (ray_rad > PI2 && ray_rad < PI3)
			load_tex_buffer(WE, tex_buffer);
		else if (ray_rad < PI2 || ray_rad > PI3)
			load_tex_buffer(EA, tex_buffer);
	}
}

void	handle_fc_tex_buffer(int orientation, int *tex_buffer)
{
	ft_bzero(tex_buffer, TILE_SIZE * TILE_SIZE);
	if (orientation == F)
		load_tex_buffer(F, tex_buffer);
	else if (orientation == C)
		load_tex_buffer(C, tex_buffer);
}
