#include "push_swap.h"

void	free_list(t_list **lst_a, t_list **lst_b)
{
	/*t_list	*tmp;

	while (*lst_a)
	{
		tmp = (*lst_a)->next;
		free((*lst_a)->content);
		free(*lst_a);
		*lst_a = tmp;
	}
	while (*lst_b)
	{
		tmp = (*lst_b)->next;
		free((*lst_b)->content);
		free(*lst_b);
		*lst_b = tmp;
	}*/
	int *tamer;
	*lst_b = NULL;
	while (*lst_a)
	{
		tamer = (*lst_a)->content;
		printf("%d\n", *tamer);
		*lst_a = (*lst_a)->next;
	}
}

int main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	//t_struct	s;

	lst_b = NULL;
	if (ac <= 1)
		return (0);
	if (!parse(av, &lst_a))
	{
		printf("Error\n");
		return (0);
	}


	int *i;
	t_list *tmp;

	tmp = lst_a;
	//printf("tmp : %d\n", *i);
/*	while (lst_a)
	{
		i = lst_a->content;
		printf("%d \t %p\n", *i, lst_a);
		lst_a = lst_a->next;
	}*/
	//lst_a = tmp;
	pa(&lst_a, &lst_b);
	
	while (lst_a)
	{
		i = lst_a->content;
		printf("%d \t %p\n", *i, lst_a);
		lst_a = lst_a->next;
	}
	lst_a = tmp;

	/*
	s.size_a = ft_lstsize(lst_a);
	s.size_b = 0;
	push_swap(&lst_a, &lst_b, &s);
	free_list(&lst_a, &lst_b);
*/
	return (0);
}
