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

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_list	*lst1;
	char	**strs;

	lst1 = NULL;
	if (is_nb(argc, argv) == 0)
		return (0);
	strs = get_nb(argv);
	lst = create_list(strs);
	push(&lst1, &lst);
	ft_lstiter(lst, &ft_putnbr);
	printf("------\n");
	ft_lstiter(lst1, &ft_putnbr);
	ft_lstclear(&lst);
	return (42);
}
