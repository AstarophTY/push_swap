/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:00:00 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/11 19:03:01 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	g_bench;

void	init_bench(bool enabled)
{
	g_bench.sa = 0;
	g_bench.sb = 0;
	g_bench.ss = 0;
	g_bench.pa = 0;
	g_bench.pb = 0;
	g_bench.ra = 0;
	g_bench.rb = 0;
	g_bench.rr = 0;
	g_bench.rra = 0;
	g_bench.rrb = 0;
	g_bench.rrr = 0;
	g_bench.total = 0;
	g_bench.enabled = enabled;
}

static const char	*get_strategy_name(t_flag flag)
{
	if (flag == simple)
		return ("Selection Sort / O(n²)");
	else if (flag == medium)
		return ("Bubble Sort / O(n²)");
	else if (flag == complex)
		return ("Radix Sort / O(n·log(n))");
	else
		return ("Adaptive / O(n√n)");
}

static void	print_disorder(double disorder)
{
	int	integer_part;
	int	decimal_part;

	integer_part = (int)disorder;
	decimal_part = (int)((disorder - integer_part) * 100);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(integer_part, 2);
	ft_putstr_fd(".", 2);
	if (decimal_part < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(decimal_part, 2);
	ft_putendl_fd("%", 2);
}

static void	print_operations(void)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(g_bench.sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(g_bench.sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(g_bench.ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(g_bench.pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(g_bench.pb, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(g_bench.ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(g_bench.rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(g_bench.rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(g_bench.rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(g_bench.rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(g_bench.rrr, 2);
	ft_putendl_fd("", 2);
}

void	print_bench(t_flag flag, int size, double disorder)
{
	if (!g_bench.enabled)
		return ;
	print_disorder(disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putendl_fd((char *)get_strategy_name(flag), 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(g_bench.total, 2);
	ft_putendl_fd("", 2);
	print_operations();
	(void)size;
}
