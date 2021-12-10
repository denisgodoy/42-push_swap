/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:56:48 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 10:58:20 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_swap_b(t_ps *push_swap)
{
	t_sort	*head;
	t_sort	*third;

	head = push_swap->stack_b;
	third = push_swap->stack_b->next->next;
	push_swap->stack_b = push_swap->stack_b->next;
	push_swap->stack_b->next = head;
	head->next = third;
	ft_putendl_fd("sb", STDIN);
}

void	ft_rotate_b(t_ps *push_swap)
{
	t_sort	*last;
	t_sort	*head;
	t_sort	*temp;

	temp = push_swap->stack_b->next;
	head = push_swap->stack_b;
	last = ft_lllast(push_swap->stack_b);
	push_swap->stack_b->next = NULL;
	last->next = head;
	push_swap->stack_b = temp;
	ft_putendl_fd("rb", STDIN);
}

void	ft_reverse_rotate_b(t_ps *push_swap)
{
	int		i;
	t_sort	*last;
	t_sort	*ntl;
	t_sort	*temp;

	last = ft_lllast(push_swap->stack_b);
	temp = push_swap->stack_b;
	i = 0;
	while (i++ < (push_swap->len - 1))
	{
		ntl = temp;
		temp = temp->next;
	}
	ntl->next = NULL;
	ft_lladd_front(&push_swap->stack_b, ft_llnew(last->num));
	free(last);
	ft_putendl_fd("rrb", STDIN);
}
