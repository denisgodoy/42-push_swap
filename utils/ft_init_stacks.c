/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:57:07 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/23 16:33:18 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_index_lookup(t_ps *push_swap);
static int	ft_get_index(int look4, t_ps *push_swap);
static void	ft_which_stack(t_ps *push_swap);

void	ft_init_stacks(t_ps *push_swap)
{
	int	i;

	push_swap->stack_a = ft_llnew(*push_swap->args);
	push_swap->stack_b = NULL;
	push_swap->min = *push_swap->args;
	push_swap->max = *push_swap->args;
	i = 0;
	while (++i < push_swap->len)
	{
		if (push_swap->args[i] > push_swap->max)
			push_swap->max = push_swap->args[i];
		if (push_swap->args[i] < push_swap->min)
			push_swap->min = push_swap->args[i];
		ft_lladd_back(&push_swap->stack_a, ft_llnew(push_swap->args[i]));
	}
	push_swap->last = ft_lllast(push_swap->stack_a)->num;
	ft_index_lookup(push_swap);
	free(push_swap->sorted);
	free(push_swap->args);
}

static void	ft_index_lookup(t_ps *push_swap)
{
	t_sort	*head;

	head = push_swap->stack_a;
	while (ft_llsize(push_swap->stack_a))
	{
		push_swap->stack_a->index = ft_get_index(push_swap->stack_a->num, push_swap);
		push_swap->stack_a = push_swap->stack_a->next;
	}
	push_swap->stack_a = head;
	ft_which_stack(push_swap);
}

static int	ft_get_index(int look4, t_ps *push_swap)
{
	int		i;

	i = -1;
	while (++i < push_swap->len)
	{
		if (push_swap->sorted[i] == look4)
			return (i);
	}
	return (0);
}

static void	ft_which_stack(t_ps *push_swap)
{
	t_sort	*head;

	head = push_swap->stack_a;
	push_swap->pivot = push_swap->stack_a->index + 1;
	while (push_swap->stack_a != NULL)
	{
		if (push_swap->stack_a->index == push_swap->pivot || \
				push_swap->stack_a->index == 0)
		{
			push_swap->stack_a->keep = A;
			push_swap->pivot = push_swap->stack_a->index + 1;
		}
		else
			push_swap->stack_a->keep = B;
		push_swap->stack_a = push_swap->stack_a->next;
	}
	push_swap->stack_a = head;
}
