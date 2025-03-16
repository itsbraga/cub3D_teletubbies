/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:39:53 by u4s2e0r           #+#    #+#             */
/*   Updated: 2025/03/06 19:03:27 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__free_data(t_data *data)
{
	if (data != NULL)
	{
		if (data->map != NULL)
			free_map(data->map);
		// if (data->texture != NULL)
		// 	del_img(s_mlx(), data->texture->img_ptr); x4
	}
}

static void	__free_game(t_game *game)
{
	if (game != NULL)
	{
		// if (game->player != NULL)
		//
		// if (game->keys != NULL)
		// 	// free_keys func
	}
}

void	free_mlx(t_mlx *mlx)
{
	ft_printf(STDERR_FILENO, BOLD PY MLX_EXIT RESET);
	if (mlx != NULL)
	{
		if (mlx->img.img_ptr != NULL)
			mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
		if (mlx->win_ptr != NULL)
			mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		if (mlx->mlx_ptr != NULL)
		{
			mlx_destroy_display(mlx->mlx_ptr);
			free(mlx->mlx_ptr);
			mlx->mlx_ptr = NULL;
		}
	}
}

int	exit_game(t_mlx *mlx, int exit_code)
{
	free_mlx(mlx);
	exit(exit_code);
}

void	clean_exit(int exit_code)
{
	free_title_screen(&s_game()->title_screen);
	if (s_data() != NULL)
		__free_data(s_data());
	if (s_game() != NULL)
		__free_game(s_game());
	// yama(CLEAN_ALL, NULL, 0);
	exit_game(s_mlx(), exit_code);
}
