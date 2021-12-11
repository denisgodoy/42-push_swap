/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:56:48 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/11 18:55:39 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_swap(t_sort **stack, char *op)
{
	t_sort	*head;
	t_sort	*third;

	if (!*stack)
		return ;
	head = *stack;
	third = (*stack)->next->next;
	*stack = (*stack)->next;
	(*stack)->next = head;
	head->next = third;
	ft_putendl_fd(op, STDOUT_FILENO);
}

void	ft_rotate(t_sort **stack, char *op)
{
	t_sort	*last;

	if (!*stack)
		return ;
	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
	ft_lladd_back(stack, last);
	ft_putendl_fd(op, STDOUT_FILENO);
}

void	ft_reverse_rotate(t_sort **stack, char *op)
{
	int		i;
	t_sort	*last;
	t_sort	*ntl;
	t_sort	*temp;

	if (!*stack)
		return ;
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
	ft_putendl_fd(op, STDOUT_FILENO);
}

void	ft_push(t_sort **src, t_sort **dst, char *op)
{
	t_sort	*head;
	t_sort	*temp;

	if (!*src)
		return ;
	ft_putendl_fd(op, STDOUT_FILENO);
	head = (*src)->next;
	temp = *dst;
	*dst = *src;
	if (!ft_llsize(*dst))
		(*src)->next = NULL;
	else
		(*src)->next = temp;
	*src = head;
}
