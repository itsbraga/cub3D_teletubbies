/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:43:21 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/27 23:08:50 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__set_player_direction(char c, t_player *player)
{
	if (c == 'N')
		return (player->dir = N);
	else if (c == 'S')
		return (player->dir = S);
	else if (c == 'E')
		return (player->dir = E);
	else
		return (player->dir = W);
}

static void	__set_player_pos(t_player *player, size_t j, size_t i, char dir)
{
	player->pos.x = (float)j + 0.4;
	player->pos.y = (float)i + 0.4;
	player->dir = __set_player_direction(dir, player);
}

static int	__find_player_in_line(char *line, t_player *player, size_t i)
{
	size_t	line_len;
	size_t	j;
	int		found;

	line_len = ft_strlen(line);
	found = 0;
	j = 0;
	while (j < line_len)
	{
		if (ft_strchr(PLAYER_DIR, line[j]) != NULL)
		{
			__set_player_pos(player, j, i, line[j]);
			found++;
		}
		j++;
	}
	return (found);
}

static bool	__is_valid_player_pos(t_map *map, t_point pos)
{
	if (pos.x < 0 || pos.y < 0 || (size_t)pos.y >= map->height
		|| (size_t)pos.x >= map->width
		|| map->map2d[(int)pos.y][(int)pos.x] == '1'
		|| map->map2d[(int)pos.y][(int)pos.x] == ' '
		|| map->map2d[(int)pos.y][(int)pos.x] == '\t')
	{
		err_msg(NULL, ERR_PLAYER_POS);
		return (false);
	}
	return (true);
}

void	get_player_direction(t_map *map, t_player *player)
{
	size_t	i;
	int		player_count;

	player_count = 0;
	i = 0;
	while (i < map->height)
	{
		player_count += __find_player_in_line(map->map2d[i], player, i);
		i++;
	}
	if (player_count == 0)
	{
		err_msg(NULL, ERR_PLAYER);
		clean_exit(FAILURE);
	}
	if (player_count > 1)
	{
		err_msg(NULL, ERR_NB_PLAYER);
		clean_exit(FAILURE);
	}
	if (__is_valid_player_pos(map, player->pos) == false)
		clean_exit(FAILURE);
	player->pos.x = player->pos.x * TILE_SIZE;
	player->pos.y = player->pos.y * TILE_SIZE;
	s_game()->player = player;
}
