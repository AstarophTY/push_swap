/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:32:49 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/10 14:45:40 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_max_to_a(t_list **lst, t_list **stack_b)
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
			rotate(stack_b, 'b');
	}
	else
	{
		while ((*stack_b)->index != max_index)
			reverse_rotate(stack_b, 'b');
	}
	push(lst, stack_b, 'a');
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

static void	while_chunk(t_list **lst, t_list **stack_b, int *values)
{
	if ((*lst)->index >= values[0] && (*lst)->index <= values[1])
	{
		push(stack_b, lst, 'b');
		if ((*stack_b)->index < (values[0] + values[1]) / 2)
			rotate(stack_b, 'b');
	}
	else
		rotate(lst, 'a');
	if (!lst_contains_index(*lst, values[0], values[1]))
	{
		values[0] += values[2];
		values[1] += values[2];
	}
}

void	chunk_sort(t_list **lst)
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
		while_chunk(lst, &stack_b, values);
	while (stack_b)
		push_max_to_a(lst, &stack_b);
}
