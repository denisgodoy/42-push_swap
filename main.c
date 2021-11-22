/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:19:18 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/22 20:24:52 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_args(t_ps *push_swap, int argc, char **argv, int i);
static int	ft_direct_argv(t_ps *push_swap, int argc, char **argv);
static int	ft_alloc_args(t_ps *push_swap, int size);
static int	ft_only_spaces(char *arg);

int	main(int argc, char **argv)
{
	int		i;
	t_ps	push_swap;

	if (ft_check_args(&push_swap, argc, argv, -1) < 0)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	else if (ft_is_duplicate(&push_swap) < 0)
	{
		free(push_swap.args);
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < push_swap.arr_len)
	{
		printf("%d\n", push_swap.args[i]);
		i++;
	}
	free(push_swap.args);
	exit(EXIT_SUCCESS);
}

static int	ft_check_args(t_ps *push_swap, int argc, char **argv, int i)
{
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
			if (ft_atoi(push_swap->temp[i]) >= 0)
			{
				if (ft_check_digits(push_swap, push_swap->temp[i], 0) < 0)
					return (ft_free_arr(push_swap->temp));
			}
			else
			{
				if (ft_check_digits(push_swap, push_swap->temp[i] + 1, 0) < 0)
					return (ft_free_arr(push_swap->temp));
			}
		}
		return (ft_alloc_args(push_swap, i));
	}
	return (ft_direct_argv(push_swap, argc, argv));
}

static int	ft_alloc_args(t_ps *push_swap, int size)
{
	int	i;
	int	j;

	push_swap->arr_len = size;
	push_swap->args = (int *)malloc(size * sizeof(int));
	if (!push_swap->args)
	{
		ft_free_arr(push_swap->temp);
		exit(EXIT_FAILURE);
	}
	i = -1;
	j = 0;
	while (push_swap->temp[++i])
	{
		push_swap->args[j++] = ft_atoi(push_swap->temp[i]);
		free(push_swap->temp[i]);
	}
	free(push_swap->temp);
	return (0);
}

static int	ft_direct_argv(t_ps *push_swap, int argc, char **argv)
{
	int	i;
	int	j;

	push_swap->arr_len = argc - 1;
	push_swap->args = (int *)malloc((argc - 1) * sizeof(int));
	if (!push_swap->args)
		exit(EXIT_FAILURE);
	i = 0;
	j = 0;
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) < 0)
		{
			if (ft_check_digits(push_swap, argv[i] + 1, 1) < 0)
				return (-1);
		}
		else
		{
			if (ft_check_digits(push_swap, argv[i], 1) < 0)
				return (-1);
		}
		push_swap->args[j++] = ft_atoi(argv[i]);
	}
	return (0);
}

static int	ft_only_spaces(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
