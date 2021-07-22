/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rribera <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:39:14 by rribera           #+#    #+#             */
/*   Updated: 2021/07/22 03:49:23 by rribera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_elem(char *elem, t_list *lst)
{
	int		test;
	char	*str;
	int		*tmp;
	t_list	*ptr;

	test = ft_atoi(elem);
	str = ft_itoa((long long)test);
	if (ft_strcmp(str, elem))
		return (0);
	ptr = lst;
	while (lst)
	{
		tmp = lst->content;
		if (*tmp == test)
			return (0);
		lst = lst->next;
	}
	lst = ptr;
	return (1);
}

int	create_node(t_list *lst_a, char **elem, int count)
{
	int		*tab;
	int		i;

	tab = (int *)malloc(sizeof(int) * count);
	if (!tab)
		return (0);
	i = 0;
	while (i < count)
	{
		tab[i] = ft_atoi(elem[i]);
		++i;
	}
	i = 1;
	while (i < count)
	{
		ft_lstadd_back(&lst_a, ft_lstnew(&tab[i]));
		++i;
	}
	return (1);
}

int	parse(char **av, t_list **lst_a)
{
	int		i;
	char	**elem;
	int		value;

	i = 0;
	while (av[1][i] < 0 && av[1][i] > 9 && av[1][i])
		++i;
	if (!av[1][i])
		return (0);
	av[1][ft_strlen(av[1])] = '\0';
	elem = ft_split(av[1], ' ');
	if (!elem)
		return (0);
	i = 0;
	while (elem[i])
	{
		if (!check_elem(elem[i], *lst_a))
			return (0);
		++i;
	}
	value = ft_atoi(elem[0]);
	*lst_a = ft_lstnew(&value);
	if (!create_node(*lst_a, elem, i))
		return (0);
	//TEST LIST BIEN REMPLIE
	/*
	int *tamer;

	while (*lst_a)
	{
		tamer = (*lst_a)->content;
		printf("%d\n", *tamer);
		*lst_a = (*lst_a)->next;
	}*/
	return (1);
}
