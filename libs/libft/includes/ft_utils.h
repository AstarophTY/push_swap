/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:54:39 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/27 13:35:03 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_puthex(uintptr_t n, int is_upper);
int	ft_putaddr(void *ptr);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);

#endif