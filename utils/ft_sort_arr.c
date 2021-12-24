/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:21:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/23 21:00:19 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	*ft_intdup(int *arr, int len);

void	ft_sort_arr(t_ps *push_swap)
{
	int	temp;
	int	*arr;
	int	flag;
	int	i;
	int	j;

	arr = ft_intdup(push_swap->args, push_swap->len);
	flag = 0;
	i = -1;
	while (++i < push_swap->len)
	{
		j = i;
		while (++j < push_swap->len)
		{
			if (arr[i] > arr[j])
			{
				flag = 1;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	push_swap->sorted = arr;
	if (!flag)
	{
		free(arr);
		exit(EXIT_SUCCESS);
	}
	push_swap->mid = arr[push_swap->len / 2];
}

static int	*ft_intdup(int *arr, int len)
{
	int	*ptr;
	int	i;

	ptr = (int *)malloc(len * sizeof(int));
	i = -1;
	while (++i < len)
		ptr[i] = arr[i];
	return (ptr);
}
