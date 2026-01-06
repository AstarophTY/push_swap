/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:20:41 by sgil--de          #+#    #+#             */
/*   Updated: 2026/01/06 12:20:41 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	clear_stacks(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a)
		ft_lstclear(stack_a);
	if (stack_b && *stack_b)
		ft_lstclear(stack_b);
}

bool	has_duplicates(t_list *lst)
{
	t_list	*cursor;
	t_list	*runner;

	cursor = lst;
	while (cursor)
	{
		runner = cursor->next;
		while (runner)
		{
			if (runner->content == cursor->content)
				return (true);
			runner = runner->next;
		}
		cursor = cursor->next;
	}
	return (false);
}
