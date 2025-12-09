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

void	ft_putnbr1(int n)
{
	ft_putnbr_fd(n, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	char	**strs;
	t_list	*lst1;

	lst1 = NULL;
	if (is_nb(argc, argv) == 0)
		return (0);
	strs = get_nb(argv);
	lst = create_list(strs);
	if (!is_sorted(lst))
		bubble_sort(lst);
	// push(&lst1, &lst, 'a');
	// push(&lst1, &lst, 'a');
	// push(&lst1, &lst, 'a');
	// ft_lstiter(lst, &ft_putnbr1);
	ft_lstclear(&lst);
	return (0);
}
