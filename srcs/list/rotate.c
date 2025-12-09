/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:40:40 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/09 10:51:22 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rotate(t_list **lst, char stack)
{
	t_list	*temp;

	temp = ft_lstlast(*lst);
	if (!temp || temp == *lst)
		return (false);
	if (temp->prev)
		temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *lst;
	*lst = temp;
	if (stack)
		ft_printf("r%c\n", stack);
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
		ft_printf("rr%c\n", stack);
	return (true);
}

bool	multi_reverse_rotate(t_list **lst1, t_list **lst2)
{
	if (reverse_rotate(lst1, 0) && reverse_rotate(lst2, 0))
	{
		printf("rrr\n");
		return (true);
	}
	return (false);
}

bool	multi_rotate(t_list **lst1, t_list **lst2)
{
	if (rotate(lst1, 0) && rotate(lst2, 0))
	{
		printf("rr\n");
		return (true);
	}
	return (false);
}