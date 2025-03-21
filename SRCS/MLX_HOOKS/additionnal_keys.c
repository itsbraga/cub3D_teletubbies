/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionnal_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:08:55 by marvin            #+#    #+#             */
/*   Updated: 2025/03/20 21:08:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	set_title_screen_keys(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		exit_game(s_mlx(), SUCCESS);
	else if (keycode == XK_Return)
	{
		game->state = GAME;
		toggle_mouse_visibility(game->mlx, game->state);
	}
	return (SUCCESS);
}

int	set_minimap_zoom_factor(int keycode, t_game *game)
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
