/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:44:33 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/12 21:27:49 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__mouse_motion(int x, int y, t_game *game)
{
	(void)y;
	static int	old_x = WIN_WIDTH / 2;

	if (x == old_x)
		return (SUCCESS);
	else if (x < old_x)
		rotate_leftward(game);
	else if (x > old_x)
		rotate_rightward(game);
	old_x = x;
	return (SUCCESS);
}

static int	__title_screen_mouse(int button, int x, int y, t_game *game)
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
		}
	}
	return (SUCCESS);
}

void	set_mouse_hooks(t_mlx *mlx, t_game *game)
{
	mlx_hook(mlx->win_ptr, MotionNotify, PointerMotionMask, &__mouse_motion,
			game);
	mlx_mouse_hook(mlx->win_ptr, &__title_screen_mouse, game);
}
