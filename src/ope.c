/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 23:38:15 by rribera           #+#    #+#             */
/*   Updated: 2021/07/22 04:24:18 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst_a, t_struct *s)
{
	t_list *tmp;

	if (s->size_a <= 1)
		return ;
	tmp = (*lst_a)->next;
	(*lst_a)->next = tmp->next;
	tmp->next = *lst_a;
	*lst_a = tmp;
	printf("sa\n");
}

void	sb(t_list **lst_b, t_struct *s)
{
	t_list	*tmp;

	if (s->size_b <= 1)
		return ;
	tmp = (*lst_b)->next;
	(*lst_b)->next = tmp->next;
	tmp->next = *lst_b;
	*lst_b = tmp;
	printf("sb\n");
}

void	ss(t_list **lst_a, t_list **lst_b, t_struct *s)
{
	sa(lst_a, s);
	sb(lst_b, s);
}

void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

//	write(1, "pa", 2);
	if (!(*lst_b))
		return ;
	tmp = *lst_b;
	*lst_b = (*lst_b)->next;
	ft_lstadd_front(lst_a, tmp);
}

void	pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	
	printf("pb\n");
	if (!(*lst_a))
		return ;
	tmp = *lst_a;
	*lst_a = (*lst_a)->next;
	ft_lstadd_front(lst_b, tmp);
}
