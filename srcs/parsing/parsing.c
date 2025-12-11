/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalpert <tmalpert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:54:17 by tmalpert          #+#    #+#             */
/*   Updated: 2025/12/08 17:57:50 by tmalpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

bool	is_onestring(char **strs, int size, t_parsing *parsing_val)
{
	int	i;
	int	j;

	i = 0;
	while (i < size && strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (ft_isspace(strs[i][j]))
			{
				parsing_val->str_index = i;
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

bool	only_digit(char *str, bool space_too)
{
	bool	has_digit;

	if (!str || !*str)
		return (false);
	has_digit = false;
	while (*str)
	{
		while (*str && ft_isspace(*str) && space_too)
			str++;
		if (*str == '-' || *str == '+')
		{
			str++;
			if (!*str || !ft_isdigit(*str))
				return (false);
		}
		if (ft_isdigit(*str))
		{
			has_digit = true;
			while (*str && ft_isdigit(*str))
				str++;
		}
		else if (*str)
			return (false);
	}
	return (has_digit);
}

char	**parse_strs(char **strs, int size, t_parsing *parsing_val)
{
	int	i;
	int	j;

	if (parsing_val->is_onestring && only_digit(strs[parsing_val->str_index], true))
		return (ft_split(strs[parsing_val->str_index], ' '));
	i = 0;
	size = 0;
	while (strs[i])
	{
		if (only_digit(strs[i], false))
			size++;
		i++;
	}
	parsing_val->item_parse = ft_calloc(size + 1, sizeof(char *));
	if (!parsing_val->item_parse)
		return (NULL);
	i = 0;
	j = 0;
	while (strs[i])
	{
		if (only_digit(strs[i], false))
			parsing_val->item_parse[j++] = ft_strdup(strs[i]);
		i++;
	}
	parsing_val->item_parse[j] = NULL;
	return (parsing_val->item_parse);
}


void	verification_flag(char **strs, t_parsing *parsing_val)
{
	int	i;

	i = 0;
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

bool	parsing(t_parsing *parsing_val, char **strs, int size)
{
	if (!parsing_val)
		return (false);
	parsing_val->is_onestring = is_onestring(strs, size, parsing_val);
	parsing_val->item_parse = parse_strs(strs, size, parsing_val);
	verification_flag(strs, parsing_val);
	if (!parsing_val->item_parse)
		return (false);
	for (size_t i = 0; parsing_val->item_parse[i]; i++)
		printf("%s\n", parsing_val->item_parse[i]);
	return (true);
}