/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:48:06 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/27 19:35:24 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	inter_hline(t_data *d, t_player *player, t_raycasting *r, float ray_rad)
{
	float	inv_tan;
	t_point	curr_tile;
	
	if (tan(ray_rad) != 0)
		inv_tan = -1 / tan(ray_rad);
	else
		inv_tan = 0;
	if (fabs(ray_rad - PI2) < EPS || fabs(ray_rad - PI3) < EPS)
	{
		r->h_ray_inter.x = player->pos.x;
		r->h_ray_inter.y = player->pos.y;
		return ;
	}
	else if (ray_rad > PI)
	{
		r->h_ray_inter.y = floor(player->pos.y / TILE_SIZE) * TILE_SIZE - 0.0001;
		r->h_ray_inter.x = player->pos.x + (player->pos.y - r->h_ray_inter.y)
				* inv_tan;
		r->h_offset.y = -TILE_SIZE;
		r->h_offset.x = -(r->h_offset.y) * inv_tan;
		// printf("1\n");
	}
	else if (ray_rad < PI)
	{
		r->h_ray_inter.y = floor(player->pos.y / TILE_SIZE) * TILE_SIZE
				+ TILE_SIZE;
		r->h_ray_inter.x = player->pos.x + (player->pos.y - r->h_ray_inter.y)
				* inv_tan;
		r->h_offset.y = TILE_SIZE;
		r->h_offset.x = -r->h_offset.y * inv_tan;
		// printf("2\n");
	}
	while (true)
	{
		curr_tile.x = r->h_ray_inter.x / TILE_SIZE;
		curr_tile.y = r->h_ray_inter.y / TILE_SIZE;
		if ((int)curr_tile.x < 0 || (size_t)curr_tile.x >= d->map->width
			|| (int)curr_tile.y < 0 || (size_t)curr_tile.y >= d->map->height)
			break;
		else if (d->map->wmap[(int)curr_tile.y][(int)curr_tile.x] == '1')
		{
			// printf("HIT A WALL !\n");
			break;
		}
		else
		{
			// printf("offset.x = %f | offset.y = %f\n", r->h_offset.x, r->h_offset.y);
			r->h_ray_inter.x += r->h_offset.x;
			r->h_ray_inter.y += r->h_offset.y;
		}
	}
}

void	inter_vline(t_data *d, t_player *player, t_raycasting *r, float ray_rad)
{
	float	neg_tan;
	t_point	curr_tile;
	
	// printf("%s\n", __func__);
	neg_tan = -tan(ray_rad);
	if (fabs(ray_rad - PI) < EPS || fabs(ray_rad) < EPS)
	{
		r->v_ray_inter.x = player->pos.x;
		r->v_ray_inter.y = player->pos.y;
		return ;
	}
	else if (ray_rad > PI2 && ray_rad < PI3)
	{
		r->v_ray_inter.x = floor(player->pos.x / TILE_SIZE) * TILE_SIZE - 0.0001;
		r->v_ray_inter.y = player->pos.y + (player->pos.x - r->v_ray_inter.x) 
				* neg_tan;
		r->v_offset.x = -TILE_SIZE;
		r->v_offset.y = -r->v_offset.x * neg_tan;
		// printf("4\n");
	}
	else if (ray_rad < PI2 || ray_rad > PI3)
	{
		r->v_ray_inter.x = floor(player->pos.x / TILE_SIZE) * TILE_SIZE
				+ TILE_SIZE;
		r->v_ray_inter.y = player->pos.y + (player->pos.x - r->v_ray_inter.x) 
				* neg_tan;
		r->v_offset.x = TILE_SIZE;
		r->v_offset.y = -r->v_offset.x * neg_tan;
		// printf("5\n");
	}
	while (true)
	{
		curr_tile.x = r->v_ray_inter.x / TILE_SIZE;
		curr_tile.y = r->v_ray_inter.y / TILE_SIZE;
		if ((int)curr_tile.x < 0 || (size_t)curr_tile.x >= d->map->width
			|| (int)curr_tile.y < 0 || (size_t)curr_tile.y >= d->map->height)
			break;
		else if (d->map->wmap[(int)curr_tile.y][(int)curr_tile.x] == '1')
		{
			// printf("HIT A WALL\n");
			break;
		}
		else
		{
			// printf("offset.x = %f | offset.y = %f\n", r->v_offset.x, r->v_offset.y);
			r->v_ray_inter.x += r->v_offset.x;
			r->v_ray_inter.y += r->v_offset.y;
		}
	}
}

void	find_closest_inter(t_player *player, t_raycasting *r,
t_point *closest_inter)
{
	float	delta_xh;
	float	delta_yh;
	float	delta_xv;
	float	delta_yv;
	float	dist_h;
	float	dist_v;

	delta_xh = r->h_ray_inter.x - player->pos.x;
	delta_yh = r->h_ray_inter.y - player->pos.y;
	delta_xv = r->v_ray_inter.x - player->pos.x;
	delta_yv = r->v_ray_inter.y - player->pos.y;
	dist_h = (delta_xh * delta_xh) + (delta_yh * delta_yh);
	dist_v = (delta_xv * delta_xv) + (delta_yv * delta_yv);
	if (dist_h < dist_v)
	{
		closest_inter->x = r->h_ray_inter.x;
		closest_inter->y = r->h_ray_inter.y;
		r->dist_wall = sqrt(dist_h);
		r->tex_x = (int)closest_inter->x & (TILE_SIZE - 1);
		r->vertical_hit = false;
	}
	else
	{
		closest_inter->x = r->v_ray_inter.x;
		closest_inter->y = r->v_ray_inter.y;
		r->dist_wall = sqrt(dist_v);
		r->tex_x = (int)closest_inter->y & (TILE_SIZE - 1);
		r->vertical_hit = true;
	}
}

// One ray == one x
// With ray_rad, we start with the leftmost ray
void	raycasting(t_data *d, t_player *player, t_raycasting *r)
{
	t_point	closest_inter;
	float	ray_rad;

	r->curr_ray = 0;
	r->player_rad = degree_to_radian(player->dir);
	ray_rad = norm_rad_angle(r->player_rad - (degree_to_radian(r->fov) / 2));
	while (r->curr_ray < WIN_WIDTH)
	{
		inter_hline(d, player, r, ray_rad);
		inter_vline(d, player, r, ray_rad);
		find_closest_inter(player, r, &closest_inter);
		draw_wall(r, ray_rad);
		#if BONUS
			fc_precalculations(r, ray_rad);
			draw_floor_texture(r);
			draw_ceiling_texture(r);
		#else
			draw_floor_color(r, d);
			draw_ceiling_color(r, d);
		#endif
		ray_rad += (degree_to_radian(r->fov) / WIN_WIDTH);
		ray_rad = norm_rad_angle(ray_rad);
		r->curr_ray++;
	}
}
