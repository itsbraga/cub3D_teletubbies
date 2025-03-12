/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:38:03 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/12 18:28:00 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_game *game)
{
	float	player_angle;

	player_angle = degree_to_radian(game->player->dir);
	game->player->move.x = cos(player_angle) * MOVE_SPEED;
	game->player->move.y = sin(player_angle) * MOVE_SPEED;
}

void	move_backward(t_game *game)
{
	float	player_angle;

	player_angle = degree_to_radian(game->player->dir);
	game->player->move.x = -cos(player_angle) * MOVE_SPEED;
	game->player->move.y = -sin(player_angle) * MOVE_SPEED;
}

void	straf_leftward(t_game *game)
{
	float	player_angle;

	player_angle = degree_to_radian(game->player->dir);
	game->player->move.x = sin(player_angle) * MOVE_SPEED;
	game->player->move.y = -cos(player_angle) * MOVE_SPEED;
}

void	straf_rightward(t_game *game)
{
	float	player_angle;

	player_angle = degree_to_radian(game->player->dir);
	game->player->move.x = -sin(player_angle) * MOVE_SPEED;
	game->player->move.y = cos(player_angle) * MOVE_SPEED;
}
