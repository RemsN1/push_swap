/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:20:43 by rribera           #+#    #+#             */
/*   Updated: 2021/07/15 21:58:25 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	cnt_word(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		if (s[i] != c && s[i])
		{
			++count;
			while (s[i] != c && s[i])
				++i;
		}
	}
	return (count);
}

static int	len_word(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i + 1);
}

static char	*alloc_free(char **s, int index, int size)
{
	s[index] = (char *)malloc(sizeof(char) * size);
	if (!s[index])
	{
		while (--index >= 0)
			free(s[index]);
		return (NULL);
	}
	return (s[index]);
}

char	**fill_result(char *s, int i, int j, char c)
{
	char	**result;
	int		k;

	result = (char **)malloc(sizeof(char *) * (cnt_word(s, c) + 1));
	if (!s || !result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			++i;
		k = -1;
		if (s[i] != c && s[i])
		{
			result[j] = (alloc_free(result, j, len_word(s + i, c)));
			if (!result[j])
				return (NULL);
			while (s[i] != c && s[i])
				result[j][++k] = s[i++];
			result[j++][k + 1] = '\0';
		}
	}
	result[j] = 0;
	return (result);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	return (fill_result(s, i, j, c));
}
