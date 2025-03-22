/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   title_screen_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:03:47 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/21 19:15:31 by annabrag         ###   ########.fr       */
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

int	title_screen_mouse(int button, int x, int y, t_game *game)
{
	t_layer	start_button;

	start_button = game->title_screen.second_layer;
	if (game->state == TITLE_SCREEN && button == Button1) // Clic gauche
	{
		if ((x >= start_button.pos.x && x <= start_button.pos.x
				+ start_button.width)
			&& (y >= start_button.pos.y && y <= start_button.pos.y
				+ start_button.height))
		{
			game->state = GAME;
			toggle_mouse_visibility(game->mlx, game->state);
		}
	}
	return (SUCCESS);
}
