/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:42:25 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/21 19:35:51 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static size_t	__handle_tab(char *normed_line, size_t k, size_t width)
{
	size_t	i;
	size_t	spaces;

	i = 0;
	spaces = 0;
	while (i < 4 && k + i < width)
	{
		normed_line[k + i] = ' ';
		i++;
		spaces++;
	}
	return (spaces);
}

static char	*__normalize_line_for_storage(char *line, size_t width)
{
	char	*normed_line;
	size_t	line_len;
	int		j;
	size_t	k;
	
	normed_line = malloc(width + 1);
	secure_malloc(normed_line, true);
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len--;
	j = -1;
	k = 0;
	while (k < width)
	{
		if (++j < (int)line_len && line[j] == '\t')
			k += __handle_tab(normed_line, k, width);
		else if (j < (int)line_len)
			normed_line[k++] = line[j];
		else
			normed_line[k++] = ' ';
	}
	normed_line[width] = '\0';
	return (normed_line);
}

char	**normalize_final_map(char **map, size_t height, size_t width)
{
	char	**normed;
	size_t	i;

	normed = malloc(sizeof(char *) * (height + 1));
	secure_malloc(normed, true);
	i = 0;
	while (i < height)
	{
		normed[i] = __normalize_line_for_storage(map[i], width);
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

	tmp = malloc(sizeof(char *) * (map->height + 2));
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
