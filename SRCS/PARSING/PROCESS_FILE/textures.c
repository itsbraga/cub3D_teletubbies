/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:47:23 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/09 13:43:34 by art3mis          ###   ########.fr       */
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

static void	__fill_textures_paths(char *line, t_textures *tex)
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

static bool	__has_all_textures(t_textures *tex)
{
	return (tex->north && tex->south && tex->west && tex->east);
}

void	process_texture_lines(char *line, t_textures *tex)
{
	__fill_textures_paths(line, tex);
	if (ft_strncmp(line, "NO", 2) == 0)
	{
		tex->imgs[NO] = xpm_to_mlx_img(tex->north);
		s_data()->feature_filled++;
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		tex->imgs[SO] = xpm_to_mlx_img(tex->south);
		s_data()->feature_filled++;
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		tex->imgs[WE] = xpm_to_mlx_img(tex->west);
		s_data()->feature_filled++;
	}
	else
	{
		tex->imgs[EA] = xpm_to_mlx_img(tex->east);
		s_data()->feature_filled++;
	}
	if (__has_all_textures(tex) == true&& check_textures_paths(tex) == FAILURE)
		clean_exit(FAILURE);
}
