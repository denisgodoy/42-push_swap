/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:40:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/11 20:49:19 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_get_max_min(t_ps *push_swap);

int	ft_is_duplicate(t_ps *push_swap)
{
	int	i;
	int	j;

	i = -1;
	while (++i < push_swap->len)
	{
		j = i;
		while (++j < push_swap->len)
		{
			if (push_swap->args[i] == push_swap->args[j])
			{
				free(push_swap->args);
				return (1);
			}
		}
	}
	ft_get_max_min(push_swap);
	return (0);
}

int	ft_check_digits(t_ps *push_swap, char *arg, int input)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
		{
			if (input)
				free(push_swap->args);
			return (1);
		}
	}
	return (0);
}

static void	ft_get_max_min(t_ps *push_swap)
{
	int	i;

	push_swap->min = *push_swap->args;
	push_swap->max = *push_swap->args;
	i = 0;
	while (++i < push_swap->len)
	{
		if (push_swap->args[i] > push_swap->max)
			push_swap->max = push_swap->args[i];
		if (push_swap->args[i] < push_swap->min)
			push_swap->min = push_swap->args[i];
	}
}
