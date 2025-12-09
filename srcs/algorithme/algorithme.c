/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:15:14 by tmalpert          #+#    #+#             */
/*   Updated: 2025/12/09 16:45:39 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double calculate_complexity(t_list *received)
{
	double		mistake;
	double		total_pairs;
	t_list		*tmp;
	t_list		*tmp2;

	mistake = 0.0;
	total_pairs = 0.0;
	tmp = received;
	while (tmp)
	{
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

void	choose_algorithme(int algo, t_list *received)
{
	double complexity;

	complexity = calculate_complexity(received);
	if (algo == 1)
		bubble_sort(received);
	// else if (algo == 2)
	// 	//algo 2 (medium)
	// 	break;
	// else if (algo == 3)
	// 	//algo 3 (complex)
	// 	break;
	// else if (algo == 4)
	// {
	// 	if (complexity < 0.2)
	// 		//algo 1 (simple)
	// 	else if (complexity >= 0.2 && complexity < 0.5)
	// 		//algo 2 (medium)
	// 	else if (complexity >= 0.5)
	// 		//algo 3 (complex)
	// }
}
