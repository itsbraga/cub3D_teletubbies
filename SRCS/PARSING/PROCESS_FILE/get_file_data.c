/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:55 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/13 00:46:32 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_file_data(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd, false);
	while (line != NULL)
	{
		if (is_empty_line(line) == true)
		{
			free(line);
			line = get_next_line(fd, false);
			continue;
		}
		if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
			|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
			process_texture_lines(line, data->textures);
		else if (line[0] == 'F' || line[0] == 'C')
			process_color_lines(line, data);
		else if (data->feature_filled == 6 && is_map_line(line) == true)
			fill_map2d_array(data->map, line);
		else
			(err_msg(NULL, ERR_CONFIG), free(line), clean_exit(FAILURE));
		free(line);
		line = get_next_line(fd, false);
	}
}

