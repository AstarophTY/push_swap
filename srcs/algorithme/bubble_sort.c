/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:29:25 by tmalpert          #+#    #+#             */
/*   Updated: 2025/12/09 16:57:55 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*bubble_sort(t_list *received)
{
	bool	swapped;
	int		i;

	i = 0;
	if (!received)
        return (NULL);
	swapped = true;
	while (swapped)
	{
		swapped = false;
		while (i < ft_lstsize(received))
		{
			if (received->content > received->next->content)
			{
				swap(received, 'a');
				swapped = true;
			}
			reverse_rotate(&received, 'a');
			i++;
		}
		while (i > 1)
		{
			rotate(&received, 'a');
			i--;
		}
	}
	return (received);
}
