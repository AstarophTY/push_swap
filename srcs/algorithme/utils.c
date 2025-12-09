/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:46:17 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/09 16:47:03 by sgil--de         ###   ########.fr       */
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

void	init_index(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}
