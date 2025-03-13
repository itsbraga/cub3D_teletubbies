/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:02:38 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/13 01:06:04 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_textures(t_textures *tex, t_data *data)
{
	tex->north = NULL;
	tex->south = NULL;
	tex->west = NULL;
	tex->east = NULL;
	tex->imgs = yama(CREATE, NULL, sizeof(t_img) * 4);
	secure_malloc(tex->imgs, true);	
	data->textures = tex;
}

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
	// a regler selon la disposition des textures
	if (check_textures_paths(tex) == FAILURE)
		clean_exit(FAILURE);
}
