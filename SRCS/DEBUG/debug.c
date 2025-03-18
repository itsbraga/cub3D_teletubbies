/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:10:05 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/18 00:44:06 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__draw_tile(t_mlx *mlx, t_point tile)
{
	t_point	pixel;
	size_t	x_end;
	size_t	y_end;

	pixel.x = tile.x * TILE_SIZE;
	pixel.y = tile.y * TILE_SIZE;
	x_end = pixel.x + TILE_SIZE;
	y_end = pixel.y + TILE_SIZE;
	while (pixel.y < y_end)
	{
		pixel.x = tile.x * TILE_SIZE;
		while (pixel.x < x_end)
		{
			my_pixel_put_to_img(&mlx->img, WHITE_PIX, pixel.x, pixel.y);
			pixel.x++;
		}
		pixel.y++;
	}
}

static void	__draw_map2d(t_mlx *mlx, t_map *map)
{
	t_point	tile;
	
	tile.y = 0;
	while (tile.y < map->height)
	{
		tile.x = 0;
		while (tile.x < map->width)
		{
			if (map->map2d[(int)tile.y][(int)tile.x] == '1')
				__draw_tile(mlx, tile);
			tile.x++;
		}
		tile.y++;
	}
}

static void	__raycasting_2d(t_data *d, t_player *player, t_raycasting *r)
{
	t_point	closest_inter;
	float	ray_rad;

	r->curr_ray = 0;
	ray_rad = norm_rad_angle(r->player_rad - (degree_to_radian(r->fov) / 2));
	while (r->curr_ray < WIN_WIDTH)
	{
		inter_hline(d, player, r, ray_rad);
		inter_vline(d, player, r, ray_rad);
		find_closest_inter(player, r, &closest_inter);
		draw_line(&s_mlx()->img, player->pos, closest_inter, RED_PIX);
		ray_rad += (degree_to_radian(r->fov) / WIN_WIDTH);
		ray_rad = norm_rad_angle(ray_rad);
		r->curr_ray++;
	}
}

int	render_2d(t_data *data)
{
	t_mlx	*mlx;
	
	mlx = s_mlx();
	clear_img(&mlx->img, WIN_WIDTH, WIN_HEIGHT, BLACK_PIX);
	__draw_map2d(mlx, data->map);
	draw_grid(mlx);
	draw_player2d(mlx, s_game()->player);
	__raycasting_2d(data, s_game()->player, s_game()->ray);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->img.img_ptr, 0, 0);
	return (SUCCESS);
}
