/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:19:51 by tmalpert          #+#    #+#             */
/*   Updated: 2025/12/08 18:28:08 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// a enlever
# include <stdio.h>
//-----------

# include <stdbool.h>
# include "libft.h"

t_list	*create_list(char **array);
int		is_nb(int argc, char **argv);
char	**get_nb(char **argv);

bool	swap(t_list *lst);
bool	push(t_list **received, t_list **send);

#endif