/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:19:18 by degabrie          #+#    #+#             */
/*   Updated: 2022/04/27 23:09:53 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_print_stack(t_sort **stack);

// static void	ft_print_lis(t_ps *push_swap)
// {
// 	int	i;

// 	ft_printf("\n");
// 	i = -1;
// 	while (++i < push_swap->len)
// 		ft_printf("lis %d\n", push_swap->lis[i]);
// }

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
	ft_printf("\n##############################\nstack b size %d\n", ft_llsize(push_swap.stack_b));
	ft_print_stack(&push_swap.stack_b);
	ft_printf("\n##############################\nstack a size %d\n", ft_llsize(push_swap.stack_a));
	ft_print_stack(&push_swap.stack_a);
	// ft_print_lis(&push_swap);
	return (0);
}

static void	ft_print_stack(t_sort **stack)
{
	t_sort	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		// ft_printf("\naddr %p\n", temp);
		ft_printf("NUM %d\n", temp->num);
		ft_printf("index %d\n", temp->index);
		ft_printf("keep %d\n", temp->keep);
		ft_printf("move a %d\n", temp->move[0]);
		ft_printf("move b %d\n\n", temp->move[1]);
		// ft_printf("move b %d\n", temp->move[1]);
		// ft_printf("lis %d\n", temp->lis);
		// ft_printf("next %p\n", temp->next);
		temp = temp->next;
	}
}
