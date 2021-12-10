/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:19:18 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 11:20:05 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	push_swap;
	int		i;

	if (ft_check_args(&push_swap, argc, argv))
	{
		ft_putendl_fd("Error", STDERR);
		return (-1);
	}
	else if (!ft_algorithm(&push_swap))
		return (-1);
	push_swap.stack_a = ft_llnew(push_swap.args[0]);
	i = 0;
	while (++i < push_swap.len)
		ft_lladd_back(&push_swap.stack_a, ft_llnew(push_swap.args[i]));
	ft_swap_a(&push_swap);
	ft_rotate_a(&push_swap);
	ft_reverse_rotate_a(&push_swap);
	while (push_swap.stack_a != NULL)
	{
		ft_putendl_fd("", STDIN);
		printf("stack %p\n", push_swap.stack_a);
		printf("next %p\n", push_swap.stack_a->next);
		printf("num %d\n", push_swap.stack_a->num);
		push_swap.stack_a = push_swap.stack_a->next;
	}
	free(push_swap.args);
	exit(EXIT_SUCCESS);
}
