/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:21:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/12 11:03:38 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	*ft_intdup(int *arr, int len);
static void	ft_get_median(int flag, int *arr, t_ps *push_swap);

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
	ft_get_median(flag, arr, push_swap);
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

static void	ft_get_median(int flag, int *arr, t_ps *push_swap)
{
	if (push_swap->len % 2 != 0)
		push_swap->mid = arr[push_swap->len / 2];
	else
		push_swap->mid = (arr[push_swap->len / 2] + \
				arr[push_swap->len / 2 - 1]) / 2;
	free(arr);
	if (!flag)
	{
		free(push_swap->args);
		exit(EXIT_SUCCESS);
	}
}
