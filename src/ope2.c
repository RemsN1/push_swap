/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 00:15:15 by rribera           #+#    #+#             */
/*   Updated: 2021/07/22 03:47:14 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **lst_a)
{
	t_list	*tmp;

	printf("ra\n");
	tmp = (*lst_a)->next;
	ft_lstadd_back(lst_a, *lst_a);
	*lst_a = tmp;
}

void	rb(t_list **lst_b)
{
	t_list	*tmp;

	printf("rb\n");
	tmp = (*lst_b)->next;
	ft_lstadd_back(lst_b, *lst_b);
	*lst_b = tmp;
}

void	rr(t_list **lst_a, t_list **lst_b)
{
	ra(lst_a);
	rb(lst_b);
}

void	rra(t_list **lst_a)
{
	t_list	*tmp;
	int		i;

	printf("rra\n");
	i = ft_lstsize(*lst_a);
	if (i <= 1)
		return ;
	tmp = ft_lstlast(*lst_a);
	tmp->next = *lst_a;
	*lst_a = tmp;
	while (--i)
		*lst_a = (*lst_a)->next;
	(*lst_a)->next = NULL;
	*lst_a = tmp;
}

void	rrb(t_list **lst_b)
{
	t_list	*tmp;
	int		i;

	printf("rrb\n");
	i = ft_lstsize(*lst_b);
	if (i <= 1)
		return ;
	tmp = ft_lstlast(*lst_b);
	tmp->next = *lst_b;
	*lst_b = tmp;
	while (--i)
		*lst_b = (*lst_b)->next;
	(*lst_b)->next = NULL;
	*lst_b = tmp;
}
