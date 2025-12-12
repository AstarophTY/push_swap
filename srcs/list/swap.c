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

bool	swap(t_list *lst, char stack, t_bench *bench)
{
	int	temp;

	if (!lst || !lst->next)
		return (false);
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	if (stack)
	{
		if (!bench->enabled)
			ft_printf("s%c\n", stack);
		if (stack == 'a')
			bench->sa++;
		else
			bench->sb++;
		bench->total++;
	}
	return (true);
}

bool	multi_swap(t_list *lst1, t_list *lst2, t_bench *bench)
{
	if (swap(lst1, 0, bench) && swap(lst2, 0, bench))
	{
		if (!bench->enabled)
			ft_printf("ss\n");
		bench->ss++;
		bench->total++;
		return (true);
	}
	return (false);
}
