/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:36 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/17 23:45:31 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

short	parsing(char *arg, t_data *data)
{
	int		fd;
	size_t	longest_line;
	char	**normed_map2d;

	fd = check_cub_file(arg);
	init_map2(data->map, arg, fd, data);
	get_file_data(fd, data);
	close(fd);
	if (data->map->map2d == NULL || data->map->height == 0)
	{
		err_msg(NULL, ERR);
		return (FAILURE);
	}
	longest_line = get_longest_line(data->map->map2d, data->map->height);
	normed_map2d = normalize_map2d(data->map->map2d, data->map->height,
		longest_line);
	secure_malloc(normed_map2d, true);
	free(data->map->map2d);
	data->map->map2d = normed_map2d;
	data->map->width = longest_line;
	if (map_fully_enclosed(data->map->map2d, data->map->height,
		data->map->width, &s_game()->player->pos) == false)
		return (FAILURE);
	get_player_direction(data->map, s_game()->player);
	return (SUCCESS);
}
