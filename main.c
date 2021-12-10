/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:19:18 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/10 17:39:56 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_print_stack(t_sort **stack)
{
	while (*stack != NULL)
	{
		ft_putendl_fd("", STDIN_FILENO);
		printf("stack %p\n", *stack);
		printf("next %p\n", (*stack)->next);
		printf("num %d\n", (*stack)->num);
		*stack = (*stack)->next;
	}
}

int	main(int argc, char **argv)
{
	t_ps	push_swap;
	int		i;

	if (ft_check_args(&push_swap, argc, argv))
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (-1);
	}
	else if (!ft_algorithm(&push_swap))
		return (-1);
	push_swap.stack_a = ft_llnew(push_swap.args[0]);
	push_swap.stack_b = NULL;
	i = 0;
	while (++i < push_swap.len)
		ft_lladd_back(&push_swap.stack_a, ft_llnew(push_swap.args[i]));
	//ft_swap(&push_swap.stack_a, "sa");
	//ft_rotate(&push_swap.stack_a, "ra");
	//ft_reverse_rotate(&push_swap.stack_a, "rra");
	ft_push_b(&push_swap);
	//ft_push_a(&push_swap);
	ft_swap_both(&push_swap);
	//ft_rotate_both(&push_swap);
	//ft_reverse_rotate_both(&push_swap);
	printf("\nstack b size %d\n", ft_llsize(push_swap.stack_b));
	ft_print_stack(&push_swap.stack_b);
	printf("\nstack a size %d\n", ft_llsize(push_swap.stack_a));
	ft_print_stack(&push_swap.stack_a);
	free(push_swap.args);
	exit(EXIT_SUCCESS);
}
