/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:46:07 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/21 19:46:41 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// NOT USED YET
int	set_minimap_zoom_factor_keys(int keycode, t_game *game)
{
	if (keycode == XK_plus || keycode == XK_equal)
	{
		game->mmap->vp.zoom_factor += 0.1f;
		if (game->mmap->vp.zoom_factor > 2.0f) // Limite de zoom max
			game->mmap->vp.zoom_factor = 2.0f;
	}
	if (keycode == XK_minus)
	{
		game->mmap->vp.zoom_factor -= 0.1f;
		if (game->mmap->vp.zoom_factor < 0.5f) // Limite de zoom min
			game->mmap->vp.zoom_factor = 0.5f;
	}
	return (SUCCESS);
}
