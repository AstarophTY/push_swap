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

typedef enum e_flag
{
	simple = 1,
	medium = 2,
	complex = 3,
	adaptive = 4,
}	t_flag;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
	bool	enabled;
}	t_bench;

typedef struct s_parsing
{
	bool	bench_state;
	t_flag	flag;
	char	**item_parse;
}	t_parsing;

t_list	*create_list(char **array);
double	calculate_complexity(t_list *received);
void	index_list(t_list *lst);
bool	lst_contains_index(t_list *lst, int min, int max);
int		find_max_index(t_list *lst);
int		get_position(t_list *lst, int target_index);
t_list	*selection_sort(t_list **received, t_bench *bench);
bool	parsing(t_parsing *parsing, char **strs);
void	choose_algorithme(t_flag a, t_list **r, double d, t_bench *b);
bool	has_duplicates(t_list *lst);

bool	swap(t_list *lst, char stack, t_bench *bench);
bool	push(t_list **received, t_list **send, char stack, t_bench *bench);
bool	rotate(t_list **lst, char stack, t_bench *bench);
bool	reverse_rotate(t_list **lst, char stack, t_bench *bench);
bool	multi_reverse_rotate(t_list **lst1, t_list **lst2, t_bench *bench);
bool	multi_rotate(t_list **lst1, t_list **lst2, t_bench *bench);
bool	multi_swap(t_list *lst1, t_list *lst2, t_bench *bench);

bool	is_sorted(t_list *lst);
void	radix_sort(t_list **lst, t_bench *bench);
void	chunk_sort(t_list **lst, t_bench *bench);
void	sort_small(t_list **lst, t_bench *bench);

void	init_bench(bool enabled, t_bench *bench);
void	print_bench(t_flag flag, double disorder, t_bench *bench);

#endif