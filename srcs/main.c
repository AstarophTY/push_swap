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

void	ft_putnbr1(int nb)
{
	ft_printf("%d\n", nb);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	char	**strs;
	int		flag;

	flag = is_nb(argc, argv);
	if (flag == 0)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	strs = get_nb(argv);
	lst = create_list(strs);
	if (!is_sorted(lst))
		radix_sort(&lst);
	ft_lstiter(lst, &ft_putnbr1);
	ft_lstclear(&lst);
	return (0);
}
