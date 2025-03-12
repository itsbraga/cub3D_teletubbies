/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:22:58 by annabrag          #+#    #+#             */
/*   Updated: 2025/03/12 18:22:31 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	swap_point(t_point *p0, t_point *p1)
{
	t_point tmp;

	tmp.x = p1->x;
	tmp.y = p1->y;
	p1->x = p0->x;
	p1->y = p0->y;
	p0->x = tmp.x;
	p0->y = tmp.y;
}

bool	valid_point(t_point point, size_t win_x, size_t win_y)
{
	if (point.x > win_x || point.x < 0)
		return (false);
	if (point.y > win_y || point.y < 0)
		return (false);
	return (true);
}
