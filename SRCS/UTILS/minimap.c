/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 00:58:19 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/28 01:02:57 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	set_mmap_tile_color(char c)
{
	if (c == '1')
		return (WHITE_PIX);
	else
		return (MANDARINE_PIX);
}

/*
	Draws a decorative frame around the minimap
	- Has a thickness of 2 pixels
	- Is drawn in x color
	- Surrounds the entire minimap area
*/
void	draw_minimap_frame(t_minimap *mmap)
{
	int	x;
	int	y;
	int	thickness;

	thickness = 2;
	y = 0;
	while (y < mmap->height)
	{
		x = 0;
		while (x < mmap->width)
		{
			if (y < thickness || y >= mmap->height - thickness ||
				x < thickness || x >= mmap->width - thickness)
				my_pixel_put_to_img(&mmap->img, RED_PIX, x, y);
			x++;
		}
		y++;
	}
}
