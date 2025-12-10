/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:30:00 by tmalpert          #+#    #+#             */
/*   Updated: 2025/12/10 14:40:39 by tmalpert         ###   ########.fr       */
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

t_list	*insertion_sort(t_list **received)
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
			reverse_rotate(received, 'a');
		push(&tmp, received, 'b');
		i++;
	}
	while (tmp)
		push(received, &tmp, 'a');
	return (tmp);
}










































































