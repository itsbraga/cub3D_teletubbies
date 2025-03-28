/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:55 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/27 23:57:54 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	__process_line(char *line, char *trimmed, t_data *data)
{
	if (is_wall_texture_line(trimmed) == true)
		process_texture_lines(trimmed, data->textures);
	else if (trimmed[0] == 'F' || trimmed[0] == 'C' || trimmed[0] == 'D')
	{
		#if BONUS
			process_bonus_texture_lines(trimmed, data->textures);
		#else
			process_color_lines(trimmed, data);
		#endif
	}
	#if BONUS
		else if (data->feature_filled == 7 && is_bonus_map_line(line))
			fill_map2d_array(data->map, line);
	#else
		else if (data->feature_filled == 6 && is_map_line(line))
			fill_map2d_array(data->map, line);
	#endif
	else
	{
		err_msg(NULL, ERR_CONFIG);
		free(line);
		clean_exit(FAILURE);
	}
}

void	get_file_data(int fd, t_data *data)
{
	char	*line;
	char	*trimmed;

	line = get_next_line(fd, false);
	while (line != NULL)
	{
		if (is_empty_line(line))
		{
			free(line);
			line = get_next_line(fd, false);
			continue;
		}
		trimmed = skip_spaces(line);
		__process_line(line, trimmed, data);
		free(line);
		line = get_next_line(fd, false);
	}
}
