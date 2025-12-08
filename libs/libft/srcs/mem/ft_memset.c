/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:20:46 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/04 14:41:36 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str_cpy;

	i = 0;
	str_cpy = (char *)s;
	while (i < n)
		str_cpy[i++] = (char)c;
	return (s);
}
