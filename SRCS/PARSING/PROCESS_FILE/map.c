/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:42:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/12 18:57:53 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// AJOUTER MALLOCS A YAMA?
char	**normalize_map2d(char **map, size_t height, size_t width)
{
	char	**normed;
	size_t	i;
	size_t	j;
	size_t	line_len;

	normed = malloc(sizeof(char *) * (height + 1));
	secure_malloc(normed, true);
	i = 0;
	while (i < height)
	{
		normed[i] = malloc(width + 1);
		secure_malloc(normed[i], true);
		line_len = ft_strlen(map[i]);
		j = 0;
		while (j < width)
		{
			if (j < line_len)
			{
				if (map[i][j] == ' ')
					normed[i][j] = '1';
				else
					normed[i][j] = map[i][j];
			}
			else
				normed[i][j] = '1';
			j++;
		}
		normed[i][width] = '\0';
		i++;
	}
	normed[height] = NULL;
	return (normed);
}

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
