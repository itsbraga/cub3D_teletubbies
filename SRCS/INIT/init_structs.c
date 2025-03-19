/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/19 01:02:44 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_map(t_map *map, char *path_to_file, int fd, t_data *data)
{
	ft_bzero(map, sizeof(t_map));
	map->path_to_file = yama(ADD, ft_strdup(path_to_file), 0);
	secure_malloc(map->path_to_file, true);
	map->fd = fd;
	data->map = map;
}

void	init_raycasting(t_raycasting *r, t_game *game)
{
	ft_bzero(r, sizeof(t_raycasting));
	r->fov = 45;
	game->ray = r;
}

void	init_keys(t_keys *keys, t_game *game)
{
	ft_bzero(keys->key_array, 6);
	game->keys = keys;
}

void	init_structs(t_data *data, t_game *game, t_mlx *mlx)
{
	init_mlx(mlx, game);
	init_title_screen(&game->title_screen);
	init_textures(data->textures, data);
	init_raycasting(game->ray, game);
	init_keys(game->keys, game);
	if (BONUS)
	{
		init_minimap(game->mmap, game);
		// init_weapon(data->weapon, data);
	}
}
