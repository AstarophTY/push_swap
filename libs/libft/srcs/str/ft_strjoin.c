/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:23:22 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/05 14:29:17 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str_trim;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	str_trim = ft_calloc(s1_len + ft_strlen(s2) + 1, sizeof(char));
	if (!str_trim)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_trim[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str_trim[i + s1_len] = s2[i];
		i++;
	}
	return (str_trim);
}
