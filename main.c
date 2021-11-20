/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:19:18 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/19 21:34:27 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	int	i;

	if (ft_check_args(argc, argv) < 0)
	{
		write(2, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	printf("argc %d\n", argc);
	i = 1;
	while (argv[i])
		printf("argv %s\n", argv[i++]);
	return (0);
}

static int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		exit(EXIT_FAILURE);
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (-1);
	}
	return (0);
}
