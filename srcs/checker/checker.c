/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:17:18 by sgil--de          #+#    #+#             */
/*   Updated: 2026/01/06 12:17:18 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	print_error(t_list **stack_a, t_list **stack_b)
{
	clear_stacks(stack_a, stack_b);
	ft_putendl_fd("Error", 2);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_bench	bench;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!build_stack(&stack_a, &argv[1]))
		return (print_error(&stack_a, &stack_b));
	init_bench(false, &bench);
	if (!read_operations(&stack_a, &stack_b, &bench))
		return (print_error(&stack_a, &stack_b));
	if (is_sorted(stack_a) && !stack_b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	clear_stacks(&stack_a, &stack_b);
	return (0);
}
