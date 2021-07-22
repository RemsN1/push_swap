/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:35:20 by rribera           #+#    #+#             */
/*   Updated: 2021/07/22 04:24:16 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compensate_ra(t_list **lst_a, int count)
{
	while (count > 0)
	{
		rra(lst_a);
		--count;
	}
}

void	compensate_rb(t_list **lst_b, int count)
{
	while (count > 0)
	{
		rrb(lst_b);
		--count;
	}
}

void	sort_b(t_list **lst_a, t_list **lst_b, int min, int max)
{
	int		*value;
	int		mid;
	int		value_mid;
	int		count;

	if (min > max)
		return ;
	mid = (max + min) / 2;
	value_mid = find_mid_value(lst_b, mid);
	count = 0;
	while (check_value(lst_b, value_mid, 1))
	{
		value = (*lst_b)->content;
		if (*value < value_mid)
		{
			rb(lst_b);
			++count;
		}
		else
			pa(lst_a, lst_b);
	}
	compensate_rb(lst_b, count);
	sort_a(lst_a, lst_b, mid, max);
	sort_b(lst_a, lst_b, min, mid - 1);
}

void	sort_a(t_list **lst_a, t_list **lst_b, int min, int max)
{
	int		*value;
	int		mid;
	int		value_mid;
	int		count;

	if (min >= max)
		return ;
	mid = (max + min) / 2;
	value_mid = find_mid_value(lst_a, mid);
	count = 0;
	while (check_value(lst_a, value_mid, 0) && ft_lstsize(*lst_a) > 0)
	{
		value = (*lst_a)->content;
		if (*value > value_mid)
		{
			ra(lst_a);
			++count;
		}
		else
			pb(lst_a, lst_b);
	}
	compensate_ra(lst_a, count);
	sort_a(lst_a, lst_b, mid + 1, max);
	sort_b(lst_a, lst_b, min, mid);
}

void	push_swap(t_list **lst_a, t_list **lst_b, t_struct *s)
{
	sort_a(lst_a, lst_b, 0, s->size_a - 1);
}
