/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:19:18 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/29 21:05:44 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	push_swap;
	int		median;
	int		i;

	if (ft_check_args(&push_swap, argc, argv))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	median = ft_sort_arr(&push_swap);
	printf("%d\n\n", median);
	i = -1;
	while (++i < push_swap.len)
		printf("%d\n", push_swap.args[i]);
	free(push_swap.args);
	exit(EXIT_SUCCESS);
}
