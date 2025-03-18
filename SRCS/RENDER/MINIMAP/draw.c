/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:39:37 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/18 00:37:49 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__draw_minimap_tile(t_minimap *mmap, t_point tile)
{
	t_point	pixel;
	size_t	x_end;
	size_t	y_end;

	pixel.x = mmap->vp.offset_x + (tile.x * mmap->tile_size);
	pixel.y = mmap->vp.offset_y + (tile.y * mmap->tile_size);
	x_end = pixel.x + mmap->tile_size;
	y_end = pixel.y + mmap->tile_size;
	while (pixel.y < y_end)
	{
		pixel.x = mmap->vp.offset_x + (tile.x * mmap->tile_size);
		while (pixel.x < x_end)
		{
			my_pixel_put_to_img(&mmap->img, WHITE_PIX, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

// void	draw_minimap(t_minimap *minimap, t_map *map)
// {
// 	t_point	tile;
	
// 	tile.y = 0;
// 	while (tile.y < map->height)
// 	{
// 		tile.x = 0;
// 		while (tile.x < map->width)
// 		{
// 			if (map->map2d[(int)tile.y][(int)tile.x] == '1')
// 				__draw_minimap_tile(minimap, tile);
// 			tile.x++;
// 		}
// 		tile.y++;
// 	}
// }

void	draw_minimap(t_minimap *mmap, t_map *map)
{
	t_point	tile;
	int player_tile_x = (int)(s_game()->player->pos.x / TILE_SIZE);
	int player_tile_y = (int)(s_game()->player->pos.y / TILE_SIZE);
	int perimeter = 8; // Affiche 8 tuiles de chaque côté du joueur

	int start_x = player_tile_x - perimeter;
	int start_y = player_tile_y - perimeter;
	int end_x = player_tile_x + perimeter;
	int end_y = player_tile_y + perimeter;

	// Clamp aux bornes de la carte
	if (start_x < 0) start_x = 0;
	if (start_y < 0) start_y = 0;
	if (end_x >= (int)map->width) end_x = (int)map->width - 1;
	if (end_y >= (int)map->height) end_y = (int)map->height - 1;

	int zone_width = end_x - start_x + 1;
	int zone_height = end_y - start_y + 1;

	// Recalculer le viewport en fonction de la zone affichée
	mmap->vp = compute_viewport(mmap, zone_width, zone_height);

	// Parcours de la région à afficher
	for (int y = start_y; y <= end_y; y++)
	{
		for (int x = start_x; x <= end_x; x++)
		{
			if (map->map2d[y][x] == '1')
			{
				// Calcul de la position relative dans la région
				tile.x = x - start_x;
				tile.y = y - start_y;
				__draw_minimap_tile(mmap, tile);
			}
		}
	}
}
