/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:18:29 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/06 10:43:38 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(long int n)
{
	size_t	result;

	result = 0;
	if (n < 0)
	{
		result++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	size;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	size = get_size(nb);
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[size - 1] = nb % 10 + '0';
		nb /= 10;
		size--;
	}
	return (str);
}
