/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:50:34 by rribera           #+#    #+#             */
/*   Updated: 2021/06/30 23:06:13 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	result = malloc(size * nmemb);
	if (!result)
		return (NULL);
	ft_bzero(result, size * nmemb);
	return (result);
}
