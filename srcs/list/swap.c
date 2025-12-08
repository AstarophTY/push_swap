/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-08 20:00:31 by sgil--de          #+#    #+#             */
/*   Updated: 2025-12-08 20:00:31 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap(t_list *lst)
{
	int temp;

	if (!lst || !lst->next)
		return (false);
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	return (true);
}
