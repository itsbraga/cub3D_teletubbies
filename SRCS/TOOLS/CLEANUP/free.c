/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 21:09:30 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/12 18:24:02 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(t_map *map)
{
	if (map->map2d != NULL)
		free_array(map->map2d);
	if (map->path_to_file != NULL)
		my_free((void **)map->path_to_file);
}

void	free_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		my_free((void **)&array[i]);
		i++;
	}
	my_free((void **)&array);
}

void	free_int_array(int **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		my_free((void **)&array[i]);
		i++;
	}
	my_free((void **)&array);
}

void	free_title_screen(t_title_screen *screen)
{
	if (screen->first_layer.img_ptr != NULL)
		del_img(mlx_s(), screen->first_layer.img_ptr);
	if (screen->second_layer.img.img_ptr != NULL)
		del_img(mlx_s(), screen->second_layer.img.img_ptr);
}
