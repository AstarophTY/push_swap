/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:30:00 by tmalpert          #+#    #+#             */
/*   Updated: 2026/01/06 19:09:57 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int min, t_list *tmp2)
{
	while (tmp2)
	{
		if (tmp2->content < min)
			min = tmp2->content;
		tmp2 = tmp2->next;
	}
	return (min);
}

t_list	*selection_sort(t_list **received, t_bench *bench)
{
	int		min;
	t_list	*tmp;
	t_list	*tmp2;
	size_t	i;
	size_t	size;

	i = 0;
	tmp = NULL;
	size = ft_lstsize(*received);
	while (i < size)
	{
		tmp2 = *received;
		min = tmp2->content;
		min = ft_min(min, tmp2);
		while ((*received)->content != min)
			rotate(received, 'a', bench);
		push(&tmp, received, 'b', bench);
		i++;
	}
	while (tmp)
		push(received, &tmp, 'a', bench);
	return (*received);
}
