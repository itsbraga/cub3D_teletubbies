/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_xpm_from_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:33:51 by art3mis           #+#    #+#             */
/*   Updated: 2025/03/04 15:28:50 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_img	xpm_to_mlx_img(char *relative_path)
{
	t_img	img;

	ft_memset(&img, 0, sizeof(t_img));
	img.img_ptr = mlx_xpm_file_to_image(s_mlx()->mlx_ptr, relative_path,
			&img.width,
			&img.height);
	if (img.img_ptr == NULL)
	{
		err_msg("minilibX", ERR_XPM);
		return (img);
	}
	img.addr = mlx_get_data_addr(img.img_ptr,
			&img.bits_per_pixel,
			&img.size_line,
			&img.endian);
	if (img.addr == NULL)
	{
		err_msg("minilibX", ERR_ADDR);
		del_img(s_mlx(), img.img_ptr);
		ft_memset(&img, 0, sizeof(t_img));
	}
	return (img);
}
