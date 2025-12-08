/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:38:14 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/06 15:35:35 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_cpy;
	const char unsigned	*s2_cpy;
	size_t				i;

	i = 0;
	s1_cpy = (const unsigned char *)s1;
	s2_cpy = (const unsigned char *)s2;
	if (!n)
		return (0);
	while (i < n - 1 && s1_cpy[i] == s2_cpy[i])
		i++;
	if (s1_cpy[i] > s2_cpy[i])
		return (1);
	else if (s1_cpy[i] < s2_cpy[i])
		return (-1);
	return (0);
}
