/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_v2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:51:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/15 20:16:04 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_minimap_tile(t_minimap *minimap, t_point tile)
{
	t_point	pixel;
	size_t	x_end;
	size_t	y_end;

	pixel.x = tile.x * minimap->tile_size;
	pixel.y = tile.y * minimap->tile_size;
	x_end = pixel.x + minimap->tile_size;
	y_end = pixel.y + minimap->tile_size;
	while (pixel.y < y_end)
	{
		pixel.x = tile.x * minimap->tile_size;
		while (pixel.x < x_end)
		{
			my_pixel_put_to_img(&minimap->img, WHITE_PIX, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

static void	__draw_minimap(t_game *game, t_minimap *minimap, t_map *map)
{
	int	view_half;

	view_half = 10;
	minimap->vp = compute_viewport(game, map, view_half, minimap->tile_size);
	init_minimap_img(game->mlx, minimap);
	clear_img(&minimap->img, minimap->img.width, minimap->img.height, GRAY_PIX);
	draw_viewport_walls(minimap, map);
	draw_player_in_viewport(game, minimap);
}

void	render_minimap_v2(t_game *game, t_minimap *minimap)
{
	__draw_minimap(game, minimap, data_s()->map);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		minimap->img.img_ptr, minimap->pos.x, minimap->pos.y);
	mlx_destroy_image(game->mlx->mlx_ptr, minimap->img.img_ptr);
}
