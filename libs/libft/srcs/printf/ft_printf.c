/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:10:59 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/27 14:53:23 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_getprint(va_list marker, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(marker, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(marker, char *)));
	else if (c == 'x')
		return (ft_puthex(va_arg(marker, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex(va_arg(marker, unsigned int), 1));
	else if (c == 'p')
		return (ft_putaddr(va_arg(marker, void *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(marker, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(marker, unsigned int)));
	else
		return (ft_putchar('%'));
}

int	ft_printf(const char *s, ...)
{
	int		writen;
	va_list	marker;

	if (!s)
		return (-1);
	writen = 0;
	va_start(marker, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			writen += ft_getprint(marker, *s++);
		}
		else
			writen += write(1, s++, 1);
	}
	va_end(marker);
	return (writen);
}
