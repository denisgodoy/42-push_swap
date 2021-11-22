/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:40:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/22 19:33:43 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	ft_is_duplicate(t_ps *push_swap)
{
	int	i;
	int	j;

	i = -1;
	while (++i < push_swap->arr_len)
	{
		j = i;
		while (++j < push_swap->arr_len)
			if (push_swap->args[i] == push_swap->args[j])
				return (-1);
	}
	return (0);
}

int	ft_check_digits(t_ps *push_swap, char *arg, int direct)
{
	int	i;

	i = -1;
	if (direct)
	{
		while (arg[++i])
		{
			if (!ft_isdigit(arg[i]))
			{
				free(push_swap->args);
				return (-1);
			}
		}
		return (0);
	}
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
			return (-1);
	return (0);
}
