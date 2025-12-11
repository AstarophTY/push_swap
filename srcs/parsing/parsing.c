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

static bool	is_flag(char *str)
{
	if (!str)
		return (false);
	if (!ft_strcmp(str, "--simple") || !ft_strcmp(str, "--medium")
		|| !ft_strcmp(str, "--complex") || !ft_strcmp(str, "--adaptive")
		|| !ft_strcmp(str, "--bench"))
		return (true);
	return (false);
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

static char	**merge_all_args(char **strs, int size)
{
	char	**result;
	char	**temp;
	char	**old_result;
	int		i;
	int		j;

	result = NULL;
	i = 0;
	while (i < size)
	{
		if (is_flag(strs[i]))
		{
			i++;
			continue;
		}
		temp = ft_split(strs[i], ' ');
		if (!temp)
			return (free_split(result));
		j = 0;
		while (temp[j])
		{
			if (is_valid_number(temp[j]))
			{
				old_result = result;
				result = append_to_array(result, temp[j]);
				if (!result)
				{
					free_split(temp);
					return (free_split(old_result));
				}
			}
			j++;
		}
		free_split(temp);
		i++;
	}
	return (result);
}

bool	parsing(t_parsing *parsing_val, char **strs, int size)
{
	if (!parsing_val)
		return (false);
	process_flags(strs, parsing_val);
	parsing_val->item_parse = merge_all_args(strs, size);
	if (!parsing_val->item_parse || !parsing_val->item_parse[0])
	{
		if (parsing_val->item_parse)
			free_split(parsing_val->item_parse);
		parsing_val->item_parse = NULL;
		return (false);
	}
	return (true);
}