/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:53:09 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/20 00:56:17 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_free_temp(t_ps *push_swap)
{
	int	i;

	i = -1;
	while (push_swap->temp[++i])
		free(push_swap->temp[i]);
	free(push_swap->temp);
	return (-1);
}
