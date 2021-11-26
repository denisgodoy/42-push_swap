/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:01:20 by degabrie          #+#    #+#             */
/*   Updated: 2021/11/25 23:20:30 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	*ft_intdup(int *arr, int len);

int	ft_sort_arr(t_ps *push_swap)
{
	int	head;
	int	temp;
	int	*arr;
	int	i;
	int	j;

	arr = ft_intdup(push_swap->args, push_swap->arr_len);
	i = -1;
	while (++i < push_swap->arr_len)
	{
		head = arr[i];
		j = i;
		while (++j < push_swap->arr_len)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[j];
				arr[i] = temp;
				arr[j] = head;
				head = arr[i];
			}
		}
	}
	i = arr[push_swap->arr_len / 2];
	free(arr);
	return(i);
}

static int	*ft_intdup(int *arr, int len)
{
	int	*new_arr;
	int	i;

	new_arr = (int *)malloc(len * sizeof(int));
	i = -1;
	while (++i < len)
		new_arr[i] = arr[i];
	return (new_arr);
}
