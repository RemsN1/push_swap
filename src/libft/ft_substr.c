/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:56:00 by rribera           #+#    #+#             */
/*   Updated: 2021/06/30 23:58:51 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	compt;
	char			*result;

	if (!s)
		return (NULL);
	compt = ft_strlen(s);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	if (len < 1 || start >= compt)
	{
		result[0] = '\0';
		return (result);
	}
	compt = 0;
	while (s[start + compt] && compt < (unsigned int)len)
	{
		result[compt] = s[start + compt];
		++compt;
	}
	result[compt] = '\0';
	return (result);
}
