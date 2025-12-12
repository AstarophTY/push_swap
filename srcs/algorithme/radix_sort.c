/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:33:26 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/12 11:15:16 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	radix_iteration(t_list **lst, t_list **s_b, size_t i, t_bench *bch)
{
	size_t	j;
	int		num;
	size_t	size;

	j = 0;
	size = ft_lstsize(*lst);
	while (j < size)
	{
		num = (*lst)->index;
		if ((num >> i) & 1)
			rotate(lst, 'a', bch);
		else
			push(s_b, lst, 'b', bch);
		j++;
	}
}

void	radix_sort(t_list **lst, t_bench *bench)
{
	t_list	*stack_b;
	size_t	max_bits;
	size_t	i;

	stack_b = NULL;
	if (!lst || !*lst || is_sorted(*lst))
		return ;
	index_list(*lst);
	max_bits = get_max_bits(*lst);
	i = 0;
	while (i < max_bits)
	{
		radix_iteration(lst, &stack_b, i, bench);
		while (stack_b)
			push(lst, &stack_b, 'a', bench);
		i++;
	}
}
