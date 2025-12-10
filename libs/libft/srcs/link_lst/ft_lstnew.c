/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:25:12 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/08 16:11:48 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*obj;

	obj = ft_calloc(1, sizeof(t_list));
	if (!obj)
		return (NULL);
	obj->content = content;
	obj->index = -1;
	obj->next = NULL;
	return (obj);
}
