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

# include <stdbool.h>
# include "libft.h"

t_list	*create_list(char **array);
t_list	*bubble_sort(t_list *received);
int		is_nb(int argc, char **argv);
char	**get_nb(char **argv);
double	calculate_complexity(t_list *received);
void	index_list(t_list *lst);
bool	lst_contains_index(t_list *lst, int min, int max);
int		find_max_index(t_list *lst);
int		get_position(t_list *lst, int target_index);
t_list	*selection_sort(t_list **received);


bool	swap(t_list *lst, char stack);
bool	push(t_list **received, t_list **send, char stack);
bool	rotate(t_list **lst, char stack);
bool	reverse_rotate(t_list **lst, char stack);
bool	multi_reverse_rotate(t_list **lst1, t_list **lst2);
bool	multi_rotate(t_list **lst1, t_list **lst2);
bool	multi_swap(t_list *lst1, t_list *lst2);

bool	is_sorted(t_list *lst);
void	radix_sort(t_list **lst);
void	chunk_sort(t_list **lst);

#endif