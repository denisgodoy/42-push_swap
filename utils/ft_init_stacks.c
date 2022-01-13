/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:57:07 by degabrie          #+#    #+#             */
/*   Updated: 2022/01/13 00:00:56 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_index_lookup(t_ps *push_swap);
static int	ft_get_index(int look4, t_ps *push_swap);
static void	ft_which_stack(t_ps *push_swap);
static void	ft_mkup1(t_ps *push_swap);
void	lis(t_ps *push_swap);
void	keep_or_push(t_ps *push_swap);
void	reverse_ll(t_sort **head_ref);

void	ft_init_stacks(t_ps *push_swap)
{
	int	i;

	push_swap->stack_a = ft_llnew(*push_swap->args);
	push_swap->stack_b = NULL;
	push_swap->min = *push_swap->args;
	push_swap->max = *push_swap->args;
	push_swap->min_pos = 0;
	i = 0;
	while (++i < push_swap->len)
	{
		if (push_swap->args[i] > push_swap->max)
			push_swap->max = push_swap->args[i];
		if (push_swap->args[i] < push_swap->min)
		{
			push_swap->min = push_swap->args[i];
			push_swap->min_pos = i;
		}
		ft_lladd_back(&push_swap->stack_a, ft_llnew(push_swap->args[i]));
	}
	ft_index_lookup(push_swap);
	free(push_swap->sorted);
	//free(push_swap->args);
}

static void	ft_index_lookup(t_ps *push_swap)
{
	t_sort	*head;

	head = push_swap->stack_a;
	while (ft_llsize(push_swap->stack_a))
	{
		push_swap->stack_a->index = ft_get_index(push_swap->stack_a->num, push_swap);
		push_swap->stack_a = push_swap->stack_a->next;
	}
	push_swap->stack_a = head;
	push_swap->last = push_swap->len - 1;
	ft_which_stack(push_swap);
}

static int	ft_get_index(int look4, t_ps *push_swap)
{
	int	i;

	i = -1;
	while (++i < push_swap->len)
	{
		if (push_swap->sorted[i] == look4)
			return (i);
	}
	return (0);
}

static void	ft_which_stack(t_ps *push_swap)
{
	t_sort	*head;

	head = push_swap->stack_a;
	push_swap->count_pb = 0;
	ft_mkup1(push_swap);
	// if (push_swap->count_pb == push_swap->len)
	// {
	// 	exit(EXIT_SUCCESS);
	// }
}

void	reverse_ll(t_sort **head)
{
	t_sort *prev;
    t_sort *current;
    t_sort *next;

	prev = NULL;
	current = *head;
	next = NULL;
    while (current != NULL)
	{
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int	max_lis(t_ps *push_swap)
{
	int	i;
	int	len;
	int	max_lis;

	len = push_swap->len;
	max_lis = 1;
	i = -1;
	while (len--)
		if (max_lis < push_swap->lis[++i])
			max_lis = push_swap->lis[i];
	free(push_swap->lis);
	return (max_lis);
}

void	keep_or_push(t_ps *push_swap)
{
	t_sort	*head;
	int		flag;

	flag = 0;
	reverse_ll(&push_swap->stack_a);
	head = push_swap->stack_a;
	push_swap->pivot = max_lis(push_swap);
	while (push_swap->stack_a != NULL)
	{
		if (push_swap->stack_a->lis == push_swap->pivot - 1 || \
				(push_swap->stack_a->lis == push_swap->pivot && !flag))
		{
			push_swap->pivot = push_swap->stack_a->lis;
			flag++;
		}
		else
		{
			push_swap->stack_a->keep = B;
			push_swap->count_pb++;
		}
		push_swap->stack_a = push_swap->stack_a->next;
	}
	push_swap->stack_a = head;
	reverse_ll(&push_swap->stack_a);
}

static void	ft_mkup1(t_ps *push_swap)
{
	int	count;

	count = 0;
	while (push_swap->stack_a->num != push_swap->min)
	{
		if (push_swap->min_pos < push_swap->len / 2)
			ft_rotate(&push_swap->stack_a, NULL);
		else
			ft_reverse_rotate(&push_swap->stack_a, NULL);
		count++;
	}
	lis(push_swap);
	keep_or_push(push_swap);
	while (count)
	{
		if (push_swap->min_pos < push_swap->len / 2)
			ft_reverse_rotate(&push_swap->stack_a, NULL);
		else
			ft_rotate(&push_swap->stack_a, NULL);
		count--;
	}
}

static int	*ft_intdup(t_sort **arr, int len)
{
	t_sort	*head;
	int		*ptr;
	int		i;

	head = *arr;
	ptr = (int *)malloc(len * sizeof(int));
	i = -1;
	while (*arr != NULL)
	{
		ptr[++i] = (*arr)->num;
		*arr = (*arr)->next;
	}
	*arr = head;
	return (ptr);
}

static int	*ft_lisdup(int len)
{
	int	*ptr;
	int	i;

	ptr = (int *)malloc(len * sizeof(int));
	i = -1;
	while (++i < len)
		ptr[i] = 1;
	return (ptr);
}

void	lis_to_list(t_ps *push_swap)
{
	t_sort	*head;
	int		i;

	head = push_swap->stack_a;
	i = -1;
	while (push_swap->stack_a != NULL)
	{
		push_swap->stack_a->lis = push_swap->lis[++i];
		push_swap->stack_a = push_swap->stack_a->next;
	}
	push_swap->stack_a = head;
}

void	lis(t_ps *push_swap)
{
	int	*arr;
	int	i;
	int	j;

	arr = ft_intdup(&push_swap->stack_a, push_swap->len);
	push_swap->lis = ft_lisdup(push_swap->len);
	i = 1;
	j = 0;
	while (i < push_swap->len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && push_swap->lis[i] <= push_swap->lis[j])
			{
				push_swap->lis[i] = push_swap->lis[j] + 1;
			}
			j++;
		}
		i++;
	}
	free(arr);
	lis_to_list(push_swap);
}
