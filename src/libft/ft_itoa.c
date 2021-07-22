/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:43:22 by rribera           #+#    #+#             */
/*   Updated: 2021/07/01 00:51:48 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*fill_result(int compt, long long n, char *result)
{
	unsigned long long	tmp;
	unsigned long long	nbr;
	int					index;

	index = 0;
	if (n < 0)
	{
		result[0] = '-';
		result[++compt] = '\0';
		index = 1;
		nbr = -n;
	}
	else
	{
		result[compt] = '\0';
		nbr = n;
	}
	while (compt > index)
	{
		tmp = nbr % 10;
		nbr /= 10;
		result[--compt] = tmp + 48;
	}
	return (result);
}

static char	*allocate(int compt, long long n)
{
	char	*result;

	if (n > 0)
	{
		result = (char *)malloc(sizeof(char) * compt);
		if (!result)
			return (NULL);
	}
	else if (n < 0)
	{
		result = (char *)malloc(sizeof(char) * compt + 1);
		if (!result)
			return (NULL);
	}
	else
	{
		result = (char *)malloc(sizeof(char) * 2);
		if (!result)
			return (NULL);
	}
	return (result);
}

static int	counter(long long nbr, int count)
{
	while (nbr / 10 != 0)
	{
		nbr /= 10;
		++count;
	}
	return (count + 1);
}

char	*ft_itoa(long long n)
{
	int					count;
	char				*result;
	unsigned long long	nbr;

	count = 0;
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	count = counter(nbr, count);
	result = allocate(count + 1, n);
	if (!result)
		return (NULL);
	if (n == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	result = fill_result(count, n, result);
	return (result);
}
