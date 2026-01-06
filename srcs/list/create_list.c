/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:24:25 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/08 17:58:57 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*free_null(t_list *head)
{
	ft_lstclear(&head);
	return (NULL);
}

t_list	*create_list(char **array)
{
	t_list	*head;
	t_list	*node;
	size_t	i;

	i = 0;
	head = NULL;
	while (array[i])
	{
		node = ft_lstnew(atoi(array[i]));
		if (!node)
			return (free_null(head));
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}
