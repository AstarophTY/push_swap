/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:01:21 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/08 18:04:21 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*new_node;
	t_list	*new_lst;
	t_list	*temp;
	int		content;

	temp = lst;
	new_lst = NULL;
	while (temp)
	{
		content = f(temp->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			ft_lstclear(&new_lst);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		temp = temp->next;
	}
	return (new_lst);
}
