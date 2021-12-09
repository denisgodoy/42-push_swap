/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:24:57 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/08 21:35:05 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	ft_operation(char *operation);
static int	ft_small_algo(t_ps *push_swap, int *args);
static int	ft_2stack_algo(t_ps *push_swap, int *args);

int	ft_algorithm(t_ps *push_swap)
{
	if (ft_is_sorted(push_swap))
		return (0);
	else if (push_swap->len <= 3)
		return (ft_small_algo(push_swap, push_swap->args));
	else if (push_swap->len <= 5)
		return (ft_2stack_algo(push_swap, push_swap->args));
	return (1);
}

static int	ft_operation(char *operation)
{
	ft_putendl_fd(operation, STDIN);
	return (1);
}

static int	ft_2stack_algo(t_ps *push_swap, int *args)
{
	int	*stack_a;
	int	*stack_b;
	int	i;
	int	j;

	push_swap->len -= 3;
	stack_b = (int *)malloc(push_swap->len * sizeof(int));
	i = -1;
	while (++i < push_swap->len)
	{
		stack_b[i] = args[i];
		ft_operation("pb");
	}
	ft_small_algo(push_swap, stack_b);
	push_swap->len = 3;
	stack_a = (int *)malloc(push_swap->len * sizeof(int));
	j = -1;
	while (++j < push_swap->len)
		stack_a[j] = args[i++];
	ft_small_algo(push_swap, stack_a);
	while (i - 3)
	{
		ft_operation("pa");
		i--;
	}
	return (1);
}

static int	ft_small_algo(t_ps *push_swap, int *args)
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
	return (ft_operation("rra"));
}
