/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:39:37 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/28 01:05:30 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	Draws a single tile (wall) in the minimap with borders
	@param tile: position of the tile in the viewport coordinates
	The function creates a bordered tile where:
	- The border is 1/8th of the tile size
	- The border is drawn in gray
	- The inside of the tile is white
*/
static void	__draw_tile(t_minimap *mmap, t_point tile, int color)
{
	t_point	pixel;
	size_t	x_end;
	size_t	y_end;
	int		wall_border;

	wall_border = mmap->tile_size / 8;
	pixel.x = mmap->vp.offset_x + (tile.x * mmap->tile_size);
	pixel.y = mmap->vp.offset_y + (tile.y * mmap->tile_size);
	x_end = pixel.x + mmap->tile_size - wall_border;
	y_end = pixel.y + mmap->tile_size - wall_border;
	while (pixel.y < y_end)
	{
		pixel.x = mmap->vp.offset_x + (tile.x * mmap->tile_size);
		while (pixel.x < x_end)
		{
			if (pixel.x == mmap->vp.offset_x + (tile.x * mmap->tile_size) ||
				pixel.y == mmap->vp.offset_y + (tile.y * mmap->tile_size))
				my_pixel_put_to_img(&mmap->img, GRAY_PIX, pixel.x, pixel.y);
			else
				my_pixel_put_to_img(&mmap->img, color, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

/*
	Determines and draws all visible walls around the player
	The function:
	- Centers the view on the player's position
	- Checks a square area of (2 * perimeter + 1) tiles around the player
	- Draws only walls ('1') or doors ('2') that are within map boundaries
*/
static void	__draw_visible_tiles(t_minimap *mmap, t_map *map)
{
	t_point	tile_in_viewport;
	int		x;
	int		y;
	int		center_x;
	int		center_y;

	center_x = (int)(s_game()->player->pos.x / TILE_SIZE);
	center_y = (int)(s_game()->player->pos.y / TILE_SIZE);
	y = center_y - mmap->vp.perimeter - 1;
	while (++y <= center_y + mmap->vp.perimeter)
	{
		x = center_x - mmap->vp.perimeter - 1;
		while (++x <= center_x + mmap->vp.perimeter)
		{
			if (is_within_map_bounds(x, y, map) == false)
				break;
			if (map->map2d[y][x] == '1' || map->map2d[y][x] == '2')
			{
				mmap->color = set_mmap_tile_color(map->map2d[y][x]);
				tile_in_viewport.x = x - (center_x - mmap->vp.perimeter);
				tile_in_viewport.y = y - (center_y - mmap->vp.perimeter);
				__draw_tile(mmap, tile_in_viewport, mmap->color);
			}
		}
	}
}

static void	__draw_minimap(t_minimap *mmap, t_map *map)
{
	mmap->vp = compute_viewport(mmap);
	__draw_visible_tiles(mmap, map);
	draw_player_in_viewport(s_game(), mmap);
	draw_minimap_frame(mmap);
}

void	render_minimap(t_game *game, t_minimap *mmap)
{
	t_img	*temp;
	clear_img(&mmap->cache, mmap->width, mmap->height, GRAY_PIX);
	__draw_minimap(mmap, game->data->map);
	draw_player_in_viewport(game, mmap);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		mmap->cache.img_ptr, mmap->pos.x, mmap->pos.y);
	temp = &mmap->img;
	mmap->img = mmap->cache;
	mmap->cache = *temp;
}
