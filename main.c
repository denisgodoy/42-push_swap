/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:19:18 by degabrie          #+#    #+#             */
/*   Updated: 2022/01/13 00:00:07 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_print_stack(t_sort **stack);

// static void	ft_print_lis(t_ps *push_swap)
// {
// 	int	i;

// 	printf("\n");
// 	i = -1;
// 	while (++i < push_swap->len)
// 		printf("lis %d\n", push_swap->lis[i]);
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
	printf("\n##############################\nstack b size %d\n", ft_llsize(push_swap.stack_b));
	ft_print_stack(&push_swap.stack_b);
	printf("\n##############################\nstack a size %d\n", ft_llsize(push_swap.stack_a));
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
		printf("\naddr %p\n", temp);
		printf("num %d\n", temp->num);
		printf("index %d\n", temp->index);
		printf("keep %d\n", temp->keep);
		printf("lis %d\n", temp->lis);
		printf("next %p\n", temp->next);
		temp = temp->next;
	}
}
