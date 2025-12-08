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

bool    push(t_list **received, t_list **send)
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
    return (true);
}
