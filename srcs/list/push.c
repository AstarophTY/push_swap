/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-08 20:08:10 by sgil--de          #+#    #+#             */
/*   Updated: 2025-12-08 20:08:10 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push(t_list **received, t_list **send, char stack, t_bench *bench)
{
	t_list	*temp;

	if (!send || !*send)
		return (false);
	temp = *send;
	*send = temp->next;
	if (*send)
		(*send)->prev = NULL;
	temp->next = *received;
	if (*received)
		(*received)->prev = temp;
	temp->prev = NULL;
	*received = temp;
	if (stack)
	{
		if (!bench->enabled)
			ft_printf("p%c\n", stack);
		if (stack == 'a')
			bench->pa++;
		else
			bench->pb++;
		bench->total++;
	}
	return (true);
}
