/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:30:00 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/21 19:36:52 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map_debug(t_map *map, const char *name)
{
	size_t	i;

	i = 0;
	printf(BOLD PINK "\n%s: " RESET, name);
	printf("[height = %zu, width = %zu]\n", map->height, map->width);
	printf(BOLD PG "Player position: [%f, %f]\n\n" RESET, \
		s_game()->player->pos.x, s_game()->player->pos.y);
	while (i < map->height)
	{
		printf("%s\n", map->map2d[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_game	*game;
	t_mlx	*mlx;

	if (argc != 2)
	{
		err_msg(NULL, strerror(EINVAL));
		ft_printf(STDERR_FILENO, BOLD PY ERR_USAGE RESET);
		exit(FAILURE);
	}
	data = s_data();
	game = s_game();
	mlx = s_mlx();
	init_structs(data, game, mlx);
	if (parsing(argv[1], data, game) == FAILURE)
	{
		ft_printf(STDERR_FILENO, BOLD RED ERR RESET);
		clean_exit(FAILURE);
	}
	print_map_debug(data->map, argv[1]);
	set_hooks(mlx, game);
	// mlx_loop_hook(mlx->mlx_ptr, &render_2d, game);
	mlx_loop_hook(mlx->mlx_ptr, &render_frame, game);
	mlx_loop(mlx->mlx_ptr);
}
