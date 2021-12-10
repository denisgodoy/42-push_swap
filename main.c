/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:19:18 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/09 21:50:23 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_swap_a(t_ps *push_swap)
{
	t_sort	*head;

	ft_putendl_fd("sa", STDIN);
	head = push_swap->stack_a;
	push_swap->stack_a->next = head;
	push_swap->stack_a->prev = NULL;
	push_swap->stack_a->next = NULL;
	push_swap->stack_a->prev = push_swap->stack_a;
}

t_sort	*ft_dllnew(int content)
{
	t_sort	*new;

	new = (t_sort *)malloc(sizeof(t_sort));
	if (!new)
		return (0);
	new->num = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_sort	*ft_dlllast(t_sort *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	ft_dlladd_back(t_sort **lst, t_sort *new)
{
	t_sort	*node;

	if (*lst != 0)
	{
		node = ft_dlllast(*lst);
		node->next = new;
		new->prev = *lst;
		return ;
	}
	*lst = new;
	return ;
}

int	main(int argc, char **argv)
{
	t_ps	push_swap;

	if (ft_check_args(&push_swap, argc, argv))
	{
		ft_putendl_fd("Error", STDERR);
		return (-1);
	}
	else if (!ft_algorithm(&push_swap))
		return (-1);
	push_swap.stack_a = ft_dllnew(push_swap.args[0]);
	push_swap.stack_b = ft_dllnew(push_swap.args[1]);
	ft_swap_a(&push_swap);
	ft_dlladd_back(&push_swap.stack_a, push_swap.stack_b);
	while (push_swap.stack_a != NULL)
	{
		printf("%p\n", push_swap.stack_a->next);
		printf("%d\n", push_swap.stack_a->num);
		printf("%p\n", push_swap.stack_a->prev);
		push_swap.stack_a = push_swap.stack_a->next;
	}
	free(push_swap.args);
	exit(EXIT_SUCCESS);
}
