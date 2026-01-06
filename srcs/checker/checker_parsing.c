/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:18:31 by sgil--de          #+#    #+#             */
/*   Updated: 2026/01/06 12:18:31 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	is_number_format(const char *str)
{
	int	index;

	if (!str || !*str)
		return (false);
	index = 0;
	if (str[index] == '+' || str[index] == '-')
		index++;
	if (!str[index])
		return (false);
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (false);
		index++;
	}
	return (true);
}

static bool	atoi_ptr(const char *str, int *value)
{
	long long	result;
	int			sign;
	int			index;

	if (!is_number_format(str))
		return (false);
	sign = 1;
	result = 0;
	index = 0;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index])
	{
		result = (result * 10) + (str[index] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-result) < INT_MIN))
			return (false);
		index++;
	}
	*value = (int)(result * sign);
	return (true);
}

static bool	process_lst(t_list **stack_a, const char *token)
{
	t_list	*node;
	int		value;

	if (!atoi_ptr(token, &value))
		return (false);
	node = ft_lstnew(value);
	if (!node)
		return (false);
	ft_lstadd_back(stack_a, node);
	return (true);
}

static bool	process_split(t_list **stack_a, char **splitted, bool *added)
{
	int	cursor;

	cursor = 0;
	while (splitted[cursor])
	{
		if (!process_lst(stack_a, splitted[cursor++]))
		{
			free_split(splitted);
			return (false);
		}
		*added = true;
	}
	free_split(splitted);
	return (true);
}

bool	build_stack(t_list **stack_a, char **argv)
{
	char	**splitted;
	int		index;
	bool	added;

	added = false;
	index = 0;
	while (argv[index])
	{
		splitted = ft_split(argv[index], ' ');
		if (!splitted)
			return (false);
		if (!process_split(stack_a, splitted, &added))
			return (false);
		index++;
	}
	if (!added || has_duplicates(*stack_a))
		return (false);
	return (true);
}
