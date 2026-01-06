/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:15:42 by sgil--de          #+#    #+#             */
/*   Updated: 2026/01/06 12:15:42 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

bool	build_stack(t_list **stack_a, char **argv);
bool	read_operations(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	clear_stacks(t_list **stack_a, t_list **stack_b);
bool	has_duplicates(t_list *lst);

#endif
