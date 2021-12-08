/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:24:57 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/08 19:39:47 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	ft_operation(char *operation);
static int	ft_small_algo(t_ps *push_swap);

int	ft_algorithm(t_ps *push_swap)
{
	if (ft_is_sorted(push_swap))
		return (0);
	else if (push_swap->len <= 3)
		return (ft_small_algo(push_swap));
	return (1);
}

static int	ft_operation(char *operation)
{
	ft_putendl_fd(operation, STDIN);
	return (1);
}

static int	ft_small_algo(t_ps *push_swap)
{
	int	i;

	i = 0;
	if (push_swap->args[i] > push_swap->args[i + 1])
	{
		if (push_swap->args[i] < push_swap->args[push_swap->len - 1])
			return (ft_operation("sa"));
		else if (push_swap->args[i + 1] > push_swap->args[push_swap->len - 1])
		{
			ft_operation("sa");
			return (ft_operation("rra"));
		}
		else if (push_swap->args[i + 1] < push_swap->args[push_swap->len - 1])
			return (ft_operation("ra"));
	}
	else if (push_swap->args[i + 1] < push_swap->args[push_swap->len - 1])
	{
		ft_operation("ra");
		ft_operation("sa");
	}
	return (ft_operation("rra"));
}
