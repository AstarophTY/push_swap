/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:11:36 by tmalpert          #+#    #+#             */
/*   Updated: 2025/12/11 18:31:08 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cleanup(t_parsing *parsing_val, t_list *lst)
{
	if (parsing_val)
	{
		if (parsing_val->item_parse)
			free_split(parsing_val->item_parse);
		free(parsing_val);
	}
	if (lst)
		ft_lstclear(&lst);
}

static int	error(t_parsing **parsing_val, int error_id)
{
	cleanup(parsing_val, NULL);
	ft_putendl_fd("Error", 2);
	return (error_id);
}

int	main(int argc, char **argv)
{
	t_list		*lst;
	t_parsing	*parsing_val;
	double		disorder;
	t_bench		bench;

	if (argc < 2)
		return (0);
	parsing_val = ft_calloc(1, sizeof(t_parsing));
	if (!parsing_val || !parsing(parsing_val, &argv[1], argc - 1))
		return (error(&parsing_val, 1));
	lst = create_list(parsing_val->item_parse);
	parsing_val->item_parse = NULL;
	if (!lst)
		return (error(&parsing_val, 1));
	init_bench(parsing_val->bench_state, &bench);
	disorder = calculate_complexity(lst) * 100;
	if (!is_sorted(lst))
		choose_algorithme(parsing_val->flag, &lst, disorder, &bench);
	if (parsing_val->bench_state)
		print_bench(parsing_val->flag, disorder, &bench);
	cleanup(parsing_val, lst);
	return (0);
}
