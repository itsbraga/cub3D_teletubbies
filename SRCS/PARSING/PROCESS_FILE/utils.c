/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:50:46 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/27 23:57:19 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*skip_spaces(char *line)
{
	while (*line != '\0' && (*line == ' ' || *line == '\t'))
		line++;
	return (line);
}

bool	is_wall_texture_line(char *trimmed)
{
	if (ft_strncmp(trimmed, "NO", 2) == 0
		|| ft_strncmp(trimmed, "SO", 2) == 0
		|| ft_strncmp(trimmed, "WE", 2) == 0
		|| ft_strncmp(trimmed, "EA", 2) == 0)
		return (true);
	return (false);
}

bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '\n' && line[i] != '\t'
			&& ft_strchr(VALID_MAP, line[i]) == NULL)
		{
			err_msg_quoted(&line[i], ERR_CHAR);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	is_bonus_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '\n' && line[i] != '\t'
			&& ft_strchr(VALID_BONUS_MAP, line[i]) == NULL)
		{
			err_msg_quoted(&line[i], ERR_CHAR);
			return (false);
		}
		i++;
	}
	return (true);
}
