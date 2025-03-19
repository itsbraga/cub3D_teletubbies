/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>            	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 06:27:16 by pmateo            #+#    #+#             */
/*   Updated: 2025/03/19 03:26:56 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ps;

	ps = (unsigned char *)s;
	while (n--)
	{
		*ps = c;
		ps++;
	}
	return (s);
}

/*int	main(void)
{
	char	str[20];

	ft_memset(str, 97, sizeof(str));
	printf("%s\n", str);
	printf("%ld", sizeof(str));
}*/