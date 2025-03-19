/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:43:21 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/18 21:54:39 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__set_player_direction(char c, t_player *player)
{
	if (c == 'N')
		return (player->dir = N);
	else if (c == 'S')
		return (player->dir = S);
	else if (c == 'E')
		return (player->dir = E);
	else
		return (player->dir = W);
}

void	get_player_direction(t_map *map, t_player *player)
{
	size_t	i;
	size_t	j;
	size_t	line_size;
	int		player_count;

	i = 0;
	player_count = 0;
	while (i < map->height)
	{
		line_size = ft_strlen(map->map2d[i]);
		j = 0;
		while (j < line_size)
		{
			if (ft_strchr(PLAYER_DIR, map->map2d[i][j]) != NULL)
			{
				// Adjust the offset to keep the player away from the walls
				player->pos.x = (float)j + 0.4;
				player->pos.y = (float)i + 0.4;
				player->dir = __set_player_direction(map->map2d[i][j], player);
				player_count++;
			}
			j++;
		}
		i++;
	}
	if (player_count == 0)
		return (err_msg(NULL, ERR_PLAYER), clean_exit(FAILURE));
	if (player_count > 1)
		return (err_msg(NULL, ERR_NB_PLAYER), clean_exit(FAILURE));
	player->pos.x = player->pos.x * TILE_SIZE;
	player->pos.y = player->pos.y * TILE_SIZE;
	s_game()->player = player;
}
// check aussi si la position donnee est valide
