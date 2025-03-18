/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:01:31 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/18 01:31:25 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*	A singleton ensures a class or structure has only
	one instance and provides a global access point
	to it.
*/
t_game	*s_game(void)
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
		instance->mmap = yama(CREATE, NULL, sizeof(t_minimap));
		secure_malloc(instance->mmap, true);
		instance->mlx = NULL;
		// instance->data = NULL;
	}
	return (instance);
}

t_mlx	*s_mlx(void)
{
	static t_mlx	*instance = NULL;
	
	if (instance == NULL)
	{
		instance = yama(CREATE, NULL, sizeof(t_mlx));
		secure_malloc(instance, true);
		instance->mlx_ptr = NULL;
		instance->win_ptr = NULL;
		ft_bzero(&instance->img, sizeof(t_img));
	}
	return (instance);
}

t_data	*s_data(void)
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
		instance->weapon = yama(CREATE, NULL, sizeof(t_weapon));
		secure_malloc(instance->weapon, true);
		instance->ennemy = yama(CREATE, NULL, sizeof(t_ennemy));
		secure_malloc(instance->ennemy, true);
		instance->floor_color = 0;
		instance->ceiling_color = 0;
		instance->feature_filled = 0;
	}
	return (instance);
}
