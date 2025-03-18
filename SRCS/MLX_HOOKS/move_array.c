/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:01:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/18 01:09:39 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__init_move_array(move_array *functions)
{
	functions[0] = move_forward;
	functions[1] = move_backward; 
	functions[2] = straf_leftward; 
	functions[3] = straf_rightward; 
	functions[4] = rotate_leftward;
	functions[5] = rotate_rightward;
	functions[6] = NULL;
}

static void	__bonus_player_moves(t_data *data, t_game *game)
{
	t_point		new_player_pos;

	new_player_pos.x = game->player->pos.x;
	new_player_pos.y = game->player->pos.y;
	if (handle_collisions(data, game->player, &new_player_pos) == FAILURE)
		return ;
	game->player->pos.x = roundf(new_player_pos.x);
	game->player->pos.y = roundf(new_player_pos.y);
}

void	move_player(t_game *game, t_keys *key)
{
	int			i;
	move_array	functions[7];
	t_player	*player;
	
	i = 0;
	player = game->player;
	__init_move_array(functions);
	while (i < 6)
	{
		if (key->key_array[i] == 1)
			functions[i](game);
		i++;
	}
	if (!BONUS)
	{
		player->pos.x = roundf(player->pos.x + player->move.x);
		player->pos.y = roundf(player->pos.y + player->move.y);
		// printf(BOLD BLUE "player dir: [%d]\n" RESET, player->dir);
	}
	else
		__bonus_player_moves(s_data(), game);
}

void	reset_move(t_player *player)
{
	player->move.x = 0;
	player->move.y = 0;
}
