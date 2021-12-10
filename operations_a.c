/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:56:48 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 10:57:17 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

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
