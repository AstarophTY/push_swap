/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:33:26 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/10 10:16:13 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_min(t_list *lst)
{
	t_list	*temp;
	t_list	*min_node;

	min_node = NULL;
	temp = lst;
	while (temp)
	{
		if (temp->index == -1)
		{
			if (!min_node || temp->content < min_node->content)
				min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

static void	index_list(t_list *lst)
{
	t_list	*min_node;
	int		index;

	index = 0;
	while (1)
	{
		min_node = find_min(lst);
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

static void	radix_iteration(t_list **lst, t_list **stack_b, size_t bit_pos, size_t size)
{
	size_t	j;
	int		num;

	j = 0;
	while (j < size)
	{
		num = (*lst)->index;
		if ((num >> bit_pos) & 1)
			rotate(lst, 'a');
		else
			push(stack_b, lst, 'b');
		j++;
	}
}

void	radix_sort(t_list **lst)
{
	t_list	*stack_b;
	size_t	size;
	size_t	max_bits;
	size_t	i;

	stack_b = NULL;
	if (!lst || !*lst || is_sorted(*lst))
		return ;
	size = ft_lstsize(*lst);
	index_list(*lst);
	max_bits = get_max_bits(*lst);
	i = 0;
	while (i < max_bits)
	{
		radix_iteration(lst, &stack_b, i, size);
		while (stack_b)
			push(lst, &stack_b, 'a');
		i++;
	}
}
