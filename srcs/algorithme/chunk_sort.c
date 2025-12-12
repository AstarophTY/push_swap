/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:32:49 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/12 11:14:09 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_max_to_a(t_list **lst, t_list **stack_b, t_bench *bench)
{
	int	max_index;
	int	pos;
	int	size;

	max_index = find_max_index(*stack_b);
	pos = get_position(*stack_b, max_index);
	size = ft_lstsize(*stack_b);
	if (pos <= size / 2)
	{
		while ((*stack_b)->index != max_index)
			rotate(stack_b, 'b', bench);
	}
	else
	{
		while ((*stack_b)->index != max_index)
			reverse_rotate(stack_b, 'b', bench);
	}
	push(lst, stack_b, 'a', bench);
}

static void	init_chunk_values(int *values, size_t size)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size * chunk_size < (int)size)
		chunk_size++;
	values[0] = 0;
	values[1] = chunk_size - 1;
	values[2] = chunk_size;
}

static void	while_chunk(t_list **lst, t_list **stack_b, int *val, t_bench *bch)
{
	if ((*lst)->index >= val[0] && (*lst)->index <= val[1])
	{
		push(stack_b, lst, 'b', bch);
		if ((*stack_b)->index < (val[0] + val[1]) / 2)
			rotate(stack_b, 'b', bch);
	}
	else
		rotate(lst, 'a', bch);
	if (!lst_contains_index(*lst, val[0], val[1]))
	{
		val[0] += val[2];
		val[1] += val[2];
	}
}

void	chunk_sort(t_list **lst, t_bench *bench)
{
	t_list	*stack_b;
	size_t	size;
	int		values[3];

	stack_b = NULL;
	if (!lst || !*lst || is_sorted(*lst))
		return ;
	size = ft_lstsize(*lst);
	index_list(*lst);
	init_chunk_values(values, size);
	while (*lst)
		while_chunk(lst, &stack_b, values, bench);
	while (stack_b)
		push_max_to_a(lst, &stack_b, bench);
}
