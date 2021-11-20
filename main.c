/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:19:18 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/20 19:38:22 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_args(t_ps *push_swap, int argc, char **argv);
static int	ft_direct_argv(t_ps *push_swap, int argc, char **argv);
static int	ft_alloc_args(t_ps *push_swap, int size);
static int	ft_only_spaces(char *arg);

int	main(int argc, char **argv)
{
	int		i;
	t_ps	push_swap;

	if (ft_check_args(&push_swap, argc, argv) < 0)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (push_swap.args[++i])
		printf("%d\n", push_swap.args[i]);
	free(push_swap.args);
	exit(EXIT_SUCCESS);
}

static int	ft_check_args(t_ps *push_swap, int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		exit(EXIT_FAILURE);
	else if (ft_strchr(argv[1], ' '))
	{
		if (ft_only_spaces(argv[1]))
			exit(EXIT_FAILURE);
		push_swap->temp = ft_split(argv[1], ' ');
		i = -1;
		while (push_swap->temp[++i])
		{
			if (ft_atoi(push_swap->temp[i]) >= 0)
			{
				j = -1;
				while (push_swap->temp[i][++j])
					if (!ft_isdigit(push_swap->temp[i][j]))
						return (ft_free_temp(push_swap));
			}
			else
			{
				j = 0;
				while (push_swap->temp[i][++j])
					if (!ft_isdigit(push_swap->temp[i][j]))
						return (ft_free_temp(push_swap));
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

	push_swap->args = (int *)ft_calloc(size + 1, sizeof(int));
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
	int	k;

	push_swap->args = (int *)ft_calloc(argc, sizeof(int));
	i = 0;
	k = 0;
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) < 0)
		{
			j = 0;
			while (argv[i][++j])
			{
				if (!ft_isdigit(argv[i][j]))
				{
					free(push_swap->args);
					return (-1);
				}
			}
		}
		else
		{
			j = -1;
			while (argv[i][++j])
			{
				if (!ft_isdigit(argv[i][j]))
				{
					free(push_swap->args);
					return (-1);
				}
			}
		}
		push_swap->args[k++] = ft_atoi(argv[i]);
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
