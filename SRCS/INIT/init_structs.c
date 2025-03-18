/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:17:31 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/18 01:24:22 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_map2(t_map *map, char *path_to_file, int fd, t_data *data)
{
	map->path_to_file = yama(ADD, ft_strdup(path_to_file), 0);
	secure_malloc(map->path_to_file, true);
	map->fd = fd;
	map->map2d = NULL;
	map->height = 0;
	map->width = 0;
	data->map = map;
}

void	init_raycasting(t_raycasting *r, t_game *game)
{
	ft_bzero(r, sizeof(t_raycasting));
	r->fov = 45;
	r->player_rad = degree_to_radian(game->player->dir);
	game->ray = r;
}

void	init_keys(t_keys *keys, t_game *game)
{
	ft_bzero(keys->key_array, 6);
	game->keys = keys;
}

void	init_minimap(t_minimap *mini, t_game *game)
{
	ft_bzero(&mini->vp, sizeof(t_viewport));
	ft_bzero(&mini->img, sizeof(t_img));
	mini->pos.x = 0;
	mini->pos.y = 0;
	mini->tile_size = 16;
	game->minimap = mini;
}

void	init_map(t_map *map, t_data *data)
{
	map->map2d = NULL;
	map->height = 0;
	map->width = 0; 
	data->map = map;
}

void	init_player(t_player *player, t_game *game)
{
	player->dir = N;
	player->pos.x = 800;
	player->pos.y = 700;
	player->move.x = 0;
	player->move.y = 0;
	game->player = player;
}

void	init_structs(t_data *data, t_game *game, t_mlx *mlx)
{
	init_map(data->map, data);
	init_player(game->player, game);
	init_mlx(mlx, game);
	init_title_screen(&game->title_screen);
	init_textures(data->textures, data);
	init_raycasting(game->ray, game);
	init_keys(game->keys, game);
	if (BONUS)
	{
		// init_minimap(game->minimap, game);
		// init_weapon(data->weapon, data);
	}
}
