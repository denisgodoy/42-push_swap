/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:01:20 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/08 18:28:20 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_is_sorted(t_ps *push_swap)
{
	int	i;
	int	j;

	i = -1;
	while (++i < push_swap->len)
	{
		j = i;
		while (++j < push_swap->len)
			if (push_swap->args[i] > push_swap->args[j])
				return (0);
	}
	free(push_swap->args);
	return (1);
}
