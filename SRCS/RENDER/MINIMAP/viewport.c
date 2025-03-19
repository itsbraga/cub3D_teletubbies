/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:36:56 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/19 03:28:44 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	Computes the viewport parameters for the minimap display
	The function:
	- Sets the view perimeter (4 tiles in each direction)
	- Calculates tile size to fit the minimap dimensions
	- Ensures tiles are square by using the minimum of width/height ratios
	- Centers the viewport by computing offsets
	- Total visible area is (2 * perimeter + 1) tiles square
*/
t_viewport	compute_viewport(t_minimap *mmap)
{
	t_viewport	vp;
	int			visible_tiles;

	vp.perimeter = 4;
	visible_tiles = (vp.perimeter * 2) + 1;
	mmap->tile_size = fmin((float)mmap->width / visible_tiles,
	(float)mmap->height / visible_tiles);
	vp.pixel_width = visible_tiles * mmap->tile_size;
	vp.pixel_height = visible_tiles * mmap->tile_size;
	vp.offset_x = (mmap->width - vp.pixel_width) / 2;
	vp.offset_y = (mmap->height - vp.pixel_height) / 2;
	return (vp);
}

void	draw_player_in_viewport(t_game *game, t_minimap *mmap)
{
	t_player	player_copy;
	t_point		center;

	player_copy = *(game->player);
	center.x = mmap->img.width / 2;
	center.y = mmap->img.height / 2;
	player_copy.pos.x = center.x;
	player_copy.pos.y = center.y;
	draw_player(mmap, &player_copy);
}
