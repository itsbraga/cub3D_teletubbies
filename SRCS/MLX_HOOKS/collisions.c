/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:36:16 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/18 22:20:40 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__check_wall_collision(t_data *data, int cell_x, int cell_y)
{
	if ((cell_x >= 0 && cell_x < (int)data->map->width)
		&& (cell_y >= 0 && cell_y < (int)data->map->height))
	{
		if (data->map->map2d[cell_y][cell_x] == '1')
		{
			printf(BOLD RED "/!\\ WARNING /!\\\t--> Collision\n" RESET);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

/*
	[0] Top-left corner
	[1] Top-right corner
	[2] Bottom-left corner
	[3] Bottom-right corner
*/
static int	__check_corners(t_data *data, t_point *new_ppos, int cell_x,
int cell_y)
{
	t_point corners[4];
	float	buffer;
	int		i;

	// The larger the buffer, the further the player is from the wall
	buffer = TILE_SIZE / 3;
	corners[0] = (t_point){new_ppos->x - buffer, new_ppos->y - buffer};
	corners[1] = (t_point){new_ppos->x + buffer, new_ppos->y - buffer};
	corners[2] = (t_point){new_ppos->x - buffer, new_ppos->y + buffer};
	corners[3] = (t_point){new_ppos->x + buffer, new_ppos->y + buffer};
	i = 0;
	while (i < 4)
	{
		cell_x = (int)(corners[i].x / TILE_SIZE);
		cell_y = (int)(corners[i].y / TILE_SIZE);
		if (__check_wall_collision(data, cell_x, cell_y) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	handle_collisions(t_data *data, t_player *player, t_point *new_ppos)
{
	int		cell_x;
	int		cell_y;

	new_ppos->x = player->pos.x + player->move.x;
	new_ppos->y = player->pos.y + player->move.y;
	cell_x = (int)(new_ppos->x / TILE_SIZE);
	cell_y = (int)(new_ppos->y / TILE_SIZE);
	if (__check_wall_collision(data, cell_x, cell_y) == FAILURE)
		return (FAILURE);
	if (__check_corners(data, new_ppos, cell_x, cell_y) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
