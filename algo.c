/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:24:57 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 00:02:50 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	ft_operation(char *operation);


int	ft_small_algo(t_ps *push_swap, int *args)
{
	int	i;

	i = 0;
	if (args[i] > args[i + 1])
	{
		if (args[i] < args[push_swap->len - 1])
			return (ft_operation("sa"));
		else if (args[i + 1] > args[push_swap->len - 1])
		{
			ft_operation("sa");
			return (ft_operation("rra"));
		}
		else if (args[i + 1] < args[push_swap->len - 1])
			return (ft_operation("ra"));
	}
	else if (args[i + 1] < args[push_swap->len - 1])
	{
		ft_operation("ra");
		ft_operation("sa");
	}
	else if (args[i] < args[push_swap->len - 1])
	{
		ft_operation("sa");
		return (ft_operation("ra"));
	}
	return (ft_operation("rra"));
}

int	ft_algorithm(t_ps *push_swap)
{
	int	midpoint;

	midpoint = ft_is_sorted(push_swap);
	//if (push_swap->len <= 3)
	//	return (ft_small_algo(push_swap, push_swap->args));
	return (1);
}

static int	ft_operation(char *operation)
{
	ft_putendl_fd(operation, STDIN);
	return (1);
}
