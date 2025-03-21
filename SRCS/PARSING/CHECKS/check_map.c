/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:14:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/21 03:04:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	Recursive flood fill algorithm to check map boundaries and enclosed spaces
	@param y: current y coordinate being checked
	@param x: current x coordinate being checked
	@param height: total height of the map
	@param width: total width of the map
	@return: true if the map is properly enclosed, false if there are holes

	The function:
	- Marks visited spaces with 'F' (Filled)
	- Checks all four adjacent cells recursively
	- Stops at walls ('1') or previously filled cells ('F')
	- Returns false if it reaches map boundaries or empty spaces
	- Used to verify that the map is completely enclosed by walls
*/
bool	flood_fill(char **map, int y, int x, size_t height, size_t width)
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
	if (flood_fill(map, y - 1, x, height, width) == false)
		return (false);
	if (flood_fill(map, y + 1, x, height, width) == false)
		return (false);
	if (flood_fill(map, y, x - 1, height, width) == false)
		return (false);
	if (flood_fill(map, y, x + 1, height, width) == false)
		return (false);
	return (true);
}

static char	*__normalize_line_for_flood(char *line, size_t width)
{
	char	*normed_line;
	size_t	line_len;
	size_t	j;
	
	normed_line = malloc(width + 1);
	secure_malloc(normed_line, true);
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len--;
	j = 0;
	while (j < width)
	{
		if (j < line_len)
		{
			if (line[j] == ' ' || line[j] == '\t')
				normed_line[j] = '1';
			else
				normed_line[j] = line[j];
		}
		else
			normed_line[j] = '1';
		j++;
	}
	normed_line[width] = '\0';
	return (normed_line);
}

char	**normalize_map_for_flood(char **map, size_t height, size_t width)
{
	char	**normed;
	size_t	i;

	normed = malloc(sizeof(char *) * (height + 1));
	secure_malloc(normed, true);
	i = 0;
	while (i < height)
	{
		normed[i] = __normalize_line_for_flood(map[i], width);
		i++;
	}
	normed[height] = NULL;
	return (normed);
}
