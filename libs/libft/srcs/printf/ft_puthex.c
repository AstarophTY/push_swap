/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:20:02 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/14 09:55:43 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_puthex(uintptr_t n, int is_upper)
{
	char	*hex;
	int		size;

	size = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		size += ft_puthex(n / 16, is_upper);
	if (is_upper && hex[n % 16] >= 'a' && hex[n % 16] <= 'f')
		size += ft_putchar(hex[n % 16] - 32);
	else
		size += ft_putchar(hex[n % 16]);
	return (size);
}
