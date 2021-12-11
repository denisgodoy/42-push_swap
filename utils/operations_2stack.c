/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:56:48 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/11 18:19:00 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_swap_both(t_ps *push_swap)
{
	int	flag;

	flag = 0;
	if (ft_llsize(push_swap->stack_a) > 1)
	{
		flag++;
		ft_swap(&push_swap->stack_a, NULL);
	}
	if (ft_llsize(push_swap->stack_b) > 1)
	{
		flag++;
		ft_swap(&push_swap->stack_b, NULL);
	}
	if (flag)
		ft_putendl_fd("ss", STDOUT_FILENO);
}

void	ft_rotate_both(t_ps *push_swap)
{
	int	flag;

	flag = 0;
	if (ft_llsize(push_swap->stack_a) > 1)
	{
		flag++;
		ft_rotate(&push_swap->stack_a, NULL);
	}
	if (ft_llsize(push_swap->stack_b) > 1)
	{
		flag++;
		ft_rotate(&push_swap->stack_b, NULL);
	}
	if (flag)
		ft_putendl_fd("rr", STDOUT_FILENO);
}

void	ft_reverse_rotate_both(t_ps *push_swap)
{
	int	flag;

	flag = 0;
	if (ft_llsize(push_swap->stack_a) > 1)
	{
		flag++;
		ft_reverse_rotate(&push_swap->stack_a, NULL);
	}
	if (ft_llsize(push_swap->stack_b) > 1)
	{
		flag++;
		ft_reverse_rotate(&push_swap->stack_b, NULL);
	}
	if (flag)
		ft_putendl_fd("rrr", STDOUT_FILENO);
}
