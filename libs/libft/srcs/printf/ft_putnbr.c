/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:54:02 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/14 09:55:47 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		size;

	nb = n;
	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size += ft_putchar('-');
	}
	if (nb >= 10)
	{
		size += ft_putnbr(nb / 10);
		size += ft_putchar((nb % 10) + '0');
	}
	else
		size += ft_putchar((nb % 10) + '0');
	return (size);
}

int	ft_putunbr(unsigned int n)
{
	long	nb;
	int		size;

	nb = n;
	size = 0;
	if (nb >= 10)
	{
		size += ft_putnbr(nb / 10);
		size += ft_putchar((nb % 10) + '0');
	}
	else
		size += ft_putchar((nb % 10) + '0');
	return (size);
}
