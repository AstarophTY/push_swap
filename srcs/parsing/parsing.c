/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:54:17 by tmalpert          #+#    #+#             */
/*   Updated: 2025/12/11 17:57:50 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_valid_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (false);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	process_flags(char **strs, t_parsing *parsing_val)
{
	int	i;

	i = 0;
	parsing_val->flag = adaptive;
	parsing_val->bench_state = false;
	while (strs[i])
	{
		if (!ft_strcmp(strs[i], "--simple"))
			parsing_val->flag = simple;
		else if (!ft_strcmp(strs[i], "--medium"))
			parsing_val->flag = medium;
		else if (!ft_strcmp(strs[i], "--complex"))
			parsing_val->flag = complex;
		else if (!ft_strcmp(strs[i], "--adaptive"))
			parsing_val->flag = adaptive;
		else if (!ft_strcmp(strs[i], "--bench"))
			parsing_val->bench_state = true;
		i++;
	}
}

static char	**merge_all_args(char **n_strs)
{
	size_t	size;
	size_t	i;
	char	**strs;

	i = 0;
	size = 0;
	while (n_strs[i])
	{
		if (is_valid_number(n_strs[i]))
			size++;
		i++;
	}
	strs = ft_calloc(size + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	size = 0;
	while (n_strs[i])
	{
		if (is_valid_number(n_strs[i]))
			strs[size++] = ft_strdup(n_strs[i]);
		i++;
	}
	strs[size] = NULL;
	return (strs);
}

bool	parsing(t_parsing *parsing_val, char **strs)
{
	if (!parsing_val)
		return (false);
	process_flags(strs, parsing_val);
	parsing_val->item_parse = merge_all_args(strs);
	if (!parsing_val->item_parse || !parsing_val->item_parse[0])
	{
		if (parsing_val->item_parse)
			free_split(parsing_val->item_parse);
		parsing_val->item_parse = NULL;
		return (false);
	}
	return (true);
}
