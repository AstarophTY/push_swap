/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:00:00 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/11 17:31:05 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_array_size(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**append_to_array(char **array, char *str)
{
	char	**new_array;
	int		size;
	int		i;

	size = count_array_size(array);
	new_array = ft_calloc(size + 2, sizeof(char *));
	if (!new_array)
	{
		free_split(array);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = ft_strdup(str);
	if (!new_array[i])
	{
		free(new_array);
		free_split(array);
		return (NULL);
	}
	new_array[i + 1] = NULL;
	if (array)
		free(array);
	return (new_array);
}
