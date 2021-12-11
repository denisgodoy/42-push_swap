/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:57:07 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 20:57:19 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_init_stacks(t_ps *push_swap)
{
	int	i;

	push_swap->stack_a = ft_llnew(push_swap->args[0]);
	push_swap->stack_b = NULL;
	i = 0;
	while (++i < push_swap->len)
		ft_lladd_back(&push_swap->stack_a, ft_llnew(push_swap->args[i]));
	free(push_swap->args);
}