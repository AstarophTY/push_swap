/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:40:40 by sgil--de          #+#    #+#             */
/*   Updated: 2026/01/02 08:57:27 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rotate(t_list **lst, char stack, t_bench *bench)
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
		if (!bench->enabled)
			ft_printf("r%c\n", stack);
		if (stack == 'a')
			bench->ra++;
		else
			bench->rb++;
		bench->total++;
	}
	return (true);
}

bool	reverse_rotate(t_list **lst, char stack, t_bench *bench)
{
	t_list	*last;
	t_list	*before_last;

	if (!lst || !*lst || !(*lst)->next)
		return (false);
	last = ft_lstlast(*lst);
	before_last = last->prev;
	if (before_last)
		before_last->next = NULL;
	last->prev = NULL;
	last->next = *lst;
	(*lst)->prev = last;
	*lst = last;
	if (stack)
	{
		if (!bench->enabled)
			ft_printf("rr%c\n", stack);
		if (stack == 'a')
			bench->rra++;
		else
			bench->rrb++;
		bench->total++;
	}
	return (true);
}

bool	multi_reverse_rotate(t_list **lst1, t_list **lst2, t_bench *bench)
{
	if (reverse_rotate(lst1, 0, bench) && reverse_rotate(lst2, 0, bench))
	{
		if (!bench->enabled)
			ft_printf("rrr\n");
		bench->rrr++;
		bench->total++;
		return (true);
	}
	return (false);
}

bool	multi_rotate(t_list **lst1, t_list **lst2, t_bench *bench)
{
	if (rotate(lst1, 0, bench) && rotate(lst2, 0, bench))
	{
		if (!bench->enabled)
			ft_printf("rr\n");
		bench->rr++;
		bench->total++;
		return (true);
	}
	return (false);
}
