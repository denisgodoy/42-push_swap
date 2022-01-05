/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:24:57 by degabrie          #+#    #+#             */
/*   Updated: 2022/01/03 23:08:57 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

// static void	ft_small_sort(t_sort **stack);
// static void	ft_small_sort_reverse(t_sort **stack);
static void	ft_split_stack(t_ps *push_swap);
// static void	ft_empty_stack(t_ps *push_swap);
// static void	ft_merge_stacks(t_ps *push_swap);

void	ft_algorithm(t_ps *push_swap)
{
	// if (push_swap->len <= 3)
	// 	ft_small_sort(&push_swap->stack_a);
	ft_split_stack(push_swap);
}

// static void	ft_small_sort(t_sort **stack)
// {
// 	if (ft_llsize(*stack) < 3 && \
// 		(*stack)->num > (*stack)->next->num)
// 	{
// 		ft_swap(stack, "sa");
// 		ft_llclear(stack, free);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else if ((*stack)->num > (*stack)->next->num && \
// 		(*stack)->next->num < ft_lllast((*stack))->num)
// 		ft_rotate(&(*stack), "ra");
// 	else if ((*stack)->num > (*stack)->next->num && \
// 		(*stack)->next->num > ft_lllast((*stack))->num)
// 	{
// 		ft_rotate(stack, "ra");
// 		ft_swap(stack, "sa");
// 	}
// 	else if ((*stack)->num < (*stack)->next->num && \
// 		(*stack)->next->num > ft_lllast((*stack))->num
// 		&& (*stack)->num < ft_lllast((*stack))->num)
// 	{
// 		ft_swap(stack, "sa");
// 		ft_rotate(stack, "ra");
// 	}
// 	else if ((*stack)->num < (*stack)->next->num && \
// 		(*stack)->num > ft_lllast((*stack))->num)
// 		ft_reverse_rotate(&(*stack), "rra");
// 	else if (ft_is_sorted(stack))
// 		return ;
// 	ft_small_sort(stack);
// }

// static void	ft_small_sort_reverse(t_sort **stack)
// {
// 	if (ft_llsize(*stack) < 3 && \
// 		(*stack)->num < (*stack)->next->num)
// 	{
// 		ft_swap(stack, "sa");
// 		return ;
// 	}
// 	else if ((*stack)->num < (*stack)->next->num && \
// 		(*stack)->next->num > ft_lllast((*stack))->num)
// 		ft_rotate(&(*stack), "ra");
// 	else if ((*stack)->num < (*stack)->next->num && \
// 		(*stack)->next->num > ft_lllast((*stack))->num)
// 	{
// 		ft_rotate(stack, "ra");
// 		ft_swap(stack, "sa");
// 	}
// 	else if ((*stack)->num > (*stack)->next->num && \
// 		(*stack)->next->num < ft_lllast((*stack))->num
// 		&& (*stack)->num > ft_lllast((*stack))->num)
// 	{
// 		ft_swap(stack, "sa");
// 		ft_rotate(stack, "ra");
// 	}
// 	else if ((*stack)->num > (*stack)->next->num && \
// 		(*stack)->num < ft_lllast((*stack))->num)
// 		ft_reverse_rotate(&(*stack), "rra");
// 	else if (ft_is_sorted(stack))
// 		return ;
// 	ft_small_sort_reverse(stack);
// }

static void	ft_split_stack(t_ps *push_swap)
{
	t_sort	*head;
	int		count;
	int		count_ra;

	count = push_swap->count_pb;
	count_ra = 0;
	head = push_swap->stack_a;
	while (count)
	{
		if (head->keep == B)
		{
			ft_push(&push_swap->stack_a, &push_swap->stack_b, "pb");
			count--;
		}
		else
		{
			ft_rotate(&push_swap->stack_a, "ra");
			count_ra++;
		}
		head = push_swap->stack_a;
	}
	// ft_empty_stack(push_swap);
	// ft_merge_stacks(push_swap);
}

// static void	ft_empty_stack(t_ps *push_swap)
// {
// 	int	*arr;
// 	t_sort	*head;
// 	int	i;

// 	i = -1;
// 	head = push_swap->stack_a;
// 	arr = (int *)malloc(ft_llsize(push_swap->stack_a) * sizeof(int));
// 	while (head)
// 	{
// 		arr[++i] = head->num;
// 		head = head->next;
// 	}
// 	if (i == 1)
// 		push_swap->mid = arr[i];
// 	else if (i > 2)
// 		push_swap->mid = arr[i / 2];
// 	else if (arr[0] < arr[1])
// 		push_swap->mid = arr[0];
// 	else
// 		push_swap->mid = arr[1];
// }

// static void	ft_merge_stacks(t_ps *push_swap)
// {
// 	if (push_swap->stack_a->index == push_swap->stack_b->index + 1)
// 	{
// 		ft_push(&push_swap->stack_b, &push_swap->stack_a, "pa");
// 	}
// 	else
// 		ft_rotate_both(push_swap);
// 	if (!ft_llsize(push_swap->stack_b))
// 		return ;
// 	ft_merge_stacks(push_swap);
// }
