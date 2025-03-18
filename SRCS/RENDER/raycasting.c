/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:48:06 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/18 01:09:23 by annabrag         ###   ########.fr       */
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
		r->h_ray_inter.x =  player->pos.x + (player->pos.y - r->h_ray_inter.y)
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
		else if (d->map->map2d[(int)curr_tile.y][(int)curr_tile.x] == '1')
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
		else if (d->map->map2d[(int)curr_tile.y][(int)curr_tile.x] == '1')
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

void	find_closest_inter(t_player *player, t_raycasting *r, t_point *closest_inter)
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

void	load_tex_buffer(int orientation, int *tex_buffer)
{
	int		x;
	int		y;
	t_img	*tex_img;
	char	*pixel_addr;

	x = 0;
	y = 0;
	tex_img = &s_data()->textures->imgs[orientation];
	pixel_addr = NULL;
	while (y < TILE_SIZE)
	{
		while (x < TILE_SIZE)
		{
			pixel_addr = tex_img->addr  + ((y * tex_img->size_line) + (x * 4));
			tex_buffer[y * TILE_SIZE + x] = *(int *)pixel_addr;
			x++;
		}
		x = 0;
		y++;
	}
}

void	handle_tex_buffer(int *tex_buffer, float ray_rad, t_raycasting *r)
{
	ft_bzero(tex_buffer, TILE_SIZE * TILE_SIZE);
	if (r->vertical_hit == false)
	{
		if (ray_rad > 0 && ray_rad < PI)
			load_tex_buffer(SO, tex_buffer);
		else if (ray_rad > PI2 && ray_rad < (2 * PI))
			load_tex_buffer(NO, tex_buffer);
	}
	else if (r->vertical_hit == true)
	{
		if (ray_rad > PI2 && ray_rad < PI3)
			load_tex_buffer(WE, tex_buffer);
		else if (ray_rad < PI2 || ray_rad > PI3)
			load_tex_buffer(EA, tex_buffer);
	}
}

void	draw_ceiling(float wall_h, t_raycasting *r)
{
	int		curr_x;
	int		curr_y;
	int		end_y;
	int		color;
	float	shadow_factor;
	t_img	*img;

	curr_x = r->curr_ray;
	curr_y = 0;
	end_y = (WIN_HEIGHT - wall_h) / 2;
	img = &s_mlx()->img;
	while (curr_y <= end_y)
	{
		shadow_factor = 1 - ((float)curr_y / (float)(WIN_HEIGHT / 2));
		if (shadow_factor < 0.1)
			shadow_factor = 0.1;
			// printf("%s | shadow factor = %f\n", __func__, shadow_factor);
		color = apply_shadow_factor((int)s_data()->ceiling_color, shadow_factor);
		my_pixel_put_to_img(img, color, curr_x, curr_y);
		curr_y++;
	}
	return ;
}

void	draw_floor(float wall_h, t_raycasting *r)
{
	int		curr_x;
	int		curr_y;
	int		color;
	float	shadow_factor;
	t_img	*img;

	curr_x = r->curr_ray;
	curr_y = (WIN_HEIGHT + wall_h) / 2;
	img = &s_mlx()->img;
	while (curr_y <= WIN_HEIGHT)
	{
		shadow_factor = ((float)curr_y / (float)WIN_HEIGHT) - 0.25;
		if (shadow_factor < 0.1)
			shadow_factor = 0.1;
		// printf("shadow factor = %f\n", shadow_factor);
		color = apply_shadow_factor((int)s_data()->floor_color, shadow_factor);
		my_pixel_put_to_img(img, color, curr_x, curr_y);
		curr_y++;
	}
	return ;
}

void	set_shadow_factor(t_raycasting *r)
{
	r->shadow_factor = 1 - (r->dist_wall / VISIBILITY_DIST_MAX);
	// r->shadow_factor = r->shadow_factor * r->shadow_factor;
	if (r->shadow_factor < 0.1)
		r->shadow_factor = 0.1;
}

void	draw_wall(float ray_rad, t_raycasting *r)
{
	float	wall_h;
	int		tex_buffer[TILE_SIZE * TILE_SIZE];
	int		start_y;
	int		end_y;
	float	fixed_angle;

	fixed_angle = r->player_rad - ray_rad;
	fixed_angle = norm_rad_angle(fixed_angle);
	r->dist_wall = r->dist_wall * cos(fixed_angle);
	set_shadow_factor(r);
	// printf("dist_wall = %f\n", r->dist_wall);
	wall_h = (TILE_SIZE * WIN_HEIGHT) / r->dist_wall;
	r->step_tex_y = TILE_SIZE / wall_h;
	r->off_tex_y = 0;
	if (wall_h > WIN_HEIGHT)
	{
		r->off_tex_y = (wall_h - WIN_HEIGHT) / 2.0f;
		wall_h = WIN_HEIGHT;
	}
	start_y = (WIN_HEIGHT / 2) - (wall_h / 2);
	end_y = start_y + wall_h;
	(draw_ceiling(wall_h, r), draw_floor(wall_h, r));
	handle_tex_buffer(tex_buffer, ray_rad, r);
	draw_vline_texture(start_y, end_y, tex_buffer, r);
	return ;
}

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
		draw_wall(ray_rad, r);
		ray_rad += (degree_to_radian(r->fov) / WIN_WIDTH);
		ray_rad = norm_rad_angle(ray_rad);
		r->curr_ray++;
	}
}
