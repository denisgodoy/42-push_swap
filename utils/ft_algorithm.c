/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:24:57 by degabrie          #+#    #+#             */
/*   Updated: 2022/04/27 23:23:57 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

// static void	ft_small_sort(t_sort **stack);
// static void	ft_small_sort_reverse(t_sort **stack);
static void	ft_split_stack(t_ps *push_swap);
int 		*ll_to_array(t_sort **stack);
void		nb_position(t_sort *stack, t_ps *push_swap);
// static void	ft_empty_stack(t_ps *push_swap);
// static void	ft_merge_stacks(t_ps *push_swap);

void	ft_algorithm(t_ps *push_swap)
{
	// if (push_swap->len <= 3)
	// 	ft_small_sort(&push_swap->stack_a);
	t_sort	*head;
	int		size;
	int		i;

	ft_split_stack(push_swap);
	i = -1;
	size = ft_llsize(push_swap->stack_b);
	head = push_swap->stack_b;
	while (++i < (size / 2))
	{
		nb_position(push_swap->stack_b, push_swap);
		push_swap->stack_b = push_swap->stack_b->next;
	}
	push_swap->stack_b = head;
	reverse_ll(&push_swap->stack_b);
	head = push_swap->stack_b;
	while (size-- > i)
	{
		nb_position(push_swap->stack_b, push_swap);
		push_swap->stack_b = push_swap->stack_b->next;
	}
	push_swap->stack_b = head;
	reverse_ll(&push_swap->stack_b);
	// push_swap->stack_b = head;
	// ft_radix_sort(&push_swap->stack_a, &push_swap->stack_b);
	// ft_merge_stacks(push_swap);
}

// static void	ft_small_sort(t_sort **stack)
// {
// 	if (ft_llsize(*stack) < 3 && \
// 		(*stack)->num > (*stack)->next->num)
// 	{
// 		ft_swap(stack, "sa");
// 		ft_llclear(stack, free);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else if ((*stack)->num > (*stack)->next->num && \
// 		(*stack)->next->num < ft_lllast((*stack))->num)
// 		ft_rotate(&(*stack), "ra");
// 	else if ((*stack)->num > (*stack)->next->num && \
// 		(*stack)->next->num > ft_lllast((*stack))->num)
// 	{
// 		ft_rotate(stack, "ra");
// 		ft_swap(stack, "sa");
// 	}
// 	else if ((*stack)->num < (*stack)->next->num && \
// 		(*stack)->next->num > ft_lllast((*stack))->num
// 		&& (*stack)->num < ft_lllast((*stack))->num)
// 	{
// 		ft_swap(stack, "sa");
// 		ft_rotate(stack, "ra");
// 	}
// 	else if ((*stack)->num < (*stack)->next->num && \
// 		(*stack)->num > ft_lllast((*stack))->num)
// 		ft_reverse_rotate(&(*stack), "rra");
// 	else if (ft_is_sorted(stack))
// 		return ;
// 	ft_small_sort(stack);
// }

// static void	ft_small_sort_reverse(t_sort **stack)
// {
// 	if (ft_llsize(*stack) < 3 && \
// 		(*stack)->num < (*stack)->next->num)
// 	{
// 		ft_swap(stack, "sa");
// 		return ;
// 	}
// 	else if ((*stack)->num < (*stack)->next->num && \
// 		(*stack)->next->num > ft_lllast((*stack))->num)
// 		ft_rotate(&(*stack), "ra");
// 	else if ((*stack)->num < (*stack)->next->num && \
// 		(*stack)->next->num > ft_lllast((*stack))->num)
// 	{
// 		ft_rotate(stack, "ra");
// 		ft_swap(stack, "sa");
// 	}
// 	else if ((*stack)->num > (*stack)->next->num && \
// 		(*stack)->next->num < ft_lllast((*stack))->num
// 		&& (*stack)->num > ft_lllast((*stack))->num)
// 	{
// 		ft_swap(stack, "sa");
// 		ft_rotate(stack, "ra");
// 	}
// 	else if ((*stack)->num > (*stack)->next->num && \
// 		(*stack)->num < ft_lllast((*stack))->num)
// 		ft_reverse_rotate(&(*stack), "rra");
// 	else if (ft_is_sorted(stack))
// 		return ;
// 	ft_small_sort_reverse(stack);
// }

// void    ft_radix_sort(t_sort **stack_a, t_sort **stack_b)
// {
//     int        i;
//     int        j;
//     int        size;

//     i = 0;
//     size = ft_llsize(*stack_a);
//     while (!ft_is_sorted(stack_a))
//     {
//         j = 0;
//         while (j++ < size)
//         {
//             if ((((*stack_a)->index >> i) & 1) == 1)
//                 ft_rotate(stack_a, "ra");
//             else
//                 ft_push(stack_a, stack_b, "pb");
//         }
//         while (ft_llsize(*stack_b) != 0)
//             ft_push(stack_b, stack_a, "pa");
//         i++;
//     }
// }

static void	ft_split_stack(t_ps *push_swap)
{
	t_sort	*head;
	int		count;

	count = push_swap->count_pb;
	head = push_swap->stack_a;
	while (count)
	{
		if (head->keep == B)
		{
			ft_push(&push_swap->stack_a, &push_swap->stack_b, "pb");
			count--;
		}
		else
			ft_rotate(&push_swap->stack_a, "ra");
		head = push_swap->stack_a;
	}
	// move_stacks(push_swap);
}

int	*ll_to_array(t_sort **stack)
{
	t_sort	*head;
	int		*array;
	int		i;

	i = -1;
	head = (*stack);
	array = (int *)malloc(ft_llsize((*stack)));
	while((*stack) != NULL)
	{
		array[++i] = (*stack)->num;
		(*stack) = (*stack)->next;
	}
	(*stack) = head;
	return(array);
}

void	nb_position(t_sort *stack, t_ps *push_swap)
{
	// t_sort *head;
	int *arr_a;
	int size;
	int i;
	// int	j;

	i = -1;
	size = ft_llsize(push_swap->stack_a);
	arr_a = ll_to_array(&push_swap->stack_a);
	// head = push_swap->stack_a;
	// if (stack->num == push_swap->max)
	// {
	// 	j = 0;
	// 	while (push_swap->stack_a != NULL)
	// 	{
	// 		if (push_swap->stack_a->index == (stack->index - 1))
	// 			stack->move[0] = j;
	// 		j++;
	// 		push_swap->stack_a = push_swap->stack_a->next;
	// 	}
	// 	push_swap->stack_a = head;
	// 	return ;
	// }
	while(++i < (size / 2))
	{
		if (stack->num > arr_a[i] && stack->num < arr_a[i + 1])
		{
			stack->move[0] = i;
			return ;
		}
		// ft_printf("tb %d\n", arr_a[i]);
	}
	while (--size >= i)
	{
		if (stack->num < arr_a[size - 1] && stack->num > arr_a[size - 2])
		{
			// stack->move[0] = size * -1;
			return ;
		}
		// ft_printf("bt %d\n", arr_a[size]);
	}
	free(arr_a);
	return ;
}

// static void	ft_empty_stack(t_ps *push_swap)
// {
// 	int	*arr;
// 	t_sort	*head;
// 	int	i;

// 	i = -1;
// 	head = push_swap->stack_a;
// 	arr = (int *)malloc(ft_llsize(push_swap->stack_a) * sizeof(int));
// 	while (head)
// 	{
// 		arr[++i] = head->num;
// 		head = head->next;
// 	}
// 	if (i == 1)
// 		push_swap->mid = arr[i];
// 	else if (i > 2)
// 		push_swap->mid = arr[i / 2];
// 	else if (arr[0] < arr[1])
// 		push_swap->mid = arr[0];
// 	else
// 		push_swap->mid = arr[1];
// }

// static void	ft_merge_stacks(t_ps *push_swap)
// {
// 	if (push_swap->stack_a->index == push_swap->stack_b->index + 1)
// 	{
// 		ft_push(&push_swap->stack_b, &push_swap->stack_a, "pa");
// 	}
// 	else
// 		ft_rotate_both(push_swap);
// 	if (!ft_llsize(push_swap->stack_b))
// 		return ;
// 	ft_merge_stacks(push_swap);
// }
