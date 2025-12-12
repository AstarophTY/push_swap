/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:46:02 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/12 11:14:15 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	lst_contains_index(t_list *lst, int min, int max)
{
	while (lst)
	{
		if (lst->index >= min && lst->index <= max)
			return (true);
		lst = lst->next;
	}
	return (false);
}

int	find_max_index(t_list *lst)
{
	int	max;

	max = lst->index;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	return (max);
}

int	get_position(t_list *lst, int target_index)
{
	int	pos;

	pos = 0;
	while (lst)
	{
		if (lst->index == target_index)
			return (pos);
		pos++;
		lst = lst->next;
	}
	return (0);
}
