/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:20:42 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/13 03:35:36 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_empty_line(char *line)
{
	while (*line != '\0')
	{
		if (ft_isspace(*line) == 0)
			return (false);
		line++;
	}
	return (true);
}

size_t	get_longest_line(char **map2d, size_t height)
{
	size_t	i;
	size_t	max;
	size_t	len;

	i = 0;
	max = 0;
	len = 0;
	while (i < height)
	{
		len = ft_strlen(map2d[i]) - 1;
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

unsigned int	convert_rgb_into_uint(char *red, char *green, char *blue)
{
	int	result;
	int	r;
	int	g;
	int	b;

	result = 0;
	r = ft_atoi(red, &result);
	if (r < 0 || r > 255)
		(err_msg(NULL, ERR_RGB), exit(FAILURE)); // a voir si free qqch
	g = ft_atoi(green, &result);
	if (g < 0 || g > 255)
		(err_msg(NULL, ERR_RGB), exit(FAILURE)); // a voir si free qqch
	b = ft_atoi(blue, &result);
	if (b < 0 || b > 255)
		(err_msg(NULL, ERR_RGB), exit(FAILURE)); // a voir si free qqch
	result = (r << 16);
	result = result | (g << 8);
	result = result | (b);
	return ((unsigned int)result);
}
