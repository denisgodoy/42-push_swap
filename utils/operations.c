/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:56:48 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 22:20:24 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_swap(t_sort **stack, char *op)
{
	t_sort	*head;
	t_sort	*third;

	head = *stack;
	third = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = head;
	head->next = third;
	ft_putendl_fd(op, STDIN_FILENO);
}

void	ft_rotate(t_sort **stack, char *op)
{
	t_sort	*last;

	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
	ft_lladd_back(stack, last);
	ft_putendl_fd(op, STDIN_FILENO);
}

void	ft_reverse_rotate(t_sort **stack, char *op)
{
	int		i;
	t_sort	*last;
	t_sort	*ntl;
	t_sort	*temp;

	last = ft_lllast(*stack);
	temp = *stack;
	i = 0;
	while (i++ < (ft_llsize(*stack) - 1))
	{
		ntl = temp;
		temp = temp->next;
	}
	ntl->next = NULL;
	ft_lladd_front(stack, last);
	ft_putendl_fd(op, STDIN_FILENO);
}

void	ft_push_a(t_ps *push_swap)
{
	t_sort	*head;
	t_sort	*temp;

	if (!ft_llsize(push_swap->stack_b))
		return ;
	ft_putendl_fd("pa", STDIN_FILENO);
	head = push_swap->stack_b->next;
	temp = push_swap->stack_a;
	push_swap->stack_a = push_swap->stack_b;
	if (!ft_llsize(push_swap->stack_a))
		push_swap->stack_a->next = NULL;
	else
		push_swap->stack_a->next = temp;
	push_swap->stack_b = head;
}

void	ft_push_b(t_ps *push_swap)
{
	t_sort	*head;
	t_sort	*temp;

	if (!ft_llsize(push_swap->stack_a))
		return ;
	ft_putendl_fd("pb", STDIN_FILENO);
	head = push_swap->stack_a->next;
	temp = push_swap->stack_b;
	push_swap->stack_b = push_swap->stack_a;
	if (!ft_llsize(push_swap->stack_b))
		push_swap->stack_b->next = NULL;
	else
		push_swap->stack_b->next = temp;
	push_swap->stack_a = head;
}
