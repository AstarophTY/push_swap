/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:40:40 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/11 19:03:56 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rotate(t_list **lst, char stack)
{
	t_list	*first;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return (false);
	first = *lst;
	last = ft_lstlast(*lst);
	*lst = first->next;
	(*lst)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	if (stack)
	{
		ft_printf("r%c\n", stack);
		if (stack == 'a')
			g_bench.ra++;
		else
			g_bench.rb++;
		g_bench.total++;
	}
	return (true);
}

bool	reverse_rotate(t_list **lst, char stack)
{
	t_list	*temp;

	temp = ft_lstlast(*lst);
	if (!temp || temp == *lst)
		return (false);
	temp->next = *lst;
	(*lst)->prev = temp;
	temp = (*lst)->next;
	(*lst)->next = NULL;
	*lst = temp;
	(*lst)->prev = NULL;
	if (stack)
	{
		ft_printf("rr%c\n", stack);
		if (stack == 'a')
			g_bench.rra++;
		else
			g_bench.rrb++;
		g_bench.total++;
	}
	return (true);
}

bool	multi_reverse_rotate(t_list **lst1, t_list **lst2)
{
	if (reverse_rotate(lst1, 0) && reverse_rotate(lst2, 0))
	{
		ft_printf("rrr\n");
		g_bench.rrr++;
		g_bench.total++;
		return (true);
	}
	return (false);
}

bool	multi_rotate(t_list **lst1, t_list **lst2)
{
	if (rotate(lst1, 0) && rotate(lst2, 0))
	{
		ft_printf("rr\n");
		g_bench.rr++;
		g_bench.total++;
		return (true);
	}
	return (false);
}