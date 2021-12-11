/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:24:57 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/11 19:03:31 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_small_algo(t_ps *push_swap)
{
	int	i;
	int	j;
	static int	flag;

	i = -1;
	if (push_swap->stack_a->num == push_swap->max)
		ft_rotate(&push_swap->stack_a, "ra");
	if (ft_is_sorted(push_swap) && push_swap->stack_b == NULL)
	{
		ft_llclear(&push_swap->stack_a, &free);
		exit(EXIT_SUCCESS);
	}
	if (ft_llsize(push_swap->stack_a) > 3 && !flag)
	{
		flag++;
		while (++i < push_swap->len - 3)
			ft_push(&push_swap->stack_a, &push_swap->stack_b, "pb");
	}
	if (push_swap->stack_a->num > push_swap->stack_a->next->num &&
			push_swap->stack_a->next->num < ft_lllast(push_swap->stack_a)->num)
		ft_rotate(&push_swap->stack_a, "ra");
	if (push_swap->stack_a->num > push_swap->stack_a->next->num &&
			push_swap->stack_a->next->num > ft_lllast(push_swap->stack_a)->num)
	{
		ft_rotate(&push_swap->stack_a, "ra");
		ft_swap(&push_swap->stack_a, "sa");
	}
	if (push_swap->stack_a->num < push_swap->stack_a->next->num &&
			push_swap->stack_a->next->num > push_swap->stack_a->next->next->num
			&& push_swap->stack_a->num < ft_lllast(push_swap->stack_a)->num)
	{
		ft_swap(&push_swap->stack_a, "sa");
		ft_rotate(&push_swap->stack_a, "ra");
	}
	if (push_swap->stack_a->num < push_swap->stack_a->next->num &&
			push_swap->stack_a->num > ft_lllast(push_swap->stack_a)->num)
		ft_reverse_rotate(&push_swap->stack_a, "rra");
	if (push_swap->stack_b != NULL)
	{
		if (push_swap->stack_b->num < push_swap->stack_b->next->num &&
				ft_llsize(push_swap->stack_b) > 1)
			ft_swap(&push_swap->stack_b, "sb");
		j = -1;
		while (++j < i)
			ft_push(&push_swap->stack_b, &push_swap->stack_a, "pa");
	}
	ft_small_algo(push_swap);
}

int	ft_algorithm(t_ps *push_swap)
{
	if (ft_is_sorted(push_swap) && push_swap->stack_b == NULL)
	{
		ft_llclear(&push_swap->stack_a, &free);
		exit(EXIT_SUCCESS);
	}
	if (push_swap->len <= 5)
		ft_small_algo(push_swap);
	return (1);
}
