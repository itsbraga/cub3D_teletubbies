/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:14:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/13 03:14:22 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '\n' && ft_strchr(VALID_MAP_CHARS, line[i]) == NULL)
		{
			err_msg_quoted(&line[i], ERR_CHAR);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	__flood_fill(char **map, int y, int x, size_t height, size_t width)
{
	if (x < 0 || y < 0 || (size_t)x >= width || (size_t)y >= height
		|| map[y][x] == '\0')
	{
		err_msg(NULL, ERR_MAP_BORDERS);
		return (false);
	}
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (true);
	map[y][x] = 'F';
	if (__flood_fill(map, y - 1, x, height, width) == false)
		return (false);
	if (__flood_fill(map, y + 1, x, height, width) == false)
		return (false);
	if (__flood_fill(map, y, x - 1, height, width) == false)
		return (false);
	if (__flood_fill(map, y, x + 1, height, width) == false)
		return (false);
	return (true);
}

static char	**__duplicate_map(char **map, size_t height)
{
	char	**dup;
	size_t	i;
	
	dup = malloc(sizeof(char *) * (height + 1));
	secure_malloc(dup, true);
	i = 0;
	while (i < height)
	{
		dup[i] = ft_strdup(map[i]);
		secure_malloc(dup[i], true);
		i++;
	}
	dup[height] = NULL;
	return (dup);
}

bool	map_fully_enclosed(char **map, size_t height, size_t width, t_point *pos)
{
	char	**copy;
	bool	result;

	copy = __duplicate_map(map, height);
	secure_malloc(copy, true);
	result = __flood_fill(copy, (int)pos->y, (int)pos->x, height, width);
	free_array(copy);
	return (result);
}
