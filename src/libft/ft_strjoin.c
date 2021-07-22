/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:17:23 by rribera           #+#    #+#             */
/*   Updated: 2021/07/01 00:43:44 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*fill_result(const char *s1, const char *s2, char *result,
				int len_s1)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		++i;
	}
	i = 0;
	while (s2[i])
	{
		result[len_s1 + i] = s2[i];
		++i;
	}
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!result)
		return (NULL);
	result = fill_result(s1, s2, result, len_s1);
	result[len_s1 + len_s2] = '\0';
	return (result);
}
