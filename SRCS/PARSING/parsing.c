/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:36 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/12 19:25:16 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

short	parsing(char *arg, t_map *map)
{
	int		fd;
	size_t	longest_line;
	char	**normed_map2d;

	fd = check_cub_file(arg);
	init_map2(map, arg, fd, data_s());
	get_file_data(fd, data_s());
	close(fd);
	if (map->map2d == NULL || map->height == 0)
	{
		err_msg(NULL, ERR);
		return (FAILURE);
	}
	longest_line = get_longest_line(map->map2d, map->height);
	normed_map2d = normalize_map2d(map->map2d, map->height,
			longest_line); // pb ici je pense
	secure_malloc(normed_map2d, true);
	free(map->map2d);
	map->map2d = normed_map2d;
	map->width = longest_line;
	get_player_direction(map, game_s()->player);
	if (map_fully_enclosed(map->map2d, map->height, map->width,
		&game_s()->player->pos) == false)
		return (FAILURE);
	return (SUCCESS);
}
