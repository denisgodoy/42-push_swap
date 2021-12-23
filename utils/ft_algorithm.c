/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:24:57 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/22 22:04:11 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_small_sort(t_ps *push_swap);
// static void	ft_sort_stack(t_ps *push_swap);

static void	ft_print_stack(t_sort **stack)
{
	t_sort	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("\naddr %p\n", temp);
		printf("num %d\n", temp->num);
		printf("next %p\n", temp->next);
		temp = temp->next;
	}
}

void	ft_algorithm(t_ps *push_swap)
{
	if (push_swap->len <= 3)
		ft_small_sort(push_swap);
}

static void	ft_small_sort(t_ps *push_swap)
{
	if (ft_llsize(push_swap->stack_a) < 3 && \
		push_swap->stack_a->num > push_swap->stack_a->next->num)
	{
		ft_swap(&push_swap->stack_a, "sa");
		ft_llclear(&push_swap->stack_a, free);
		exit(EXIT_SUCCESS);
	}
	else if (push_swap->stack_a->num > push_swap->stack_a->next->num && \
		push_swap->stack_a->next->num < ft_lllast(push_swap->stack_a)->num)
		ft_rotate(&push_swap->stack_a, "ra");
	else if (push_swap->stack_a->num > push_swap->stack_a->next->num && \
		push_swap->stack_a->next->num > ft_lllast(push_swap->stack_a)->num)
	{
		ft_rotate(&push_swap->stack_a, "ra");
		ft_swap(&push_swap->stack_a, "sa");
	}
	else if (push_swap->stack_a->num < push_swap->stack_a->next->num && \
		push_swap->stack_a->next->num > ft_lllast(push_swap->stack_a)->num
		&& push_swap->stack_a->num < ft_lllast(push_swap->stack_a)->num)
	{
		ft_swap(&push_swap->stack_a, "sa");
		ft_rotate(&push_swap->stack_a, "ra");
	}
	else if (push_swap->stack_a->num < push_swap->stack_a->next->num && \
		push_swap->stack_a->num > ft_lllast(push_swap->stack_a)->num)
		ft_reverse_rotate(&push_swap->stack_a, "rra");
	else if (ft_is_sorted(push_swap) && push_swap->stack_b == NULL)
	{
		ft_print_stack(&push_swap->stack_a);
		ft_llclear(&push_swap->stack_a, free);
		exit(EXIT_SUCCESS);
	}
	else if (ft_is_sorted(push_swap) && push_swap->stack_b != NULL)
	{
		while (ft_llsize(push_swap->stack_b))
			ft_push(&push_swap->stack_b, &push_swap->stack_a, "pa");
	}
	ft_small_sort(push_swap);
}

// static void	ft_sort_stack(t_ps *push_swap)
// {
// 	t_sort *temp;

// 	if (push_swap->last == push_swap->min)
// 		ft_reverse_rotate(&push_swap->stack_a, "rra");
// 	if (push_swap->last == push_swap->max)
// 		ft_rotate(&push_swap->stack_a, "ra");
// 	temp = push_swap->stack_a;
// 	while (temp->num != push_swap->last || ft_llsize(push_swap->stack_a) > 3)
// 	{
// 		if (temp->num < push_swap->last)
// 			ft_push(&push_swap->stack_a, &push_swap->stack_b, "pb");
// 		ft_rotate(&push_swap->stack_a, "ra");
// 		temp = push_swap->stack_a;
// 	}
// 	if (ft_llsize(push_swap->stack_a) == 3)
// 		ft_small_sort(push_swap);
// 	push_swap->last = push_swap->stack_a->num;
// }
