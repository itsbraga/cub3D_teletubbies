/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:43:21 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/18 01:12:17 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// func assigner valeur du define de la direction du joueur et 

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
				player->pos.x = (float)j;// + 0.5; // 0.5: decaler legerement (collisions)
				player->pos.y = (float)i;// + 0.5;
				player->dir = map->map2d[i][j]; // remplacer par la fonction ci-dessus
				printf("player dir: %d\n", player->dir);
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
