/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:46:17 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/10 12:33:33 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content)
			return (false);
		lst = lst->next;
	}
	return (true);
}

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

void	index_list(t_list *lst)
{
	t_list	*min_node;
	int		index;

	index = 0;
	min_node = NULL;
	while (min_node || !index)
	{
		min_node = find_min(lst);
		if (!min_node)
			break ;
		min_node->index = index++;
	}
}