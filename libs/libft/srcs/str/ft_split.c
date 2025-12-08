/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil--de <sgil--de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:30:15 by sgil--de          #+#    #+#             */
/*   Updated: 2025/12/08 17:57:10 by sgil--de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	size_t	result;

	result = 0;
	while (*s)
	{
		if (*s != c)
		{
			result++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (result);
}

static char	*fill_word(const char *s, char c)
{
	char	*word;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

char	**free_split(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	cur_word;
	size_t	i;

	strs = ft_calloc(count_word(s, c) + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	cur_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			strs[cur_word++] = fill_word(&s[i], c);
			if (!strs[cur_word - 1])
				return (free_split(strs));
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	strs[cur_word] = NULL;
	return (strs);
}
