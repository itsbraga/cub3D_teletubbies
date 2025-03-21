/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 04:32:37 by marvin            #+#    #+#             */
/*   Updated: 2025/03/21 04:32:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

float	compute_scale_factor(t_map *map)
{
	float	scale_x;
	float	scale_y;
	float	total_width;
	float	total_height;

	total_width = map->width * TILE_SIZE;
	total_height = map->height * TILE_SIZE;
	scale_x = (float)WIN_WIDTH / total_width;
	scale_y = (float)WIN_HEIGHT / total_height;
	if (scale_x < scale_y)
		return (scale_x);
	return (scale_y);
}

t_point	scale_point(t_point p, float scale)
{
	t_point scaled;

	scaled.x = p.x * scale;
	scaled.y = p.y * scale;
	return (scaled);
}

void	raycasting_2d(t_data *d, t_player *player, t_raycasting *r,
float scale)
{
	t_point	closest_inter;
	t_point	ray_start;
	float	ray_rad;

	ray_start.x = player->pos.x / TILE_SIZE;
	ray_start.y = player->pos.y / TILE_SIZE;
	ray_start = scale_point(ray_start, TILE_SIZE * scale);
	ray_rad = norm_rad_angle(r->player_rad - (degree_to_radian(r->fov) / 2));
	r->curr_ray = 0;
	while (r->curr_ray < WIN_WIDTH)
	{
		inter_hline(d, player, r, ray_rad);
		inter_vline(d, player, r, ray_rad);
		find_closest_inter(player, r, &closest_inter);
		closest_inter.x = closest_inter.x / TILE_SIZE;
		closest_inter.y = closest_inter.y / TILE_SIZE;
		closest_inter = scale_point(closest_inter, TILE_SIZE * scale);
		draw_line(&s_mlx()->img, ray_start, closest_inter, YELLOW_PIX);
		ray_rad += (degree_to_radian(r->fov) / WIN_WIDTH);
		ray_rad = norm_rad_angle(ray_rad);
		r->curr_ray++;
	}
}
