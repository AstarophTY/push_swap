/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:15:14 by tmalpert          #+#    #+#             */
/*   Updated: 2025/12/09 11:39:46 by tmalpert         ###   ########.fr       */
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

// void	choose_algorithme(int algo)
// {
// 	if (algo = 1)
// 		//algo 1 (simple)
// 	else if (algo = 2)
// 		//algo 2 (medium)
// 	else if (algo = 3)
// 		//algo 3 (complex)
// 	else if (algo = 4)
// }
