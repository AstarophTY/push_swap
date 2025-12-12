/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:00:00 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/12 11:03:54 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(bool enabled, t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total = 0;
	bench->enabled = enabled;
}

static const char	*get_strategy_name(t_flag flag, double disorder)
{
	if (flag == simple)
		return ("Selection Sort / O(n²)");
	else if (flag == medium)
		return ("Chunk Sort / O(n√n)");
	else if (flag == complex)
		return ("Radix Sort / O(n·log(n))");
	else
	{
		if (disorder < 20)
			return ("Adaptive / O(n²)");
		else if (disorder >= 20 && disorder < 50)
			return ("Adaptive / O(n√n)");
		else if (disorder >= 50)
			return ("Adaptive / O(n·log(n))");
	}
	return (NULL);
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

static void	print_operations(t_bench *bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd("  ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd("  pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd("  pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd("  rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd("  rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd("  rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd("  rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd("  rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putendl_fd("", 2);
}

void	print_bench(t_flag flag, double disorder, t_bench *bench)
{
	if (!bench->enabled)
		return ;
	print_disorder(disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putendl_fd((char *)get_strategy_name(flag, disorder), 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total, 2);
	ft_putendl_fd("", 2);
	print_operations(bench);
}
