/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:36 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/21 03:25:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	__process_map_data(t_map *map, t_data *data, char *arg, int fd)
{
	init_map(map, arg, fd, data);
	get_file_data(fd, data);
	close(fd);
	if (map->map2d == NULL || map->height == 0)
		return (false);
	return (true);
}

static bool	__validate_map(char **flood_map, size_t height, size_t longest_line,
t_player *player)
{
	t_point	pos;
	
	pos = (t_point){player->pos.x, player->pos.y};
	if (flood_fill(flood_map, pos.y, pos.x, height, longest_line) == false)
	{
		free_array(flood_map);
		return (false);
	}
	free_array(flood_map);
	return (true);
}

static void	__replace_by_final_map(t_data *data, size_t longest_line)
{
	char	**final_map;

	final_map = normalize_map(data->map->map2d, data->map->height,
	longest_line);
	secure_malloc(final_map, true);
	free_array(data->map->map2d);
	data->map->map2d = final_map;
	data->map->width = longest_line;
}

int	parsing(char *arg, t_data *data, t_game *game)
{
	int		fd;
	t_map	*map;
	size_t	longest_line;
	char	**flood_map;

	fd = check_cub_file(arg);
	map = data->map;
	if (__process_map_data(map, data, arg, fd) == false)
		return (FAILURE);
	longest_line = get_longest_line(map->map2d, map->height);
	flood_map = normalize_map_for_flood(map->map2d, map->height, longest_line);
	secure_malloc(flood_map, true);
	if (__validate_map(flood_map, map->height, longest_line,
		game->player) == false)
		return (FAILURE);
	__replace_by_final_map(data, longest_line);
	get_player_direction(map, game->player);
	game->data = data;
	return (SUCCESS);
}
