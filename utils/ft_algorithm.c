/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:24:57 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/23 17:03:27 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_small_sort(t_sort **stack);
static void	ft_split_stack(t_ps *push_swap);

void	ft_algorithm(t_ps *push_swap)
{
	if (push_swap->len <= 3)
		ft_small_sort(&push_swap->stack_a);
	ft_split_stack(push_swap);
}

static void	ft_small_sort(t_sort **stack)
{
	if (ft_llsize(*stack) < 3 && \
		(*stack)->num > (*stack)->next->num)
	{
		ft_swap(stack, "sa");
		ft_llclear(stack, free);
		exit(EXIT_SUCCESS);
	}
	else if ((*stack)->num > (*stack)->next->num && \
		(*stack)->next->num < ft_lllast((*stack))->num)
		ft_rotate(&(*stack), "ra");
	else if ((*stack)->num > (*stack)->next->num && \
		(*stack)->next->num > ft_lllast((*stack))->num)
	{
		ft_rotate(stack, "ra");
		ft_swap(stack, "sa");
	}
	else if ((*stack)->num < (*stack)->next->num && \
		(*stack)->next->num > ft_lllast((*stack))->num
		&& (*stack)->num < ft_lllast((*stack))->num)
	{
		ft_swap(stack, "sa");
		ft_rotate(stack, "ra");
	}
	else if ((*stack)->num < (*stack)->next->num && \
		(*stack)->num > ft_lllast((*stack))->num)
		ft_reverse_rotate(&(*stack), "rra");
	else if (ft_is_sorted(stack))
		return ;
	ft_small_sort(stack);
}

static void	ft_split_stack(t_ps *push_swap)
{
	t_sort	*head;
	int		count;

	count = 1;
	head = push_swap->stack_a;
	while (head->num != push_swap->last)
	{
		if (head->keep == B)
			ft_push(&push_swap->stack_a, &push_swap->stack_b, "pb");
		else
		{
			ft_rotate(&push_swap->stack_a, "ra");
			count++;
		}
		head = push_swap->stack_a;
	}
	if (push_swap->stack_a->keep == B)
		ft_push(&push_swap->stack_a, &push_swap->stack_b, "pb");
	if (ft_llsize(push_swap->stack_a) == 3)
		ft_small_sort(&push_swap->stack_a);
	push_swap->pivot = ft_lllast(push_swap->stack_a)->index;
}
