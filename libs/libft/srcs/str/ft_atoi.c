/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:53:33 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/11 09:16:01 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	long long int	result;
	int				is_neg;

	result = 0;
	is_neg = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			is_neg = -1;
		s++;
	}
	while (ft_isdigit((int)*s))
	{
		if (is_neg == 1 && result > (LLONG_MAX - (*s - '0')) / 10)
			return (-1);
		else if (is_neg == -1 && - result < (LLONG_MIN + (*s - '0')) / 10)
			return (0);
		result = (result * 10) + (*s - '0');
		s++;
	}
	return (result * is_neg);
}
