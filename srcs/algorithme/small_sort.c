/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:10:12 by sgil--de          #+#    #+#             */
/*   Updated: 2026/01/06 13:10:12 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list **lst, t_bench *bench)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->content;
	b = (*lst)->next->content;
	c = (*lst)->next->next->content;
	if (a > b && b < c && a < c)
		swap(*lst, 'a', bench);
	else if (a > b && b > c)
	{
		swap(*lst, 'a', bench);
		reverse_rotate(lst, 'a', bench);
	}
	else if (a > b && b < c && a > c)
		rotate(lst, 'a', bench);
	else if (a < b && b > c && a < c)
	{
		swap(*lst, 'a', bench);
		rotate(lst, 'a', bench);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(lst, 'a', bench);
}

void	sort_small(t_list **lst, t_bench *bench)
{
	if (!lst || !*lst || is_sorted(*lst))
		return ;
	if (ft_lstsize(*lst) == 2)
	{
		if ((*lst)->content > (*lst)->next->content)
			swap(*lst, 'a', bench);
		return ;
	}
	sort_three(lst, bench);
}
