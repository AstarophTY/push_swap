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

static bool	check_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit((int)*str))
			return (false);
		str++;
	}
	return (true);
}

static int	verification_flag(char *str)
{
	int	flag;

	flag = 0;
	if (!ft_strcmp(str, "--simple"))
		flag = 1;
	else if (!ft_strcmp(str, "--medium"))
		flag = 2;
	else if (!ft_strcmp(str, "--complex"))
		flag = 3;
	else if (!ft_strcmp(str, "--adaptive"))
		flag = 4;
	return (flag);
}

static bool	array_contain(char *to_find, char **array, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (array[i] && ft_strcmp(array[i], to_find) == 0)
			return (true);
		i++;
	}
	return (false);
}

int	is_nb(int argc, char **argv)
{
	char	**strs;
	int		i;
	int		temp;

	i = 1;
	temp = 4;
	if (argc <= 1)
		return (0);
	strs = ft_calloc(argc, sizeof(char *));
	if (!strs)
		return (0);
	while (argv[i] && i < argc && temp)
	{
		if (verification_flag(argv[i]))
			temp = verification_flag(argv[i]);
		else if (check_digit(argv[i]) && !array_contain(argv[i], strs, argc))
			strs[i] = argv[i];
		else
			temp = 0;
		i++;
	}
	free(strs);
	return (temp);
}

char	**get_nb(char **argv)
{
	size_t	size;
	size_t	i;
	char	**strs;

	i = 0;
	size = 0;
	while (argv[i])
	{
		if (check_digit(argv[i]))
			size++;
		i++;
	}
	strs = ft_calloc(size + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	size = 0;
	while (argv[i])
	{
		if (check_digit(argv[i]))
			strs[size++] = ft_strdup(argv[i]);
		i++;
	}
	strs[size] = NULL;
	return (strs);
}
