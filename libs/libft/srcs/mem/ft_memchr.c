/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:30:30 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/06 17:06:10 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*s_cpy;
	size_t		i;

	if (n == 0)
		return (0);
	i = 0;
	s_cpy = (const char *)s;
	while (i < n)
	{
		if (s_cpy[i] == (char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
