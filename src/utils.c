/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:00:22 by rribera           #+#    #+#             */
/*   Updated: 2021/07/22 04:24:13 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_value(t_list **lst, int mid, int b)
{
	int		*i;
	t_list	*tmp;

	if (!(*lst))
		return (0);
	tmp = *lst;
	while (*lst)
	{
		i = (*lst)->content;
		if (*i <= mid && !b)
		{
			*lst = tmp;
			return (1);
		}

		else if (*i >= mid && b)
		{
			*lst = tmp;
			return (1);	
		}
		*lst = (*lst)->next;
	}
	*lst = tmp;
	return (0);
}

int		find_mid_value(t_list **lst, int mid)
{
	int		count;
	int		*value;
	t_list	*ptr;

	count = 0;
	/*if (!(*lst))
		return (0);*/
	ptr = *lst;
	while (count < mid && (*lst)->next) //remplacer lst par lst->next pour segv
	{
		++count;
		if (!(*lst)->next)
			break;
		*lst = (*lst)->next;
	}
	value = (*lst)->content;
	*lst = ptr;
	return (*value);
}

int 	compare_values(t_list *lst, int value)
{
	int *others;

	while (lst)
	{
		others = lst->content;
		if (value > *others)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int		lst_good(t_list **lst)
{
	t_list	*ptr;
	int		*value;

	ptr = *lst;
	while (*lst)
	{
		value = (*lst)->content;
		if (!compare_values((*lst)->next, *value))
			return (0);
		*lst = (*lst)->next;
	}
	*lst = ptr;
	return (1);
}
