/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:40:16 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/11 08:48:59 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_cpy;
	const char	*src_cpy;

	if (!dest && !src)
		return (NULL);
	dest_cpy = (char *)dest;
	src_cpy = (const char *)src;
	if (dest_cpy < src_cpy)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		dest_cpy[n - 1] = src_cpy[n - 1];
		n--;
	}
	return (dest);
}
