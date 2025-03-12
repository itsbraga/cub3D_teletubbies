/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:01:31 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/12 18:18:34 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*	A singleton ensures a class or structure has only
	one instance and provides a global access point
	to it.
*/
t_game	*game_s(void)
{
	static t_game	*instance = NULL;

	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_game));
		secure_malloc(instance, true);
		instance->state = TITLE_SCREEN;
		instance->player = yama(CREATE, NULL, sizeof(t_player));
		secure_malloc(instance->player, true);
		instance->ray = yama(CREATE, NULL, sizeof(t_raycasting));
		secure_malloc(instance->ray, true);
		instance->keys = yama(CREATE, NULL, sizeof(t_keys));
		secure_malloc(instance->keys, true);
		instance->minimap = yama(CREATE, NULL, sizeof(t_minimap));
		secure_malloc(instance->minimap, true);
		instance->mlx = NULL;
	}
	return (instance);
}

t_mlx	*mlx_s(void)
{
	static t_mlx	*instance = NULL;
	
	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_mlx));
		secure_malloc(instance, true);
		instance->mlx_ptr = NULL;
		instance->win_ptr = NULL;
		instance->img.img_ptr = NULL;
		instance->img.addr = NULL;
		instance->img.bits_per_pixel = 0;
		instance->img.size_line = 0;
		instance->img.endian = 0;
	}
	return (instance);
}

t_data	*data_s(void)
{
	static t_data	*instance = NULL;

	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_data));
		secure_malloc(instance, true);
		instance->map = yama(CREATE, NULL, sizeof(t_map));
		secure_malloc(instance->map, true);
		instance->textures = yama(CREATE, NULL, sizeof(t_textures));
		secure_malloc(instance->textures, true);
		instance->floor_color = 0;
		instance->ceiling_color = 0;
		instance->feature_filled = 0;
	}
	return (instance);
}
