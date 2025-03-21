/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:01:29 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/21 04:47:16 by marvin           ###   ########.fr       */
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

static void	__bonus_player_moves(t_data *data, t_player *player)
{
	t_point	new_ppos;

	new_ppos = (t_point){player->pos.x, player->pos.y};
	if (handle_collisions(data, player, &new_ppos) == FAILURE)
		return ;
	player->pos.x = roundf(new_ppos.x);
	player->pos.y = roundf(new_ppos.y);
}

void	move_player(t_game *game, t_keys *key)
{
	int			i;
	move_array	functions[7];
	t_player	*player;
	
	player = game->player;
	__init_move_array(functions);
	i = 0;
	while (i < 6)
	{
		if (key->key_array[i] == 1)
			functions[i](game);
		i++;
	}
	if (BONUS)
		__bonus_player_moves(game->data, player);
	else
	{
		player->pos.x = roundf(player->pos.x + player->move.x);
		player->pos.y = roundf(player->pos.y + player->move.y);
	}
}

void	reset_move(t_player *player)
{
	player->move.x = 0;
	player->move.y = 0;
}
