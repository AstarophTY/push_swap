/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:36:55 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/06 10:51:33 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	size_t	end;
	size_t	start;

	end = ft_strlen(s);
	start = 0;
	if (!s || !set)
		return (NULL);
	while (s[end - 1] && ft_strchr(set, s[end - 1]))
		end--;
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	return (ft_substr(s, (unsigned int)start, end - start));
}
