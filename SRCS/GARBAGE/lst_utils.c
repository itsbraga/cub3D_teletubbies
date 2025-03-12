/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:32:30 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/12 19:04:20 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*new_gc_node(void *ptr, bool is_tab)
{
	t_gc_lst	*node;

	node = malloc(sizeof(t_gc_lst));
	if (node == NULL)
		return (err_msg(NULL, ERR_MALLOC), NULL);
	node->ptr = ptr;
	node->is_array = is_tab;
	node->next = NULL;
	return (node);
}

static t_gc_lst	*__last_gc_lst_node(t_gc_lst *yama)
{
	if (yama == NULL)
		return (NULL);
	while (yama->next != NULL)
		yama = yama->next;
	return (yama);
}

void	add_gc_node(t_gc_lst **yama, t_gc_lst *node)
{
	t_gc_lst	*tmp;

	if (*yama == NULL)
		*yama = node;
	else
	{
		tmp = __last_gc_lst_node(*yama);
		tmp->next = node;
	}
}

int	remove_gc_node(t_gc_lst **yama, void *ptr)
{
	t_gc_lst	*node;
	t_gc_lst	*prev;

	if (yama == NULL || *yama == NULL)
		return (FAILURE);
	if ((*yama)->ptr == ptr)
	{
		node = *yama;
		*yama = (*yama)->next;
		my_free((void **)&node->ptr);
		my_free((void **)&node);
		return (SUCCESS);
	}
	prev = *yama;
	while (prev->next != NULL && prev->next->ptr != ptr)
		prev = prev->next;
	node = prev->next;
	prev->next = (prev->next)->next;
	my_free((void **)&node->ptr);
	my_free((void **)&node);
	return (SUCCESS);
}
