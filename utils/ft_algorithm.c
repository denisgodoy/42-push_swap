/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:24:57 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/12 10:46:10 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_small_sort(t_ps *push_swap);

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
		ft_llclear(&push_swap->stack_a, free);
		exit(EXIT_SUCCESS);
	}
	ft_small_sort(push_swap);
}
