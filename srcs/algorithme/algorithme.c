/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:15:14 by tmalpert          #+#    #+#             */
/*   Updated: 2026/01/06 13:53:27 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_complexity(t_list *received)
{
	double		mistake;
	double		total_pairs;
	t_list		*tmp;
	t_list		*tmp2;

	mistake = 0.0;
	total_pairs = 0.0;
	tmp = received;
	if (ft_lstsize(received) < 2)
		return (0);
	while (tmp)
	{
		if (tmp->next)
			tmp2 = tmp->next;
		while (tmp2)
		{
			total_pairs++;
			if (tmp->content > tmp2->content)
				mistake++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (mistake / total_pairs);
}

void	choose_algorithme(t_flag algo, t_list **lst, double diso, t_bench *bch)
{
	if (algo == simple)
		selection_sort(lst, bch);
	else if (algo == medium)
		chunk_sort(lst, bch);
	else if (algo == complex)
		radix_sort(lst, bch);
	else if (algo == adaptive)
	{
		if (diso < 20)
			selection_sort(lst, bch);
		else if (diso >= 20 && diso < 50)
			chunk_sort(lst, bch);
		else if (diso >= 50)
			radix_sort(lst, bch);
	}
}
