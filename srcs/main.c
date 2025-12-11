/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:11:36 by tmalpert          #+#    #+#             */
/*   Updated: 2025/12/08 18:31:08 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{	
	t_list		*lst;
	t_parsing	*parsing_val;
	char		**strs;

	parsing_val = NULL;
	if (argc < 2 || !parsing(parsing_val, &argv[1], argc - 1))
	{
		if (parsing_val->item_parse)
			free_split(parsing_val->item_parse);
		free(parsing_val);
		ft_putendl_fd("Error", 2);
		return (1);
	}
	// lst = create_list(parsing_val->item_parse);
	// if (!is_sorted(lst))
		// chunk_sort(&lst);
	// ft_lstclear(&lst);
	free(parsing_val);
	return (0);
}
