/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:18:37 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/06 10:51:55 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	sub_str = ft_calloc(len + 1, sizeof(char));
	if (!sub_str)
		return (NULL);
	while (i < len && s[i + start])
	{
		sub_str[i] = s[i + start];
		i++;
	}
	return (sub_str);
}
