/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:24:57 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 20:08:17 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_algorithm(t_ps *push_swap)
{
	if (ft_is_sorted(push_swap) && push_swap->stack_b == NULL)
	{
		ft_llclear(&push_swap->stack_a, &free);
		exit(EXIT_SUCCESS);
	}
	return (1);
}
