/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:14:14 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/19 03:28:03 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	Validates if a line contains only valid map characters
	@param line: string to check
	@return: true if line contains only valid map characters, false otherwise
	The function:
	- Checks each character against VALID_MAP_CHARS (0,1, ,N,S,E,W)
	- Allows newline characters
	- Returns false and displays error if invalid character found
*/
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

/*
	Verifies if the map is completely enclosed by walls using flood fill
	@param pos: starting position for flood fill (player position)
	@return: true if map is properly enclosed, false if there are holes
	The function:
	- Creates a copy of the map for testing
	- Performs flood fill from player position
	- Cleans up allocated memory
	- Returns the flood fill result
*/
bool	map_fully_enclosed(char **map, size_t height, size_t width,
t_point *pos)
{
	char	**copy;
	bool	result;

	copy = __duplicate_map(map, height);
	secure_malloc(copy, true);
	result = __flood_fill(copy, (int)pos->y, (int)pos->x, height, width);
	free_array(copy);
	return (result);
}
