/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:22:58 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/28 00:58:06 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	swap_point(t_point *p0, t_point *p1)
{
	t_point tmp;

	tmp = *p0;
	*p0 = *p1;
	*p1 = tmp;
}

bool	is_valid_point(t_point point, size_t win_width, size_t win_height)
{
	if (point.x > win_width || point.x < 0)
		return (false);
	if (point.y > win_height || point.y < 0)
		return (false);
	return (true);
}

bool	is_within_map_bounds(int x, int y, t_map *map)
{
	if (x < 0 || x >= (int)map->width || y < 0 || y >= (int)map->height)
		return (false);
	return (true);
}

bool	is_door(t_data *data, t_point *p)
{
	int	cell_x;
	int	cell_y;

	cell_x = (int)(p->x / TILE_SIZE);
	cell_y = (int)(p->y / TILE_SIZE);
	if (cell_x < 0 || cell_x >= (int)data->map->width
		|| cell_y < 0 || cell_y >= (int)data->map->height)
		return (false);
	if (data->map->map2d[cell_y][cell_x] == '2')
		return (true);
	return (false);
}
