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

bool	only_digit(char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str) || !ft_isdigit(*str))
			return (false);
		str++;
	}
	return (false);
}

char	**parse_strs(char **strs, int size, t_parsing *parsing_val)
{
	if (parsing_val->is_onestring && only_digit(strs[parsing_val->str_index]))
		return (ft_split(strs[parsing_val->str_index], ' '));
	
	
}

bool	parsing(t_parsing *parsing_val, char **strs, int size)
{
	parsing_val = ft_calloc(sizeof(t_parsing), 1);
	if (!parsing_val)
		return (false);
	parsing_val->is_onestring = is_onestring(strs, size, parsing_val);
	parsing_val->item_parse = parse_strs(strs, size, parsing_val);
	if (parsing_val->item_parse)
		return (false);
	return (true);
}