/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:09:54 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/13 03:34:35 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_map2d(t_map *m)
{
	if (m == NULL || m->map2d != NULL)
		return ;
	m->map2d = malloc(17 * sizeof(char *));
	secure_malloc(m->map2d, true);
	m->map2d[0] = ft_strdup("1111111111111111");
	m->map2d[1] = ft_strdup("1010000001000001");
	m->map2d[2] = ft_strdup("1010001001000001");
	m->map2d[3] = ft_strdup("1010001001111001");
	m->map2d[4] = ft_strdup("1010001000000001");
	m->map2d[5] = ft_strdup("1010001111111001");
	m->map2d[6] = ft_strdup("1010000000000001");
	m->map2d[7] = ft_strdup("1011111100000001");
	m->map2d[8] = ft_strdup("1000000000000001");
	m->map2d[9] = ft_strdup("1000000000000001");
	m->map2d[10] = ft_strdup("1000000000000001");
	m->map2d[11] = ft_strdup("1000001111000001");
	m->map2d[12] = ft_strdup("1000001001000001");
	m->map2d[13] = ft_strdup("1000001001000001");
	m->map2d[14] = ft_strdup("1000000000000001");
	m->map2d[15] = ft_strdup("1111111111111111");
	m->map2d[16] = NULL;
}

void	get_map_size(t_map *m)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (m->map2d[y][x] != '\0')
		x++;
	while (m->map2d[y] != NULL)
		y++;
	m->width = x;
	m->height = y;
}

void	get_map_info(t_map *m)
{
	get_map2d(m);
	get_map_size(m);
}
