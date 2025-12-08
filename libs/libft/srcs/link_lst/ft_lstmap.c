/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:01:21 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/11 13:33:31 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_node;
	t_list	*new_lst;
	t_list	*temp;
	void	*content;

	temp = lst;
	new_lst = NULL;
	while (temp)
	{
		content = f(temp->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			if (del)
				del(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		temp = temp->next;
	}
	return (new_lst);
}
