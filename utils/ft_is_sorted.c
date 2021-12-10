/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:01:20 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 20:04:39 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_is_sorted(t_ps *push_swap)
{
	t_sort *temp;

	temp = push_swap->stack_a;
	while (temp->next != NULL)
	{
		if (temp->num > temp->next->num)
				return (0);
		temp = temp->next;
	}
	return (1);
}
