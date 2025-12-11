/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:46:17 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/11 17:41:42 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content)
			return (false);
		lst = lst->next;
	}
	return (true);
}

static t_list	*find_min(t_list *lst)
{
	t_list	*temp;
	t_list	*min_node;

	min_node = NULL;
	temp = lst;
	while (temp)
	{
		if (temp->index == -1)
		{
			if (!min_node || temp->content < min_node->content)
				min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

void	index_list(t_list *lst)
{
	t_list	*min_node;
	int		index;

	index = 0;
	min_node = NULL;
	while (min_node || !index)
	{
		min_node = find_min(lst);
		if (!min_node)
			break ;
		min_node->index = index++;
	}
}

double	calculate_disorder(t_list *lst)
{
	int		inversions;
	int		size;
	int		max_inversions;
	t_list	*current;
	t_list	*runner;

	inversions = 0;
	size = ft_lstsize(lst);
	current = lst;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->content > runner->content)
				inversions++;
			runner = runner->next;
		}
		current = current->next;
	}
	max_inversions = (size * (size - 1)) / 2;
	if (max_inversions == 0)
		return (0.0);
	return ((double)inversions / max_inversions * 100.0);
}