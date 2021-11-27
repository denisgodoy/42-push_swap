/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:25:03 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/26 22:06:39 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	ft_alloc_args(t_ps *push_swap, int size);
static int	ft_direct_argv(t_ps *push_swap, int argc, char **argv);
static int	ft_only_spaces(char *arg);

int	ft_check_args(t_ps *push_swap, int argc, char **argv)
{
	int	i;

	if (argc == 1 || ft_only_spaces(argv[1]))
		exit(EXIT_FAILURE);
	else if (ft_strchr(argv[1], ' '))
	{
		push_swap->temp = ft_split(argv[1], ' ');
		if (!push_swap->temp)
			exit(EXIT_FAILURE);
		i = -1;
		while (push_swap->temp[++i])
		{
			if (ft_atoi(push_swap->temp[i]) < 0)
			{
				if (ft_check_digits(push_swap, push_swap->temp[i] + 1, str))
					return (ft_free_arr(push_swap->temp));
			}
			else if (ft_check_digits(push_swap, push_swap->temp[i], str))
				return (ft_free_arr(push_swap->temp));
		}
		return (ft_alloc_args(push_swap, i));
	}
	return (ft_direct_argv(push_swap, argc, argv));
}

static int	ft_alloc_args(t_ps *push_swap, int size)
{
	int	i;

	push_swap->len = size;
	if (push_swap->len == 1)
	{
		ft_free_arr(push_swap->temp);
		exit(EXIT_FAILURE);
	}
	push_swap->args = (int *)malloc(size * sizeof(int));
	if (!push_swap->args)
	{
		ft_free_arr(push_swap->temp);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (push_swap->temp[++i])
		push_swap->args[i] = ft_atoi(push_swap->temp[i]);
	ft_free_arr(push_swap->temp);
	return (ft_is_duplicate(push_swap));
}

static int	ft_direct_argv(t_ps *push_swap, int argc, char **argv)
{
	int	i;

	push_swap->len = argc - 1;
	push_swap->args = (int *)malloc((argc - 1) * sizeof(int));
	if (!push_swap->args)
		exit(EXIT_FAILURE);
	i = 0;
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) < 0)
		{
			if (ft_check_digits(push_swap, argv[i] + 1, cmd))
				return (1);
		}
		else if (ft_check_digits(push_swap, argv[i], cmd))
			return (1);
		push_swap->args[i - 1] = ft_atoi(argv[i]);
	}
	if (push_swap->len == 1)
	{
		free(push_swap->args);
		exit(EXIT_FAILURE);
	}
	return (ft_is_duplicate(push_swap));
}

static int	ft_only_spaces(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (arg[i] != ' ')
			return (0);
	return (1);
}
