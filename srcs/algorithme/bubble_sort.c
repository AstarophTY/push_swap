/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:29:25 by tmalpert          #+#    #+#             */
/*   Updated: 2025/12/09 14:36:21 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*bubble_sort(t_list *received)
{
	t_list 		*tmp;
	bool		swapped;

	if (!received)
        return (NULL);
	swapped = true;
	while (swapped)
	{
		swapped = false;
		tmp = received;
		while (tmp && tmp->next)
		{
			if (tmp->content > tmp->next->content)
			{
				swap(tmp, 'a');
				swapped = true;
			}
			tmp=tmp->next;
		}
	}
	return (received);
}
