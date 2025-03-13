/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:36:56 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/13 03:11:42 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__handle_map_limits(t_viewport *vp, t_map *map)
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

t_viewport	compute_viewport(t_game *game, t_map *map, int view_half,
size_t tile_size)
{
	int			player_tile_x;
	int			player_tile_y;
	t_viewport	vp;

	player_tile_x = (int)(game->player->pos.x / TILE_SIZE);
	player_tile_y = (int)(game->player->pos.y / TILE_SIZE);
	vp.start_tile_x = player_tile_x - view_half;
	vp.start_tile_y = player_tile_y - view_half;
	vp.end_tile_x = player_tile_x + view_half;
	vp.end_tile_y = player_tile_y + view_half;
	__handle_map_limits(&vp, map);
	vp.width_tiles = vp.end_tile_x - vp.start_tile_x + 1;
	vp.height_tiles = vp.end_tile_y - vp.start_tile_y + 1;
	vp.pixel_width = vp.width_tiles * tile_size;
	vp.pixel_height = vp.height_tiles * tile_size;
	return (vp);
}

void	draw_viewport_walls(t_minimap *minimap, t_map *map)
{
	t_viewport	*vp;
	t_point		tile_in_view;
	int			x;
	int			y;

	vp = &minimap->vp;
	y = vp->start_tile_y;
	while (y <= vp->end_tile_y)
	{
		x = vp->start_tile_x;
		while (x <= vp->end_tile_x)
		{
			if (map->map2d[y][x] == '1')
			{
				tile_in_view.x = x - vp->start_tile_x;
				tile_in_view.y = y - vp->start_tile_y;
				draw_minimap_tile(minimap, tile_in_view);
			}
			x++;
		}
		y++;
	}
}

void	draw_player_in_viewport(t_game *game, t_minimap *minimap)
{
	t_viewport	*vp;
	t_point		player_tile_pos;
	t_point		player_view;

	vp = &minimap->vp;
	player_tile_pos.x = game->player->pos.x / TILE_SIZE;
	player_tile_pos.y = game->player->pos.y / TILE_SIZE;
	player_view.x = (player_tile_pos.x - vp->start_tile_x) * minimap->tile_size;
	player_view.y = (player_tile_pos.y - vp->start_tile_y) * minimap->tile_size;
	draw_miniplayer(minimap, &player_view);
}
