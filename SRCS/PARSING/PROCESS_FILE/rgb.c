/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:57:10 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/21 02:55:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**__rgb_to_convert(char *line, char **to_convert)
{
	while (ft_isdigit(*line) != 1)
		line++;
	to_convert = ft_split(line, ',');
	secure_malloc(to_convert, true);
	return (to_convert);
}

void	process_color_lines(char *line, t_data *data)
{
	char	**rgb_array;

	rgb_array = NULL;
	if (line[0] == 'F')
	{
		rgb_array = __rgb_to_convert(line, rgb_array);
		data->floor_color = convert_rgb_into_uint(rgb_array[0],
				rgb_array[1], rgb_array[2]);
		data->feature_filled++;
	}
	else
	{
		rgb_array = __rgb_to_convert(line, rgb_array);
		data->ceiling_color = convert_rgb_into_uint(rgb_array[0],
				rgb_array[1], rgb_array[2]);
		data->feature_filled++;
	}
	free_array(rgb_array);
}
