/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:58:48 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/12 18:23:48 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	secure_malloc(void *to_secure, bool full_clean)
{
	if (to_secure == NULL)
	{
		err_msg("malloc", strerror(errno));
		if (full_clean == true)
			clean_exit(FAILURE);
	}
}

void	my_free(void **to_free)
{
	if (to_free != NULL && (*to_free) != NULL)
	{
		free(*to_free);
		*to_free = NULL;
	}
}
