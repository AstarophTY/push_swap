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

bool push(t_list **received, t_list **send, char stack)
{
    t_list *temp;

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
    if (send)
    if (stack)
        ft_printf("p%c\n", stack);
    return (true);
}
