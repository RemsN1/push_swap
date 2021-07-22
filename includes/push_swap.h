/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:29:31 by rribera           #+#    #+#             */
/*   Updated: 2021/07/22 02:16:55 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_struct {
	int		size_a;
	int		size_b;
}	t_struct;

int		parse(char **av, t_list **lst_a);
int		check_elem(char *elem, t_list *lst);
void	sa(t_list **lst_a, t_struct *s);
void	sb(t_list **lst_b, t_struct *s);
void	ss(t_list **lst_a, t_list **lst_b, t_struct *s);
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_a, t_list **lst_b);
void	ra(t_list **lst_a);
void	rb(t_list **lst_b);
void	rr(t_list **lst_a, t_list **lst_b);
void	rra(t_list **lst_a);
void	rrb(t_list **lst_b);
void	rrr(t_list **lst_a, t_list **lst_b);
int		check_value(t_list **lst, int mid, int b);
int		find_mid_value(t_list **lst, int mid);
void	push_swap(t_list **lst_a, t_list **lst_b, t_struct *s);
void	sort_b(t_list **lst_a, t_list **lst_b, int min, int max);
void	sort_a(t_list **lst_a, t_list **lst_b, int min, int max);
int		lst_good(t_list **lst);
int 	compare_values(t_list *lst, int value);

#endif
