/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:02:38 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/21 19:58:19 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*__get_texture_path(char *line)
{
	char	*start;
	char	*path;
	size_t	len;

	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	start = ft_strchr(line, '.');
	if (start == NULL)
		return (NULL);
	len = ft_strlen_gnl(start, 0);
	if (start[len - 1] == '\n')
		len--;
	path = ft_substr(start, 0, len);
	secure_malloc(path, true);
	return (path);
}

void	fill_textures_paths(char *line, t_textures *tex)
{
	if (ft_strncmp(line, "NO", 2) == 0 && tex->north == NULL)
	{
		tex->north = __get_texture_path(line);
		printf(BOLD PB "NORTH: " RESET "[%s]\n", tex->north);
	}
	else if (ft_strncmp(line, "SO", 2) == 0 && tex->south == NULL)
	{
		tex->south = __get_texture_path(line);
		printf(BOLD PB "SOUTH: " RESET "[%s]\n", tex->south);
	}
	else if (ft_strncmp(line, "WE", 2) == 0 && tex->west == NULL)
	{
		tex->west = __get_texture_path(line);
		printf(BOLD PB "WEST: " RESET "[%s]\n", tex->west);
	}
	else if (ft_strncmp(line, "EA", 2) == 0 && tex->east == NULL)
	{
		tex->east = __get_texture_path(line);
		printf(BOLD PB "EAST: " RESET "[%s]\n", tex->east);
	}
}

void	fill_bonus_textures_paths(char *line, t_textures *tex)
{
	if (line[0] == 'F' && tex->floor == NULL)
	{
		tex->floor = __get_texture_path(line);
		printf(BOLD PB "FLOOR: " RESET "[%s]\n", tex->floor);
	}
	else if (line[0] == 'C' && tex->ceiling == NULL)
	{
		tex->ceiling = __get_texture_path(line);
		printf(BOLD PB "CEILING: " RESET "[%s]\n", tex->ceiling);
	}
}
