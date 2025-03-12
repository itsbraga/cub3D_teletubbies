/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:35:26 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/12 18:14:09 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_pixel_put_to_img(t_img *img, int color, int x, int y)
{
	int	pixel;

	pixel = (y * img->size_line) + (x * 4);
	if (img->endian == 0)
	{
		img->addr[pixel] = (color) & 0xFF;
		img->addr[pixel + 1] = (color >> 8) & 0xFF;
		img->addr[pixel + 2] = (color >> 16) & 0xFF;
		img->addr[pixel + 3] = (color >> 24) & 0xFF;
	}
	else if (img->endian == 1)
	{
		img->addr[pixel] = (color >> 24);
		img->addr[pixel + 1] = (color >> 16) & 0xFF;
		img->addr[pixel + 2] = (color >> 8) & 0xFF;
		img->addr[pixel + 3] = (color) & 0xFF;
	}
}

void	clear_img(t_img *img, size_t size_x, size_t size_y, int color)
{
	t_point	pixel;

	if (img->addr == NULL)
		return ;
	pixel.y = 0;
	while (pixel.y < size_y)
	{
		pixel.x = 0;
		while (pixel.x < size_x)
		{
			my_pixel_put_to_img(img, color, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
	return ;
}
