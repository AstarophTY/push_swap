/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:53:03 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/05 13:55:24 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_cpy;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	s_cpy = ft_calloc(s_len, sizeof(char));
	if (!s_cpy)
		return (NULL);
	ft_strlcpy(s_cpy, s, s_len);
	return (s_cpy);
}
