/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:44:55 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/21 20:20:03 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*__skip_spaces(char *line)
{
	while (*line != '\0' && (*line == ' ' || *line == '\t'))
		line++;
	return (line);
}

static bool	__is_texture_line(char *trimmed)
{
	if (ft_strncmp(trimmed, "NO", 2) == 0
		|| ft_strncmp(trimmed, "SO", 2) == 0
		|| ft_strncmp(trimmed, "WE", 2) == 0
		|| ft_strncmp(trimmed, "EA", 2) == 0)
		return (true);
	return (false);
}

static bool	__is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '\n' && line[i] != ' ' && line[i] != '\t'
			&& line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
		{
			err_msg_quoted(&line[i], ERR_CHAR);
			return (false);
		}
		i++;
	}
	return (true);
}

static void	__process_line(char *line, char *trimmed, t_data *data)
{
	if (__is_texture_line(trimmed) == true)
		process_texture_lines(trimmed, data->textures);
	else if (trimmed[0] == 'F' || trimmed[0] == 'C')
	{
		#if BONUS
			process_bonus_texture_lines(trimmed, data->textures);
		#else
			process_color_lines(trimmed, data);
		#endif
	}
	else if (data->feature_filled == 6 && __is_map_line(line))
		fill_map2d_array(data->map, line);
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
		trimmed = __skip_spaces(line);
		__process_line(line, trimmed, data);
		free(line);
		line = get_next_line(fd, false);
	}
}
