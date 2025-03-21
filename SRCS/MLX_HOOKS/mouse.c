/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:44:33 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/20 21:16:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

static void	__handle_mouse_boundaries(int x, int *prev_x, t_mlx *mlx)
{
	if (x < WIN_WIDTH / 10 || x > WIN_WIDTH * 9 / 10)
	{
		*prev_x = WIN_WIDTH / 2;
		mlx_mouse_move(mlx->mlx_ptr, mlx->win_ptr, *prev_x, WIN_HEIGHT / 2);
	}
}

int	mouse_motion(int x, int y, t_game *game)
{
	(void)y;
	static int	prev_x = -1;
	int			delta_x;

	if (prev_x == -1)
		prev_x = x;
	__handle_mouse_boundaries(x, &prev_x, game->mlx);
	delta_x = x - prev_x;
	if (delta_x != 0)
	{
		game->player->dir += delta_x * MOUSE_SENSITIVITY_X;
		game->player->dir = norm_h_angle(game->player->dir);
		game->ray->player_rad = degree_to_radian(game->player->dir);
	}
	prev_x = x;
	return (SUCCESS);
}
