/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:33:26 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/09 14:28:37 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (temp && temp->next)
	{
		if (temp && temp->next && temp->content > temp->next->content)
			return (false);
		temp = temp->next;
	}
	return (true);
}

static void	normalize_values(t_list *lst)
{
	t_list	*current;
	t_list	*compare;
	int		index;

	current = lst;
	while (current)
	{
		index = 0;
		compare = lst;
		while (compare)
		{
			if (compare->content < current->content)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

size_t	get_max_bits(t_list *lst)
{
	int		max;
	size_t	bits;

	if (!lst)
		return (0);
	max = lst->index;
	bits = 0;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

bool	radix_sort(t_list **lst)
{
	size_t	size;
	size_t	max_bits;
	t_list	*stack_b;
	size_t	i;
	size_t	j;
	int		num;

	stack_b = NULL;
	size = ft_lstsize(*lst);
	normalize_values(*lst);
	max_bits = get_max_bits(*lst);
	for (i = 0; i < max_bits; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			num = (*lst)->index;
			if ((num >> i) & 1)
				rotate(lst, 'a');
			else
				push(&stack_b, lst, 'b');
		}
		while (stack_b)
			push(lst, &stack_b, 'a');
	}
	return (true);
}
