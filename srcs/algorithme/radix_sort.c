/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:33:26 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/09 16:46:54 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_min_unindexed(t_list *lst)
{
	t_list	*tmp;
	t_list	*min_node;

	min_node = NULL;
	tmp = lst;
	while (tmp)
	{
		if (tmp->index == -1)
		{
			if (!min_node || tmp->content < min_node->content)
				min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

static void	normalize_stack(t_list *lst)
{
	t_list	*min_node;
	int		index;

	init_index(lst);
	index = 0;
	while (1)
	{
		min_node = find_min_unindexed(lst);
		if (!min_node)
			break ;
		min_node->index = index++;
	}
}

static size_t	get_max_bits(t_list *lst)
{
	int		max;
	size_t	bits;

	max = 0;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_iteration(t_list **stack_a, t_list **stack_b,
				size_t bit_pos, size_t size)
{
	size_t	j;
	int		num;

	j = 0;
	while (j < size)
	{
		num = (*stack_a)->index;
		if ((num >> bit_pos) & 1)
			rotate(stack_a, 'a');
		else
			push(stack_b, stack_a, 'b');
		j++;
	}
}

void	radix_sort(t_list **stack_a)
{
	t_list	*stack_b;
	size_t	size;
	size_t	max_bits;
	size_t	i;

	stack_b = NULL;
	if (!stack_a || !*stack_a || is_sorted(*stack_a))
		return ;
	size = ft_lstsize(*stack_a);
	normalize_stack(*stack_a);
	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		radix_iteration(stack_a, &stack_b, i, size);
		while (stack_b)
			push(stack_a, &stack_b, 'a');
		i++;
	}
}
