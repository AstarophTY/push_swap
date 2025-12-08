/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:45:31 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/10 17:37:06 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *f, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!f[0] && !s[0])
		return ((char *)s);
	if (!f[0])
		return ((char *)s);
	while (i < n && s[i])
	{
		if (s[i] == f[0])
		{
			j = 0;
			while (i + j < n && f[j] && s[i + j] && s[i + j] == f[j])
				j++;
			if (!f[j])
				return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}
