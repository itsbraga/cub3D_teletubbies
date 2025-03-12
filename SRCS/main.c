/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/12 22:29:50 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	(void)argv;
	t_data	*data;
	t_game	*game;
	t_mlx	*mlx;

	if (argc != 2)
	{
		err_msg(NULL, strerror(EINVAL));
		ft_printf(STDERR_FILENO, BOLD PY ERR_USAGE RESET);
		exit(FAILURE);
	}
	data = data_s();
	game = game_s();
	mlx = mlx_s();
	init_structs(data, game, mlx);
	// if (parsing(argv[1], data->map) == FAILURE)
	// {
	// 	ft_printf(STDERR_FILENO, BOLD RED ERR RESET);
	// 	clean_exit(FAILURE);
	// }
	// printf("Player position after parsing: %f, %f\n", game->player->pos.x, game->player->pos.y);
	set_hooks(mlx, game);
	mlx_loop_hook(mlx->mlx_ptr, &render, game);
	mlx_loop(mlx->mlx_ptr);
}
