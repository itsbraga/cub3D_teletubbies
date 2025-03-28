/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:05 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/27 23:08:50 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

static void	__draw_tile(t_mlx *mlx, t_point tile, float scale)
{
	t_point	pixel;
	size_t	x_end;
	size_t	y_end;

	pixel.x = tile.x * TILE_SIZE * scale;
	pixel.y = tile.y * TILE_SIZE * scale;
	x_end = pixel.x + (TILE_SIZE * scale);
	y_end = pixel.y + (TILE_SIZE * scale);
	while (pixel.y < y_end)
	{
		pixel.x = tile.x * TILE_SIZE * scale;
		while (pixel.x < x_end)
		{
			my_pixel_put_to_img(&mlx->img, WHITE_PIX, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

static void	__draw_map2d(t_mlx *mlx, t_map *map, float scale)
{
	t_point	tile;
	
	tile.y = 0;
	while (tile.y < map->height)
	{
		tile.x = 0;
		while (tile.x < map->width)
		{
			if (map->map2d[(int)tile.y][(int)tile.x] == '1')
				__draw_tile(mlx, tile, scale);
			tile.x++;
		}
		tile.y++;
	}
}

int	render_2d(t_game *game)
{
	float		scale;
	t_player	tmp_player;
	t_point		scaled_pos;

	scale = compute_scale_factor(game->data->map);
	move_player(game, game->keys);
	reset_move(game->player);
	scaled_pos.x = (game->player->pos.x / TILE_SIZE) * (TILE_SIZE * scale);
	scaled_pos.y = (game->player->pos.y / TILE_SIZE) * (TILE_SIZE * scale);
	tmp_player = *game->player;
	tmp_player.pos = scaled_pos;
	clear_img(&game->mlx->img, WIN_WIDTH, WIN_HEIGHT, BLACK_PIX);
	__draw_map2d(game->mlx, game->data->map, scale);
	draw_grid(game->mlx, scale, game->data->map);
	draw_player_2d(game->mlx, &tmp_player);
	raycasting_2d(game->data, game->player, game->ray, scale);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		game->mlx->img.img_ptr, 0, 0);
	return (SUCCESS);
}
