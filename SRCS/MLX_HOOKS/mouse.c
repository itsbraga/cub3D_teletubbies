/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:44:33 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/16 17:26:00 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	__reset_mouse_position(t_mlx *mlx)
{
	int	center_x;
	int	center_y;

	center_x = WIN_WIDTH / 2;
	center_y = WIN_HEIGHT / 2;
	mlx_mouse_move(mlx->mlx_ptr, mlx->win_ptr, center_x, center_y);
	return (center_x);
}

static int	__handle_mouse_boundaries(int x, int *prev_x, t_mlx *mlx)
{
	if (x < WIN_WIDTH / 10 || x > WIN_WIDTH * 9 / 10)
	{
		*prev_x = __reset_mouse_position(mlx);
		return (1);
	}
	return (0);
}

static int	__mouse_motion(int x, int y, t_game *game)
{
	(void)y;
	static int	prev_x = -1;
	static bool	recentered = false;
	int			delta_x;

	if (prev_x == -1)
		prev_x = x;
	if (__handle_mouse_boundaries(x, &prev_x, game->mlx) == 1)
		return (recentered = true, SUCCESS);
	if (recentered == true)
    {
        recentered = false;
        prev_x = x;
    }
	delta_x = x - prev_x;
	if (delta_x != 0)
	{
		// Ajuste l'angle du joueur selon le deplacement horizontal
		game->player->dir += delta_x * MOUSE_SENSITIVITY_X;
		game->player->dir = norm_h_angle(game->player->dir);
		// MAJ de l'angle en radians pour le raycasting
		game->ray->player_rad = degree_to_radian(game->player->dir);
	}
	prev_x = x;
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
	mlx_mouse_hide(mlx->mlx_ptr, mlx->win_ptr);
	mlx_mouse_hook(mlx->win_ptr, &__title_screen_mouse, game);
	mlx_hook(mlx->win_ptr, MotionNotify, PointerMotionMask, &__mouse_motion,
		game);
}
