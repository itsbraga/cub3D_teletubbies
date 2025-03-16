/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:36:16 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/13 02:51:04 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	handle_collisions(t_data *data, t_player *player, t_point *new_player_pos)
{
	t_point	cell;
	int		x;
	int		y;

	cell.x = 0;
	cell.y = 0;
	new_player_pos->x += player->move.x;
	new_player_pos->y += player->move.y;
	// printf("New player pos: (%.2f, %.2f)\n", new_player_pos->x, new_player_pos->y);
	cell.x = new_player_pos->x * data->map->width / WIN_WIDTH;
	cell.y = new_player_pos->y * data->map->height / WIN_HEIGHT;
	// printf("Cell value: %c\n", data->map->map2d[(int)cell.y][(int)cell.x]);
	x = (int)cell.x;
	y = (int)cell.y;
	if (data->map->map2d[y][x] == '1')
	{
		printf(BOLD RED "/!\\ WARNING /!\\\t--> Collision\n" RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}
