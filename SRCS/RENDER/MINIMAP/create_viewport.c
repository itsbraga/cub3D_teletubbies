/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_viewport.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:36:56 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/16 20:50:07 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__handle_viewport_map_limits(t_viewport *vp, t_map *map)
{
	if (vp->start_tile_x < 0)
		vp->start_tile_x = 0;
	if (vp->start_tile_y < 0)
		vp->start_tile_y = 0;
	if (vp->end_tile_x >= (int)map->width)
		vp->end_tile_x = map->width - 1;
	if (vp->end_tile_y >= (int)map->height)
		vp->end_tile_y = map->height - 1;
}

bool	__is_in_map_limits(int y, int x, t_map *map)
{
	if ((y >= 0 && y < (int)map->height) && (x >= 0 && x < (int)map->width))
		return (true);
	else
		return (false);
}

t_viewport	compute_viewport(t_game *game, t_minimap *minimap)
{
	t_viewport	vp;
	int			player_tile_x;
	int			player_tile_y;
	int			radius_tiles;

	// Calcul de la position du joueur en tile
	player_tile_x = (int)(game->player->pos.x / TILE_SIZE);
	player_tile_y = (int)(game->player->pos.y / TILE_SIZE);
	// Calcul des rayons autour du joueur
	radius_tiles = (minimap->img.width / minimap->tile_size) / 2;
	// Centrage de la viewport sur le joueur
	vp.start_tile_x = player_tile_x - radius_tiles;
	vp.start_tile_y = player_tile_y - radius_tiles;
	vp.end_tile_x = vp.start_tile_x + radius_tiles;
	vp.end_tile_y = vp.start_tile_y + radius_tiles;
	__handle_viewport_map_limits(&vp, s_data()->map);
	vp.width_tiles = vp.end_tile_x - vp.start_tile_x + 1;
	vp.height_tiles = vp.end_tile_y - vp.start_tile_y + 1;
	vp.pixel_width = vp.width_tiles * minimap->tile_size;
	vp.pixel_height = vp.height_tiles * minimap->tile_size;
	return (vp);
}

static void	__draw_minimap_tile(t_minimap *minimap, t_point tile)
{
	t_point	pixel;
	size_t	x_end;
	size_t	y_end;

	pixel.y = tile.y;
	x_end = pixel.x + minimap->tile_size;
	y_end = pixel.y + minimap->tile_size;
	while (pixel.y < y_end)
	{
		pixel.x = tile.x;
		while (pixel.x < x_end)
		{
			my_pixel_put_to_img(&minimap->img, WHITE_PIX, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

void	draw_viewport_walls(t_minimap *minimap, t_map *map)
{
	t_viewport	*vp;
	t_point		view_tile;
	int			x;
	int			y;

	vp = &minimap->vp;
	y = vp->start_tile_y;
	while (y < vp->end_tile_y)
	{
		x = vp->start_tile_x;
		while (x < vp->end_tile_x)
		{
			if (x >= 0 && x < (int)map->width && y >= 0 && y < (int)map->height)
			{
				if (map->map2d[y][x] == '1')
				{
					view_tile.x = (x - vp->start_tile_x) * minimap->tile_size;
					view_tile.y = (y - vp->start_tile_y) * minimap->tile_size;
					__draw_minimap_tile(minimap, view_tile);
				}
			}
			x++;
		}
		y++;
	}
}
