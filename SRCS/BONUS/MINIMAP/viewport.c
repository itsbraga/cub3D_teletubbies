/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:36:56 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/21 19:07:45 by annabrag         ###   ########.fr       */
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
	t_point		player_offset;
	t_point		precise_pos;

	player_copy = *(game->player);
	center.x = mmap->vp.offset_x + (mmap->vp.pixel_width / 2);
	center.y = mmap->vp.offset_y + (mmap->vp.pixel_height / 2);
	precise_pos.x = player_copy.pos.x / TILE_SIZE;
	precise_pos.y = player_copy.pos.y / TILE_SIZE;
	// Calculate the offset from the center based on the player's real position
	player_offset.x = (precise_pos.x - (int)(precise_pos.x)) * mmap->tile_size;
	player_offset.y = (precise_pos.y - (int)(precise_pos.y)) * mmap->tile_size;
	// Adjust the player's position to account for the offset within the tile
	player_copy.pos.x = center.x + player_offset.x - (mmap->tile_size / 2);
	player_copy.pos.y = center.y + player_offset.y - (mmap->tile_size / 2);
	draw_player(mmap, &player_copy);
}
