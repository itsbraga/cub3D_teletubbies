/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:44:33 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/21 19:44:44 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	toggle_mouse_visibility(t_mlx *mlx, t_game_state state)
{
	if (state == TITLE_SCREEN)
		mlx_mouse_show(mlx->mlx_ptr, mlx->win_ptr);
	else
		mlx_mouse_hide(mlx->mlx_ptr, mlx->win_ptr);
}

static int	__handle_mouse_boundaries(int x, int *prev_x, t_mlx *mlx)
{
	int	center_x;
	int	center_y;

	center_x = WIN_WIDTH / 2;
	center_y = WIN_HEIGHT / 2;
	if (x < WIN_WIDTH / 10 || x > WIN_WIDTH * 9 / 10)
	{
		mlx_mouse_move(mlx->mlx_ptr, mlx->win_ptr, center_x, center_y);
		*prev_x = center_x;
		return (1);
	}
	return (0);
}

int	mouse_motion(int x, int y, t_game *game)
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
		game->player->dir += delta_x * MOUSE_SENSITIVITY_X;
		game->player->dir = norm_h_angle(game->player->dir);
		game->ray->player_rad = degree_to_radian(game->player->dir);
	}
	prev_x = x;
	return (SUCCESS);
}
