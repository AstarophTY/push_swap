/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:24:53 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/08 14:59:09 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*s1_cpy;
	const unsigned char	*s2_cpy;
	size_t				i;

	i = 0;
	s1_cpy = (const unsigned char *)s1;
	s2_cpy = (const unsigned char *)s2;
	while (s1_cpy[i] && s1_cpy[i] == s2_cpy[i])
		i++;
	return (s1_cpy[i] - s2_cpy[i]);
}
