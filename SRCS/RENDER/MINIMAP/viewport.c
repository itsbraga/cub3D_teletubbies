/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:36:56 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/17 23:23:03 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_viewport	compute_viewport(t_minimap *mmap, int zone_width, int zone_height)
{
	t_viewport	vp;

	vp.scale_x = (float)mmap->width / zone_width;
    vp.scale_y = (float)mmap->height / zone_height;
    if (vp.scale_x < vp.scale_y)
		mmap->tile_size = vp.scale_x;
	else
		mmap->tile_size = vp.scale_y;
	vp.pixel_width = zone_width * mmap->tile_size;
	vp.pixel_height = zone_height * mmap->tile_size;
	vp.offset_x = (mmap->width - vp.pixel_width) / 2;
	vp.offset_y = (mmap->height - vp.pixel_height) / 2;
	return (vp);
}

void	draw_player_in_viewport(t_game *game, t_minimap *mmap)
{
	t_player	player_copy;

	player_copy = *(game->player);
	player_copy.pos.x = mmap->img.width / 2;
	player_copy.pos.y = mmap->img.height / 2;
	draw_player(mmap, &player_copy);
}
