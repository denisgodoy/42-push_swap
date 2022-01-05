/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:57:07 by degabrie          #+#    #+#             */
/*   Updated: 2022/01/04 22:10:24 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_index_lookup(t_ps *push_swap);
static int	ft_get_index(int look4, t_ps *push_swap);
static void	ft_which_stack(t_ps *push_swap);
static int	ft_mkup1(t_ps *push_swap);
static int	ft_mkup2(t_ps *push_swap);

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
	push_swap->mid = push_swap->args[i / 2];
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
	push_swap->last = push_swap->len - 1;
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
	int		mkup1;
	int		mkup2;
	int		index1;
	int		index2;

	head = push_swap->stack_a;
	push_swap->count_pb = 0;
	mkup1 = ft_mkup1(push_swap);
	index1 = push_swap->stack_a->index;
	push_swap->stack_a = head;
	mkup2 = ft_mkup2(push_swap);
	index2 = push_swap->stack_a->index;
	if (mkup1 < mkup2)
	{
		ft_mkup1(push_swap);
		push_swap->count_pb = mkup1;
	}
	else if (mkup1 == mkup2)
	{
		if (index1 < index2)
			push_swap->count_pb = ft_mkup1(push_swap);
		else
			push_swap->count_pb = mkup2;
	}
	else
		push_swap->count_pb = mkup2;
	printf("mkup1 %d - mkup2 %d\n", mkup1, mkup2);
	// if (push_swap->count_pb == push_swap->len)
	// {
	// 	exit(EXIT_SUCCESS);
	// }
}

static int	ft_mkup1(t_ps *push_swap)
{
	t_sort	*head;
	int		mkup1;

	mkup1 = 0;
	head = push_swap->stack_a;
	if (push_swap->stack_a->index == push_swap->last)
	{
		ft_rotate(&push_swap->stack_a, NULL);
		head = push_swap->stack_a;
	}
	push_swap->pivot = push_swap->stack_a->index;
	while (push_swap->stack_a != NULL)
	{
		if (push_swap->stack_a->index == push_swap->pivot)
		{
			push_swap->stack_a->keep = B;
			push_swap->count_pb++;
			mkup1++;
		}
		else if (push_swap->stack_a->index == push_swap->pivot + 1)
		{
			push_swap->stack_a->keep = B;
			push_swap->pivot = push_swap->stack_a->index;
			push_swap->count_pb++;
			mkup1++;
		}
		else
			push_swap->stack_a->keep = A;
		push_swap->stack_a = push_swap->stack_a->next;
	}
	push_swap->stack_a = head;
	return (mkup1);
}

static int	ft_mkup2(t_ps *push_swap)
{
	t_sort	*head;
	int		mkup2;

	mkup2 = 0;
	head = push_swap->stack_a;
	push_swap->pivot = push_swap->mid;
	while (push_swap->stack_a != NULL)
	{
		if (push_swap->stack_a->num >= push_swap->pivot)
		{
			push_swap->stack_a->keep = B;
			push_swap->count_pb++;
			mkup2++;
		}
		else
			push_swap->stack_a->keep = A;
		push_swap->stack_a = push_swap->stack_a->next;
	}
	push_swap->stack_a = head;
	return (mkup2);
}
