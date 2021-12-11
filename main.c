/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:19:18 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 21:03:29 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_print_stack(t_sort **stack);

int	main(int argc, char **argv)
{
	t_ps	push_swap;

	if (ft_check_args(&push_swap, argc, argv))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_init_stacks(&push_swap);
	ft_algorithm(&push_swap);
	ft_llclear(&push_swap.stack_a, &free);
	// printf("\nstack b size %d\n", ft_llsize(push_swap.stack_b));
	// ft_print_stack(&push_swap.stack_b);
	// printf("\nstack a size %d\n", ft_llsize(push_swap.stack_a));
	// ft_print_stack(&push_swap.stack_a);
	exit(EXIT_SUCCESS);
}

static void	ft_print_stack(t_sort **stack)
{
	while (*stack != NULL)
	{
		printf("\naddr %p\n", *stack);
		printf("next %p\n", (*stack)->next);
		printf("num %d\n", (*stack)->num);
		*stack = (*stack)->next;
	}
}
