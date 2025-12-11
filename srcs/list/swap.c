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

bool	swap(t_list *lst, char stack)
{
	int temp;

	if (!lst || !lst->next)
		return (false);
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	if (stack)
	{
		ft_printf("s%c\n", stack);
		if (stack == 'a')
			g_bench.sa++;
		else
			g_bench.sb++;
		g_bench.total++;
	}
	return (true);
}

bool	multi_swap(t_list *lst1, t_list *lst2)
{
	if (swap(lst1, 0) && swap(lst2, 0))
	{
		ft_printf("ss\n");
		g_bench.ss++;
		g_bench.total++;
		return (true);
	}
	return (false);
}