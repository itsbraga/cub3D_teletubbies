/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:25:59 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/12 19:04:54 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*__append_strs(char *s1, char *s2)
{
	char	*tmp;

	if (s2 == NULL)
		return (s1);
	if (s1 == NULL)
		return (yama(ADD, ft_strdup(s2), 0));
	tmp = s1;
	s1 = ft_strjoin(tmp, s2);
	secure_malloc(s1, true);
	(void)yama(ADD, s1, 0);
	return (s1);
}

void	err_msg(char *context, char *reason)
{
	char	*msg;

	msg = NULL;
	if (context != NULL)
	{
		msg = __append_strs(__append_strs(NULL, ERR_PREFIX), context);
		msg = __append_strs(msg, ": ");
		msg = __append_strs(msg, reason);
	}
	else
		msg = __append_strs(__append_strs(NULL, ERR_PREFIX), reason);
	ft_putendl_fd(msg, STDERR_FILENO);
	yama(REMOVE, msg, 0);
}

void	err_msg_quoted(char *context, char *reason)
{
	char	*msg;

	msg = NULL;
	if (context != NULL)
	{
		msg = __append_strs(__append_strs(NULL, ERR_PREFIX), "‘");
		msg = __append_strs(__append_strs(msg, context), "’");
		msg = __append_strs(msg, ": ");
		msg = __append_strs(msg, reason);
	}
	else
		msg = __append_strs(__append_strs(NULL, ERR_PREFIX), reason);
	ft_putendl_fd(msg, STDERR_FILENO);
	yama(REMOVE, msg, 0);
}
