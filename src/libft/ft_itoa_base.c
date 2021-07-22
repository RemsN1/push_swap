/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:43:08 by rribera           #+#    #+#             */
/*   Updated: 2021/06/30 23:22:45 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

static int	check_base(char *base)
{
	int		i;
	int		j;

	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = -1;
		while (base[i] && base[++j])
			if (base[i] == base[j] && i != j)
				return (0);
	}
	if (i <= 1)
		return (0);
	return (i);
}

static char	*allocate(unsigned int base_10, int count, char *res)
{
	if (base_10 > 0)
	{
		res = (char *)malloc(sizeof(char) * count + 1);
		if (!res)
			return (NULL);
	}
	else
	{
		res = (char *)malloc(sizeof(char) * count + 2);
		if (!res)
			return (NULL);
	}
	return (res);
}

static char	*itoa_base(long long base_10, char *base_to, char *res,
		int count)
{
	long long		tmp;
	int				j;
	long long		cheu;

	j = 0;
	cheu = base_10;
	res[count] = '\0';
	while (count > j)
	{
		tmp = cheu;
		cheu = cheu / check_base(base_to);
		res[--count] = base_to[tmp % check_base(base_to)];
	}
	return (res);
}

char	*ft_itoa_base(long long nbr, char *base_to)
{
	int				len;
	char			*res;
	int				count;
	long long		tmp;

	len = 0;
	count = 1;
	len = check_base(base_to);
	if (!len)
		return (NULL);
	res = 0;
	tmp = nbr;
	while (tmp / len)
	{
		tmp /= len;
		++count;
	}
	res = allocate(nbr, count, res);
	res = itoa_base(nbr, base_to, res, count);
	if (nbr == 0)
		res[0] = base_to[0];
	return (res);
}
