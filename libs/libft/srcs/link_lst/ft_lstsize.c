/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:25:16 by sgil--de          #+#    #+#             */
/*   Updated: 2025/11/06 17:06:09 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*temp;

	if (!lst)
		return (0);
	len = 0;
	temp = lst;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
