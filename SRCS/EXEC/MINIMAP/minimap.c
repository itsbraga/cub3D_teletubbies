/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:51:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/12 21:06:39 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__draw_minimap_tile(t_minimap *minimap, t_point tile)
{
	t_point	pixel;
	size_t	x_end;
	size_t	y_end;

	pixel.x = tile.x * (TILE_SIZE / 4);
	pixel.y = tile.y * (TILE_SIZE / 4);
	x_end = pixel.x + (TILE_SIZE / 4);
	y_end = pixel.y + (TILE_SIZE / 4);
	while (pixel.y < y_end)
	{
		pixel.x = tile.x * (TILE_SIZE / 4);
		while (pixel.x < x_end)
		{
			my_pixel_put_to_img(&minimap->img, WHITE_PIX,
					pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

static void	__draw_minimap(t_game *game, t_minimap *minimap, t_map *map)
{
	t_point	tile;
	
	minimap->pos.x = WIN_WIDTH - minimap->img.width - 20;
	minimap->pos.y = WIN_HEIGHT - minimap->img.height - 20;
	clear_img(&minimap->img, minimap->img.width, minimap->img.height,
		GRAY_PIX);
	tile.y = 0;
	while (tile.y < map->height)
	{
		tile.x = 0;
		while (tile.x < map->width)
		{
			if (map->map2d[(int)tile.y][(int)tile.x] == '1')
				__draw_minimap_tile(minimap, tile);
			tile.x++;
		}
		tile.y++;
	}
	draw_player(game, minimap, game->player);
}

void	render_minimap(t_game *game, t_minimap *minimap)
{
	init_minimap_img(game->mlx, minimap);
	__draw_minimap(game, minimap, data_s()->map);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		minimap->img.img_ptr,
		minimap->pos.x, minimap->pos.y);
	mlx_destroy_image(game->mlx->mlx_ptr, minimap->img.img_ptr);
}
