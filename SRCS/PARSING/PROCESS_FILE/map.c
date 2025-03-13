/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:42:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/13 01:54:26 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// AJOUTER MALLOC A YAMA?
static char	*__normalize_line(char *line, size_t width)
{
	char	*normed_line;
	size_t	line_len;
	size_t	j;
	
	normed_line = malloc(width + 1);
	secure_malloc(normed_line, true);
	line_len = ft_strlen(line) - 1;
	j = 0;
	while (j < width)
	{
		if (j < line_len)
		{
			if (line[j] == ' ')
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

// AJOUTER MALLOC A YAMA?
char	**normalize_map2d(char **map, size_t height, size_t width)
{
	char	**normed;
	size_t	i;


	normed = malloc(sizeof(char *) * (height + 1));
	secure_malloc(normed, true);
	i = 0;
	while (i < height)
	{
		normed[i] = __normalize_line(map[i], width);
		i++;
	}
	normed[height] = NULL;
	return (normed);
}

// AJOUTER MALLOC A YAMA?
void	fill_map2d_array(t_map *map, char *line)
{
	char	**tmp;
	size_t	i;

	tmp = malloc(sizeof(char *) * (map->height + 2)); // pour \n et EOF
	secure_malloc(tmp, true);
	i = 0;
	while (i < map->height)
	{
		tmp[i] = map->map2d[i];
		i++;
	}
	tmp[map->height] = ft_strdup(line);
	secure_malloc(tmp[map->height], true);
	tmp[map->height + 1] = NULL;
	free(map->map2d);
	map->map2d = tmp;
	map->height++;
}
