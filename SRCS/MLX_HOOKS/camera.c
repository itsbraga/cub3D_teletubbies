/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:39:19 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/12 19:18:40 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_leftward(t_game *game)
{
	game->player->dir -= 4;
	if (game->player->dir < 0)
		game->player->dir += 360;
	game->ray->player_rad = degree_to_radian(game->player->dir);
}

void	rotate_rightward(t_game *game)
{
	game->player->dir += 4;
	if (game->player->dir > 360)
		game->player->dir = game->player->dir % 360;
	game->ray->player_rad = degree_to_radian(game->player->dir);
}
