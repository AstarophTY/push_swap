/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:19:44 by sgil--de          #+#    #+#             */
/*   Updated: 2026/01/06 12:19:44 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	apply_swap_push(const char *op, t_list **stack_a,
			t_list **stack_b, t_bench *bench)
{
	if (!ft_strcmp(op, "sa"))
		swap(*stack_a, 'a', bench);
	else if (!ft_strcmp(op, "sb"))
		swap(*stack_b, 'b', bench);
	else if (!ft_strcmp(op, "ss"))
		multi_swap(*stack_a, *stack_b, bench);
	else if (!ft_strcmp(op, "pa"))
		push(stack_a, stack_b, 'a', bench);
	else if (!ft_strcmp(op, "pb"))
		push(stack_b, stack_a, 'b', bench);
	else
		return (false);
	return (true);
}

static bool	apply_rotate(const char *op, t_list **stack_a,
			t_list **stack_b, t_bench *bench)
{
	if (!ft_strcmp(op, "ra"))
		rotate(stack_a, 'a', bench);
	else if (!ft_strcmp(op, "rb"))
		rotate(stack_b, 'b', bench);
	else if (!ft_strcmp(op, "rr"))
		multi_rotate(stack_a, stack_b, bench);
	else if (!ft_strcmp(op, "rra"))
		reverse_rotate(stack_a, 'a', bench);
	else if (!ft_strcmp(op, "rrb"))
		reverse_rotate(stack_b, 'b', bench);
	else if (!ft_strcmp(op, "rrr"))
		multi_reverse_rotate(stack_a, stack_b, bench);
	else
		return (false);
	return (true);
}

static bool	apply_operation(const char *op, t_list **stack_a,
			t_list **stack_b, t_bench *bench)
{
	if (apply_swap_push(op, stack_a, stack_b, bench))
		return (true);
	return (apply_rotate(op, stack_a, stack_b, bench));
}

static char	*read_all(void)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*content;
	char	*tmp;
	ssize_t	bytes;

	content = ft_strdup("");
	if (!content)
		return (NULL);
	bytes = read(0, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		tmp = content;
		content = ft_strjoin(content, buffer);
		free(tmp);
		if (!content)
			return (NULL);
		bytes = read(0, buffer, BUFFER_SIZE);
	}
	if (bytes < 0)
		return (free(content), NULL);
	return (content);
}

bool	read_operations(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	char	**ops;
	char	*content;
	int		index;

	content = read_all();
	if (!content)
		return (false);
	ops = ft_split(content, '\n');
	free(content);
	if (!ops)
		return (false);
	index = 0;
	while (ops[index])
	{
		if (!ops[index][0]
			|| !apply_operation(ops[index], stack_a, stack_b, bench))
		{
			free_split(ops);
			return (false);
		}
		index++;
	}
	free_split(ops);
	return (true);
}
