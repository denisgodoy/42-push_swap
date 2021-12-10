/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:19:18 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 00:45:18 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

t_sort	*ft_llnew(int content)
{
	t_sort	*new;

	new = (t_sort *)malloc(sizeof(t_sort));
	if (!new)
		return (0);
	new->num = content;
	new->next = 0;
	return (new);
}

t_sort	*ft_lllast(t_sort *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

void	ft_lladd_back(t_sort **lst, t_sort *new)
{
	t_sort	*node;

	if (*lst != 0)
	{
		node = ft_lllast(*lst);
		node->next = new;
		return ;
	}
	*lst = new;
	return ;
}

void	ft_lladd_front(t_sort **lst, t_sort *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_swap_a(t_ps *push_swap)
{
	t_sort	*head;
	t_sort	*third;

	head = push_swap->stack_a;
	third = push_swap->stack_a->next->next;
	push_swap->stack_a = push_swap->stack_a->next;
	push_swap->stack_a->next = head;
	head->next = third;
	ft_putendl_fd("sa", STDIN);
}

void	ft_rotate_a(t_ps *push_swap)
{
	t_sort	*last;
	t_sort	*head;
	t_sort	*temp;

	temp = push_swap->stack_a->next;
	head = push_swap->stack_a;
	last = ft_lllast(push_swap->stack_a);
	push_swap->stack_a->next = NULL;
	last->next = head;
	push_swap->stack_a = temp;
	ft_putendl_fd("ra", STDIN);
}

void	ft_reverse_rotate_a(t_ps *push_swap)
{
	int		i;
	t_sort	*last;
	t_sort	*ntl;
	t_sort	*temp;

	last = ft_lllast(push_swap->stack_a);
	temp = push_swap->stack_a;
	i = 0;
	while (i++ < (push_swap->len - 1))
	{
		ntl = temp;
		temp = temp->next;
	}
	ntl->next = NULL;
	ft_lladd_front(&push_swap->stack_a, ft_llnew(last->num));
	free(last);
	ft_putendl_fd("rra", STDIN);
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
	push_swap.stack_a = ft_llnew(push_swap.args[0]);
	int i = 0;
	while (++i < push_swap.len)
		ft_lladd_back(&push_swap.stack_a, ft_llnew(push_swap.args[i]));
	ft_swap_a(&push_swap);
	ft_rotate_a(&push_swap);
	ft_reverse_rotate_a(&push_swap);
	while (push_swap.stack_a != NULL)
	{
		ft_putendl_fd("", STDIN);
		printf("stack %p\n", push_swap.stack_a);
		printf("next %p\n", push_swap.stack_a->next);
		printf("num %d\n", push_swap.stack_a->num);
		push_swap.stack_a = push_swap.stack_a->next;
	}
	free(push_swap.args);
	exit(EXIT_SUCCESS);
}
